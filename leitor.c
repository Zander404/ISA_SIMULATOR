#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"
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

int main(){
    FILE *arq;
    char *pl;         //indices das instrucoes
    char str[50];
    int count=0;        //Variavel de controle da leitura
    int indice=0;
    char tipo=0;
    unsigned char MEMORIA[154];                 //8 bits

    arq = fopen("instrucoes.txt", "r");
    if (NULL == arq) {
        printf("Arquivo instrucoes.txt nao encontrado \n");
    }else{
        while (fgets(str, 50, arq) != NULL) {
            pl= strtok(str, ";"); //Peguei o indice de posicao da memoria
//            printf("\n%s",pl);

            while(count<3){

                if(count==0){
                    indice = (int) strtol(pl,NULL,16); //comeco da leitura
                    printf("\n\n%i", indice);

//                    printf("%i", count);
                }else if(count == 1){
                    pl = strtok(NULL,";"); //Peguei o tipo de dado i ou d
                    tipo = *pl;
                    printf("\t\t\t\t\t\t TIPO DE DADO: %c\n", tipo);


                    pl = strtok(NULL,";"); //Peguei as 2 instrucoes
                    printf("\t\t\t\t\t\t Print das 2 instrucoes: %s\n", pl);


                    pl = strtok(pl,"/"); //peguei a instrucao da Direita
                    printf("\t\t\t\t\t\t 1 intrucao: %s\n", pl);


                    pl = strtok(NULL,"/"); //peguei a instrucao da esquerda
                    printf("\t\t\t\t\t\t 2 instrucao: %s\n", pl);



                }
                count++;
            }
            count=0;


        }
    }

}