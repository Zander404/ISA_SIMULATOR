//
// Created by xandy on 31/03/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu.h"

unsigned int mbr, mar = 0, imm, pc = 0, reg[8];
unsigned char ir, ro0, ro1, e, l, g, memoria[154];

unsigned char *pt;

void guardarMemoria(unsigned int mem ,unsigned int aux){
    memoria[mem++] = (aux & 0xff000000) >> 24;
    memoria[mem++] = (aux & 0x00ff0000) >> 16;
    memoria[mem++] = (aux & 0x0000ff00) >> 8;
    memoria[mem] = (aux & 0x0000ff);
}

void colocarInstru(int mem){
    char mine[8], mine2[8]; // aux recebe rg0
    unsigned char rg0;
    char *ponteiro;
    unsigned int count = 0, imediatoMem, palavra, palavra2;

    ponteiro = strtok(pt," /");

    while(ponteiro){
        if(strcmp(ponteiro, "add") == 0 || strcmp(ponteiro, "hlt") == 0 ||strcmp(ponteiro, "nop") == 0 ||strcmp(ponteiro, "sub") == 0 ||
           strcmp(ponteiro, "mul") == 0 ||strcmp(ponteiro, "div") == 0 ||strcmp(ponteiro, "cmp") == 0 ||strcmp(ponteiro, "xchg") == 0  ||
           strcmp(ponteiro, "and") == 0 ||strcmp(ponteiro, "or") == 0 |strcmp(ponteiro, "xor") == 0 ||strcmp(ponteiro, "not") == 0 ||
           strcmp(ponteiro, "ldrb") == 0 ){
            strcpy(mine,ponteiro);
            printf("\nMINE: %s\n",mine);

            ponteiro = strtok(NULL," /");
            while (ponteiro){
                if(strcmp(ponteiro, "add") == 0 || strcmp(ponteiro, "hlt") == 0 ||strcmp(ponteiro, "nop") == 0 ||strcmp(ponteiro, "sub") == 0 ||
                   strcmp(ponteiro, "mul") == 0 ||strcmp(ponteiro, "div") == 0 ||strcmp(ponteiro, "cmp") == 0 ||strcmp(ponteiro, "xchg") == 0  ||
                   strcmp(ponteiro, "and") == 0 ||strcmp(ponteiro, "or") == 0 |strcmp(ponteiro, "xor") == 0 ||strcmp(ponteiro, "not") == 0 ||
                   strcmp(ponteiro, "ldrb") == 0 ){
                    strcpy(mine2,ponteiro);
                    printf("\nMINE2: %s\n",mine2);
                } else{
                    if(count == 0){
                        strcpy(mine2,ponteiro);
                        printf("\nMINE2: %s\n",mine2);
                    }
                    if(count == 1){
                        imediatoMem = (int)strtol(ponteiro,NULL,16);
                        printf("\nImediato: %x\n",imediatoMem);
                    }
                    ponteiro = strtok(NULL," /");
                    count++;
                }
            }
        } else{
            if(count == 0){
                strcpy(mine,ponteiro);
                printf("\nMINE: %s\n",mine);
            }
            if (count== 1){
                rg0 = (int)strtol(ponteiro,NULL,16);
                printf("\nRG0: %x\n",rg0);
            }
            if(count == 2){
                strcpy(mine2,ponteiro);
                printf("\nMINE2: %s\n",mine2);
            }
            if(count == 3){
                imediatoMem = (int)strtol(ponteiro,NULL,16);
                printf("\nImediato: %x\n",imediatoMem);
            }
            ponteiro = strtok(NULL," /");
            count++;
        }
    }

    if(strcmp(mine,"nop")== 0) {
        palavra = nop;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"add")== 0){
        palavra = add;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"sub")== 0) {
        palavra = sub;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"mul")== 0) {
        palavra = mul;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"div")== 0) {
        palavra = div;
        palavra = (palavra << 11)| 00;
    } else if(strcmp(mine,"cmp")== 0) {
        palavra = cmp;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"xchg")== 0) {
        palavra = xchg;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"ldrb")== 0) {
        palavra = ldrb;
        palavra = (palavra << 11);
    }
    else if(strcmp(mine,"and")== 0) {
        palavra = and;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"or")== 0) {
        palavra = or;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"xor")== 0) {
        palavra = xor;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"not")== 0) {
        palavra = not;
        palavra = (palavra << 11);
    } else if(strcmp(mine,"je")== 0) {
        palavra = je;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"jne")== 0) {
        palavra = jne;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"jl")== 0) {
        palavra = jl;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"jle")== 0) {
        palavra = jle;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"jg")== 0) {
        palavra = jg;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"jge")== 0) {
        palavra = jge;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"jmp")== 0) {
        palavra = jmp;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"lda")== 0){
        palavra = lda;
        palavra = (palavra << 11)| rg0;
    }else if(strcmp(mine,"ldb")== 0){
        palavra = ldb;
        palavra = (palavra << 11)| rg0;
    }
    else if(strcmp(mine,"sta")== 0){
        palavra = sta;
        palavra = (palavra << 11)| rg0;

    }  else if(strcmp(mine,"stb")== 0){
        palavra = stb;
        palavra = (palavra << 11)| rg0;

    } else if(strcmp(mine,"movial")== 0) {
        palavra = movial;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"moviah")== 0) {
        palavra = moviah;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"addia")== 0) {
        palavra = addia;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"subia")== 0) {
        palavra = subia;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"mulia")== 0) {
        palavra = mulia;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"divia")== 0) {
        palavra = divia;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"lsh")== 0) {
        palavra = lsh;
        palavra = (palavra << 11)| rg0;
    } else if(strcmp(mine,"rsh")== 0) {
        palavra = rsh;
        palavra = (palavra << 11)| rg0;
    } else {
        palavra = hlt;
        palavra = (palavra << 11);
    }

    if(strcmp(mine2,"nop")== 0) {
        palavra2 = nop;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"add")== 0){
        palavra2 = add;

        palavra2 = palavra2 << 11;

    } else if(strcmp(mine2,"sub")== 0) {
        palavra2 = sub;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"mul")== 0) {
        palavra2 = mul;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"div")== 0) {
        palavra2 = div;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"cmp")== 0) {
        palavra2 = cmp;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"xchg")== 0) {
        palavra2 = xchg;
        palavra2 = palavra2 << 11;
        printf("\n\nPALAVRA : %x\n\n",palavra2);
    } else if(strcmp(mine2,"ldrb")== 0) {
        palavra2 = ldrb;

        palavra2 = palavra2 << 11;
    }
    else if(strcmp(mine2,"and")== 0) {
        palavra2 = and;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"or")== 0) {
        palavra2 = or;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"xor")== 0) {
        palavra2 = xor;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"not")== 0) {
        palavra2 = not;

        palavra2 = palavra2 << 11;
    } else if(strcmp(mine2,"je")== 0) {
        palavra2 = je;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"jne")== 0) {
        palavra2 = jne;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"jl")== 0) {
        palavra2 = jl;


        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"jle")== 0) {
        palavra2 = jle;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"jg")== 0) {
        palavra2 = jg;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"jge")== 0) {
        palavra2 = jge;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"jmp")== 0) {
        palavra2 = jmp;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"lda")== 0){
        palavra2 = lda;

        palavra2 = (palavra2 << 11)| imediatoMem;

    }else if(strcmp(mine2,"ldb")== 0){
        palavra2 = ldb;
        palavra2 = (palavra2 << 11)| imediatoMem;
    }
    else if(strcmp(mine2,"sta")== 0){
        palavra2 = sta;

        palavra2 = (palavra2 << 11)| imediatoMem;

    }  else if(strcmp(mine2,"stb")== 0){
        palavra2 = stb;

        palavra2 = (palavra2 << 11)| imediatoMem;

    } else if(strcmp(mine2,"movial")== 0) {
        palavra2 = movial;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"moviah")== 0) {
        palavra2 = moviah;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"addia")== 0) {
        palavra2 = addia;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"subia")== 0) {
        palavra2 = subia;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"mulia")== 0) {
        palavra2 = mulia;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"divia")== 0) {
        palavra2 = divia;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"lsh")== 0) {
        palavra2 = lsh;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else if(strcmp(mine2,"rsh")== 0) {
        palavra2 = rsh;

        palavra2 = (palavra2 << 11)| imediatoMem;
    } else {
        palavra2 = 0x0000;
    }
    printf("\n\npalavra2: %x\n\n",palavra2);
    palavra = palavra << 16 | palavra2;
    printf("%x",palavra);
    guardarMemoria(mem,palavra);
}

void lerArquivo(){

    unsigned int mem, valor;
    FILE *arq;
    unsigned char tipo, linha[99];
    unsigned int count = 0;
    arq = fopen("instrucoes.txt", "r");

    while (fgets(linha, 99, arq) != NULL){
        pt = strtok(linha, "; ");
        mem = (int)strtol(pt,NULL,16);
        while(pt){
            if(count == 1){
                tipo = *pt;
            }else if(count == 2){
                if(tipo == 0x64){
                    valor = (int)strtol(pt,NULL,16);
                    printf("\nVALOR: %x",valor);
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
}

int main (void) {

    lerArquivo();

    int teste = 0;
    int aux = 0;

    while (aux != 3){
        printf(" Aperte 1 para executar, 2 para mostrar a memoria, 3 para finalizar");
        scanf("%d", &aux);

        if (aux == 1) {
//            ciclo();
            printf("MBR: %x MAR: %x  IMM: %x PC: %x \n",mbr, mar, imm,pc);
            printf("REG1: %x REG2: %x REG3: %x  REG4: %x \n", reg[0], reg[1], reg[2], reg[3]);
            printf("REG5: %x  REG6: %x  REG7: %x  REG8: %x \n", reg[4], reg[5], reg[6], reg[7]);
            printf("IR: %x  RO0: %x  RO1: %x  E: %x  L: %x G: %x \n", ir, ro0, ro1, e, l, g);
            if (ir == 0) {
                while(teste < 154){
                    printf("Posicao %d : %x \n", teste, memoria[teste++]);
                };
                break;
            }
        } else if (aux == 2) {
            while(teste < 154){
                printf("Posicao %d : %x \n", teste, memoria[teste]);
                teste++;
            };
        } else {
            break;
        }
    };

    printf("MBR: %x MAR: %x  IMM: %x PC: %x \n",mbr, mar, imm,pc);
    printf("REG1: %x REG2: %x REG3: %x  REG4: %x \n", reg[0], reg[1], reg[2], reg[3]);
    printf("REG5: %x  REG6: %x  REG7: %x  REG8: %x \n", reg[4], reg[5], reg[6], reg[7]);
    printf("IR: %x  RO0: %x  RO1: %x  E: %x  L: %x G: %x \n", ir, ro0, ro1, e, l, g);

    return 0;
}