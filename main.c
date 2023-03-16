#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"

unsigned char MEMORIA[154];

unsigned int MBR;

unsigned short int MAR,IBR,IR,IMM,PC;

unsigned char E , L ,G,LR;

unsigned short int A,B,T;


int criar_palavra(char instrucao[], unsigned int reg1, unsigned int reg2, unsigned int menOuImm, int inicio)
{
    int palavra;
    if(strcmp(instrucao,"ld")== 0){
        palavra = ld;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"st")== 0){
        palavra = st;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"add")== 0){
        palavra = add;
        palavra = (palavra << 3) |reg1;
        palavra = (palavra << 3) | reg2;
        palavra =  palavra << 18;
    }else if(strcmp(instrucao,"sub")== 0) {
        palavra = sub;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 3) | reg2;
        palavra = palavra << 18;
    }else if(strcmp(instrucao,"mul")== 0) {
        palavra = mul;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 3) | reg2;
        palavra = palavra << 18;
    }else if(strcmp(instrucao,"div")== 0) {
        palavra = div;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 3) | reg2;
        palavra = palavra << 18;
    }else if(strcmp(instrucao,"cmp")== 0) {
        palavra = cmp;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 3) | reg2;
        palavra = palavra << 18;
    }else if(strcmp(instrucao,"movr")== 0) {
        palavra = movr;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 3) | reg2;
        palavra = palavra << 18;
    }
    else if(strcmp(instrucao,"and")== 0) {
        palavra = and;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 3) | reg2;
        palavra = palavra << 18;
    }else if(strcmp(instrucao,"or")== 0) {
        palavra = or;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 3) | reg2;
        palavra = palavra << 18;
    }else if(strcmp(instrucao,"xor")== 0) {
        palavra = xor;
        palavra = (palavra << 3) | ro0;
        palavra = (palavra << 3) | palavra;
        palavra = palavra << 18;
    }else if(strcmp(instrucao,"not")== 0) {
        palavra = not;
        palavra = (palavra << 3)|ro0;
        palavra = palavra << 21;
    }else if(strcmp(instrucao,"je")== 0) {
        palavra = je;
        palavra = (palavra << 24) | menOuImm;
    }else if(strcmp(instrucao,"jne")== 0) {
        palavra = jne;
        palavra = (palavra << 24)| menOuImm;
    }else if(strcmp(instrucao,"jl")== 0) {
        palavra = jl;
        palavra = (palavra << 24)| menOuImm;
    }else if(strcmp(instrucao,"jg")== 0) {
        palavra = jg;
        palavra = (palavra << 24)| menOuImm;
    }else if(strcmp(instrucao,"jle")== 0) {
        palavra = jle;
        palavra = (palavra << 24)| menOuImm;
    }else if(strcmp(instrucao,"jge")== 0) {
        palavra = jge;
        palavra = (palavra << 24)| menOuImm;
    }else if(strcmp(instrucao,"jmp")== 0) {
        palavra = jmp;
        palavra = (palavra << 24)| menOuImm;
    }else if(strcmp(instrucao,"movial")== 0) {
        palavra = movial;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"addi")== 0) {
        palavra = addia;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"subi")== 0) {
        palavra = subia;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"muli")== 0) {
        palavra = mulia;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"divi")== 0) {
        palavra = divia;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"lsh")== 0) {
        palavra = lsh;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else if(strcmp(instrucao,"rsh")== 0) {
        palavra = rsh;
        palavra = (palavra << 3) | reg1;
        palavra = (palavra << 21) | menOuImm;
    }else{
        palavra  = 0;
    }
    MEMORIA[inicio++] = palavra >> 24;
    MEMORIA[inicio++] = (palavra & 0x00ff0000) >> 16;
    MEMORIA[inicio++] = (palavra & 0x0000ff00) >> 16;
    MEMORIA[inicio] = palavra & 0x000000ff;

    return palavra;
}

void lerTexto()
{
    FILE *arq;
    char *pl;
    char str[50];
    char instrucao[10];
    int count = 0;
    int inicio;
    char tipo;
    unsigned int palavra;
    unsigned int reg1;
    unsigned int reg2;
    unsigned int menOuImm;
    arq = fopen("instrucoes.txt", "r");
    if (NULL == arq) {
        printf("Arquivo instrucoes.txt nao encontrado \n");
    } else{
        while (fgets(str, 50, arq) != NULL) {
            pl = strtok(str, ";");
            while(count < 3)
            {
                if(count == 0)
                {
                    inicio = (int) strtol(pl,NULL,16); //comeco da leitura
                } else if(count == 1)
                {
                    tipo = *pl;
                } else{
                    if(tipo == 'i')
                    {
                        pl = strtok(pl,", ");
                        if(strcmp(pl, "add") == 0 || strcmp(pl, "sub") == 0 ||
                           strcmp(pl, "mul") == 0 || strcmp(pl, "div") == 0 ||
                           strcmp(pl, "cmp") == 0 || strcmp(pl, "movr") == 0 ||
                           strcmp(pl, "and") == 0 || strcmp(pl, "or") == 0 ||
                           strcmp(pl, "xor") == 0)
                        {
                            strcpy(instrucao,pl);  //Pega a instrucao do texto
                            pl = strtok(NULL,"r, ");
                            reg1 = (int) strtol(pl, NULL, 16); //armazena no ro1
                            pl = strtok(NULL,"r, ");
                            reg2 = (int) strtol(pl, NULL, 16); //armazena no ro2

                            criar_palavra(instrucao,reg1,reg2,0,inicio);
                        } else if(strcmp(pl, "not") == 0)
                        {
                            strcpy(instrucao,pl);
                            pl = strtok(NULL,"r, ");
                            reg1 = (int) strtol(pl, NULL, 16);
                            criar_palavra(instrucao,reg1,0x0,0x0,inicio);
                        } else if(strcmp(pl, "je") == 0 || strcmp(pl, "jne") == 0 ||
                                  strcmp(pl, "jl") == 0 || strcmp(pl, "jle") == 0 ||
                                  strcmp(pl, "jg") == 0 || strcmp(pl, "jge") == 0 ||
                                  strcmp(pl, "jmp") == 0)
                        {
                            strcpy(instrucao,pl);
                            pl = strtok(NULL,", ");
                            menOuImm = (int) strtol(pl, NULL, 16);
                            palavra = criar_palavra(instrucao,0x00,0x00,menOuImm,inicio);
                        } else if(strcmp(pl, "ld") == 0 || strcmp(pl,"st") == 0)
                        {
                            strcpy(instrucao,pl);
                            pl = strtok(NULL, "r, ");
                            reg1 = (int) strtol(pl,NULL,16);
                            pl = strtok(NULL, ", ");
                            menOuImm = (int) strtol(pl, NULL, 16);
                            palavra = criar_palavra(instrucao,reg1,0x00,menOuImm,inicio);
                        }else if(strcmp(pl, "addi") == 0 || strcmp(pl, "subi") == 0 ||
                                 strcmp(pl, "muli") == 0 || strcmp(pl, "divi") == 0 ||
                                 strcmp(pl, "movi") == 0 ||strcmp(pl, "lsh") == 0 ||
                                 strcmp(pl, "rsh") == 0)
                        {
                            strcpy(instrucao, pl);
                            pl = strtok(NULL,"r, ");
                            reg1 = (int) strtol(pl, NULL, 16);
                            pl = strtok(NULL,"r, ");
                            menOuImm = (int) strtol(pl,NULL,16);
                            palavra = criar_palavra(instrucao,reg1,0x00,menOuImm,inicio);
                        }else if(strcmp(pl, "nop") == 0 || strcmp(pl, "hlt") == 0)
                        {
                            strcpy(instrucao,pl);
                            palavra = criar_palavra(instrucao,0x00,0x00,0x00,inicio);
                        }
                    } else{
                        palavra = (int) strtol(pl,NULL,16);
                        MEMORIA[inicio++] = palavra >> 24;
                        MEMORIA[inicio++] = (palavra & 0x00ff0000) >> 16;
                        MEMORIA[inicio++] = (palavra & 0x0000ff00) >> 16;
                        MEMORIA[inicio] = palavra & 0x000000ff;
                    }
                }
                pl = strtok(NULL,";");
                count++;
            }
            count = 0;
        }
    }
    fclose(arq);
}




void teste(){

    printf("hlt: %i\n",hlt);
    printf("nop: %i\n",nop);
    printf("add: %i\n",add);
    printf("sub: %i\n",sub);
    printf("mul: %i\n",mul);
    printf("div: %i\n",div);

    printf("cmp: %i\n",cmp);
    printf("xchg: %i\n",xchg);
    printf("and: %i\n",and);
    printf("or: %i\n",or);
    printf("xor: %i\n",xor);
    printf("not: %i\n",not);

    printf("je: %i\n",je);
    printf("jne: %i\n",jne);
    printf("jl: %i\n",jl);
    printf("jle: %i\n",jle);
    printf("jg: %i\n",jg);
    printf("jge: %i\n",jge);

    printf("jmp: %i\n",jmp);
    printf("lda: %i\n",lda);
    printf("ldb: %i\n",ldb);
    printf("sta: %i\n",sta);
    printf("stb: %i\n",stb);
    printf("ldrb: %i\n",ldrb);

    printf("movial: %i\n",movial);
    printf("moviah: %i\n",moviah);

    printf("addia: %i\n",addia);
    printf("subia: %i\n",subia);
    printf("mulia: %i\n",mulia);
    printf("divia: %i\n",divia);

    printf("lsh: %i\n",lsh);
    printf("rsh: %i\n",rsh);
};


void busca(){
    MAR = PC;
    MBR = MEMORIA[MAR++];
    for(int i = 0; i<4;i++){
        MBR = (MBR << 8 ) | MEMORIA[MAR++];
    };

}

void decodifica(){
    IR = MBR >> 27;
    IBR =  MBR >> 16;
}

void executa(){

}

int main() {

    //lerTexto();
    PC = 0;
    IR=1;
    while (IR!=hlt){
        busca();
        decodifica();
        executa();

        printf("Registrador A tem o valor %x\n", A);
        printf("Registrador B tem o valor %x\n", B);

        printf("---------------Memorias-----------------\n");
        for (int i = 0; i < 154 ; i++) {
            printf("%d=[%x]  ",i,MEMORIA[i]);
            if(i%10 == 0 && i!=0){
                printf("\n");
            }
        }
        printf("\nPressione enter para executar o proximo ciclo de instrucao\n");
        getchar();
    }


    return 0;
}
