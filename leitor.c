//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include "cpu.h"
//
//
//unsigned short int fazer_palavra_16Bits (char instrucao[], unsigned int menOuImm) {
//    int palavra;
//    if(strcmp(instrucao,"ld")== 0){
//        palavra = ld;
//        palavra = (palavra << 4) | menOuImm;
//        palavra = (palavra << 11) | menOuImm;
//    }else if(strcmp(instrucao,"st")== 0){
//        palavra = st;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"add")== 0){
//        palavra = add;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra =  palavra << 18;
//    }else if(strcmp(instrucao,"sub")== 0) {
//        palavra = sub;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"mul")== 0) {
//        palavra = mul;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"div")== 0) {
//        palavra = div;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"cmp")== 0) {
//        palavra = cmp;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"movr")== 0) {
//        palavra = movr;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra = palavra << 18;
//    }
//    else if(strcmp(instrucao,"and")== 0) {
//        palavra = and;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"or")== 0) {
//        palavra = or;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 4) | B;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"xor")== 0) {
//        palavra = xor;
//        palavra = (palavra << 4) | ro0;
//        palavra = (palavra << 4) | palavra;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"not")== 0) {
//        palavra = not;
//        palavra = (palavra << 4)|ro0;
//        palavra = palavra << 21;
//    }else if(strcmp(instrucao,"je")== 0) {
//        palavra = je;
//        palavra = (palavra << 24) | menOuImm;
//    }else if(strcmp(instrucao,"jne")== 0) {
//        palavra = jne;
//        palavra = (palavra << 24)| menOuImm;
//    }else if(strcmp(instrucao,"jl")== 0) {
//        palavra = jl;
//        palavra = (palavra << 24)| menOuImm;
//    }else if(strcmp(instrucao,"jg")== 0) {
//        palavra = jg;
//        palavra = (palavra << 24)| menOuImm;
//    }else if(strcmp(instrucao,"jle")== 0) {
//        palavra = jle;
//        palavra = (palavra << 24)| menOuImm;
//    }else if(strcmp(instrucao,"jge")== 0) {
//        palavra = jge;
//        palavra = (palavra << 24)| menOuImm;
//    }else if(strcmp(instrucao,"jmp")== 0) {
//        palavra = jmp;
//        palavra = (palavra << 24)| menOuImm;
//    }else if(strcmp(instrucao,"movial")== 0) {
//        palavra = movial;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"addi")== 0) {
//        palavra = addia;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"subi")== 0) {
//        palavra = subia;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"muli")== 0) {
//        palavra = mulia;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"divi")== 0) {
//        palavra = divia;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"lsh")== 0) {
//        palavra = lsh;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"rsh")== 0) {
//        palavra = rsh;
//        palavra = (palavra << 4) | A;
//        palavra = (palavra << 21) | menOuImm;
//    }else{
//        palavra  = 0;
//    }
//
//}
//
//
//int criar_palavra(char instrucao[], unsigned short int A, unsigned short int B, unsigned int menOuImm, int inicio,unsigned  char LR)
//{
//    unsigned short int METADE_DA_MINHA_ALMA_FOI_PERDIDA_NA_ESQUERDA_VIVA_O_COMUNISMO, METADE_DA_MINHA_ALMA_FOI_PERDIDA_NA_DIREITA_VIVA_O_BOLSONARO_22;
//
//    METADE_DA_MINHA_ALMA_FOI_PERDIDA_NA_ESQUERDA_VIVA_O_COMUNISMO = fazer_palavra_16Bits(instrucao,menOuImm);
//
//    METADE_DA_MINHA_ALMA_FOI_PERDIDA_NA_DIREITA_VIVA_O_BOLSONARO_22 = fazer_palavra_16Bits(instrucao,menOuImm);
//
//
//    MEMORIA[inicio++] = palavra >> 24;
//    MEMORIA[inicio++] = (palavra & 0x00ff0000) >> 16;
//    MEMORIA[inicio++] = (palavra & 0x0000ff00) >> 16;
//    MEMORIA[inicio] = palavra & 0x000000ff;
//
//    return palavra;
//}
//
//int main() {
//    FILE *arq;
//    char *pl;
//    char str[50];
//    char instrucao[10];
//    int count = 0;
//    int inicio;
//    char tipo;
//    unsigned int palavra;
//    unsigned int A;
//    unsigned int B;
//    unsigned int menOuImm;
//    unsigned  char LR = 0;
//    arq = fopen("instrucoes.txt", "r");
//    if (NULL == arq) {
//        printf("Arquivo instrucoes.txt nao encontrado \n");
//    } else{
//        while (fgets(str, 50, arq) != NULL) {
//            pl= strtok(str, ";");
//            while(count < 3)
//            {
//                if(count == 0)
//                {
//                    inicio = (int) strtol(pl,NULL,16); //comeco da leitura
//                } else if(count == 1)
//                {
//                    tipo = *pl;
//                } else{
//                    if(tipo == 'i')
//                    {
//                        pl = strtok(pl,", ");
//                        if(strcmp(pl, "add") == 0 || strcmp(pl, "sub") == 0 ||
//                           strcmp(pl, "mul") == 0 || strcmp(pl, "div") == 0 ||
//                           strcmp(pl, "cmp") == 0 || strcmp(pl, "xchg") == 0 ||
//                           strcmp(pl, "and") == 0 || strcmp(pl, "or") == 0 ||
//                           strcmp(pl, "xor") == 0 || strcmp(pl, "ldrb") == 0 )
//                        {
//                            strcpy(instrucao,pl);  //Pega a instrucao do texto
//                            pl = strtok(NULL,"r, ");
//                            A = (int) strtol(pl, NULL, 16); //armazena no ro1
//                            pl = strtok(NULL,"r, ");
//                            B = (int) strtol(pl, NULL, 16); //armazena no ro2
//
//                            criar_palavra(instrucao,A,B,0,inicio,LR);
//                        } else if(strcmp(pl, "not") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            pl = strtok(NULL,"r, ");
//                            A = (int) strtol(pl, NULL, 16);
//                            criar_palavra(instrucao,A,0x0,0x0,inicio);
//                        } else if(strcmp(pl, "je") == 0 || strcmp(pl, "jne") == 0 ||
//                                  strcmp(pl, "jl") == 0 || strcmp(pl, "jle") == 0 ||
//                                  strcmp(pl, "jg") == 0 || strcmp(pl, "jge") == 0 ||
//                                  strcmp(pl, "jmp") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            pl = strtok(NULL,", ");
//                            menOuImm = (int) strtol(pl, NULL, 16);
//                            palavra = criar_palavra(instrucao,0x00,0x00,menOuImm,inicio,LR);
//                        } else if(strcmp(pl, "ld") == 0 || strcmp(pl,"st") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            pl = strtok(NULL, "r, ");
//                            A = (int) strtol(pl,NULL,16);
//                            pl = strtok(NULL, ", ");
//                            menOuImm = (int) strtol(pl, NULL, 16);
//                            palavra = criar_palavra(instrucao,A,0x00,menOuImm,inicio,LR);
//                        }else if(strcmp(pl, "addi") == 0 || strcmp(pl, "subi") == 0 ||
//                                 strcmp(pl, "muli") == 0 || strcmp(pl, "divi") == 0 ||
//                                 strcmp(pl, "movi") == 0 ||strcmp(pl, "lsh") == 0 ||
//                                 strcmp(pl, "rsh") == 0)
//                        {
//                            strcpy(instrucao, pl);
//                            pl = strtok(NULL,"r, ");
//                            A = (int) strtol(pl, NULL, 16);
//                            pl = strtok(NULL,"r, ");
//                            menOuImm = (int) strtol(pl,NULL,16);
//                            palavra = criar_palavra(instrucao,A,0x00,menOuImm,inicio LR);
//                        }else if(strcmp(pl, "nop") == 0 || strcmp(pl, "hlt") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            palavra = criar_palavra(instrucao,0x00,0x00,0x00,inicio,LR);
//                        }
//                    } else{
//                        palavra = (int) strtol(pl,NULL,16);
//                        MEMORIA[inicio++] = palavra >> 24;
//                        MEMORIA[inicio++] = (palavra & 0x00ff0000) >> 16;
//                        MEMORIA[inicio++] = (palavra & 0x0000ff00) >> 16;
//                        MEMORIA[inicio] = palavra & 0x000000ff;
//                    }
//                }
//                pl = strtok(NULL,";");
//                count++;
//            }
//            count = 0;
//        }
//    }
//    fclose(arq);
//}

void colocarInstru(int mem){
    unsigned char *ponteiro, rg0, mine[8]; // aux recebe rg0
    unsigned int count = 0, imediatoMem, palavra;

    ponteiro = strtok(pt," ,");
    while(ponteiro){
        if(count == 0){
            strcpy(mine,ponteiro);
        }
        if (count== 1){
            rg0 = (int)strtol(ponteiro,NULL,16);
        }
        if(count == 2){
            imediatoMem = (int)strtol(ponteiro,NULL,16);
        }
        ponteiro = strtok(NULL," ,r");
        count++;
    }
    if(strcmp(mine,"nop")== 0) {
        palavra = 1;
        palavra = palavra << 24;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"add")== 0){
        palavra = 2;
        palavra = (palavra << 3) |rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra =  palavra << 18;
        guardarMemoria(mem,palavra);
    } else if(strcmp(mine,"sub")== 0) {
        palavra = 3;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"mul")== 0) {
        palavra = 4;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"div")== 0) {
        palavra = 5;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"cmp")== 0) {
        palavra = 6;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"movr")== 0) {
        palavra = 7;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"and")== 0) {
        palavra = 8;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"or")== 0) {
        palavra = 9;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"xor")== 0) {
        palavra = 10;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 3) | imediatoMem;
        palavra = palavra << 18;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"not")== 0) {
        palavra = 11;
        palavra = ((palavra << 3)|rg0)<<21;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"je")== 0) {
        palavra = 12;
        palavra = (palavra << 24)| imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"jne")== 0) {
        palavra = 13;
        palavra = (palavra << 24)| imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"jl")== 0) {
        palavra = 14;
        palavra = (palavra << 24)| imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"jle")== 0) {
        palavra = 15;
        palavra = (palavra << 24)| imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"jg")== 0) {
        palavra = 16;
        palavra = (palavra << 24)| imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"jge")== 0) {
        palavra = 17;
        palavra = (palavra << 24)| imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"jmp")== 0) {
        palavra = 18;
        palavra = (palavra << 24)| imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"ld")== 0){
        palavra = 19;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21)| imediatoMem;
        guardarMemoria(mem,palavra);
    } else if(strcmp(mine,"st")== 0){
        palavra = 20;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21)| imediatoMem;
        guardarMemoria(mem,palavra);
    } else if(strcmp(mine,"movi")== 0) {
        palavra = 21;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21) | imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"addi")== 0) {
        palavra = 22;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21) | imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"subi")== 0) {
        palavra = 23;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21) | imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"muli")== 0) {
        palavra = 24;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21) | imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"divi")== 0) {
        palavra = 25;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21) | imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"lsh")== 0) {
        palavra = 26;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21) | imediatoMem;
        guardarMemoria(mem, palavra);
    } else if(strcmp(mine,"rsh")== 0) {
        palavra = 27;
        palavra = (palavra << 3) | rg0;
        palavra = (palavra << 21) | imediatoMem;
        guardarMemoria(mem, palavra);
    } else{
        palavra  = 0;
        guardarMemoria(mem,palavra);
    }
}


void lerArquivo(){

    unsigned int mem, valor;
    FILE *arq;
    unsigned char tipo, linha[99];
    unsigned int count = 0;
    arq = fopen("programa.txt", "r");

    while (fgets(linha, 99, arq) != NULL){
        pt = strtok(linha, "; ");
        mem = (int)strtol(pt,NULL,16);
        while(pt){
            if(count == 1){
                tipo = *pt;
            }else if(count == 2){
                if(tipo == 0x64){
                    valor = (int)strtol(pt,NULL,16);
                    memoria[mem++] = (valor & 0xff000000) >> 24;
                    memoria[mem++] = (valor & 0x00ff0000) >> 16;
                    memoria[mem++] = (valor & 0x0000ff00) >> 8;
                    memoria[mem]   = (valor & 0x000000ff);
                }else{
                    colocarInstru(mem);
                }
            }

            pt = strtok(NULL ,";");
            count++;
        }
        count = 0;
    }

    if (NULL == arq)
        printf("Erro ao tentar abrir programa.txt \n");
    fclose(arq);

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"

void getInstrucao(unsigned int indice, unsigned char instrucao, unsigned char flagLR){
//    printf("indice:%i \n instrucao:%s \n flagLR: %i", indice,instrucao,flagLR);

}

int main(){
    FILE *arq;
    unsigned char *pl, *charc;         //indices das instrucoes
    char str[50];

    unsigned int indice=0;
    unsigned char tipo=0;                       //8 bits
    unsigned short int instrucao_direita;        //16 bits
    unsigned char instrucao_esquerda[8];      //16 bits
    unsigned char flagLR = 0;                       //8 bits / mas apenas 2 bits
    unsigned char MEMORIA[154];                 //8 bits
    unsigned short int temp =0;                 //PC

    int count=0;        //Variavel de controle da leitura



    arq = fopen("instrucoes.txt", "r");
    if (NULL == arq) {
        printf("Arquivo instrucoes.txt nao encontrado \n");
    }else{
        while (fgets(str, 50, arq) != NULL) {
            pl = strtok(str, ";"); //Peguei o indice de posicao da memoria
            charc = strtol()

            while(count<3){

                if(count==0){
                    indice = (int) strtol(pl,NULL,16); //comeco da leitura


//
                }else if(count == 1){
                    pl = strtok(NULL,";"); //Peguei o tipo de dado i ou d
                    tipo = *pl;
                    printf("\t\t\t\t\t\t TIPO DE DADO: %c\n", tipo);
                    if(tipo == 0x69){
                        pl = strtok(NULL,";"); //Peguei as 2 instrucoes
                        printf("\t\t\t\t\t\t Print das 2 instrucoes: %s\n", pl);


                        pl = strtok(pl,"/"); //peguei a instrucao da Direita
                        printf("\t\t\t\t\t\t 1 intrucao: %s\n", pl);
//                        instrucao_esquerda = *pl;
                        getInstrucao(indice,pl);


//                        MEMORIA[temp++] = 0;
//                        MEMORIA[temp] = 0;


                        pl = strtok(NULL,"/"); //peguei a instrucao da esquerda
                        instrucao_direita = *pl;
                        printf("\t\t\t\t\t\t 2 instrucao: %s\n", pl);
//                        instrucao_esquerda = *pl;
//                     Fazer um conjunto de ifs fudidos
//                     Ou fazer uma funcao com uma flag de controle
//                     getInstrucao(indice,pl,flagLR);
                        getInstrucao(indice,pl);


                    }else if (tipo == 0x64){
                        pl = strtok(NULL,";"); //Peguei as 2 instrucoes
                        printf("\t\t\t\t\t\t Print do dado: %s\n", pl);
                    }else{
                        printf("\n\t\t\t\t\tDado invalido\n\nEncerrando programa ...\n\n\n");
                        return 0;
                    }




                    pl = strtok(NULL,";"); //Peguei as 2 instrucoes
                    printf("\t\t\t\t\t\t Print das 2 instrucoes: %s\n", pl);


                    pl = strtok(pl,"/"); //peguei a instrucao da Direita
                    printf("\t\t\t\t\t\t 1 intrucao: %s\n", pl);
//                    Fazer um conjunto de ifs fudidos
//                    Ou fazer uma funcao com uam flag de controle
;                     getInstrucao(indice,*pl,flagLR);

                    pl = strtok(NULL,"/"); //peguei a instrucao da esquerda
                    printf("\t\t\t\t\t\t 2 instrucao: %s\n", pl);
//                     Fazer um conjunto de ifs fudidos
//                     Ou fazer uma funcao com uma flag de controle
//                     getInstrucao(indice,pl,flagLR);


                    MEMORIA[1] = *pl;




                }
                count++;
            }
            count=0;


        }
    }

}