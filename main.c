//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include "cpu.h"
//
//// Caso for necessario compilar na mão use os seguintes comandos
////Compilar      gcc -o main main.c
////Executar      ./main
//
//                                            // Tamanho em bits
//unsigned char MEMORIA[154];                 //  8 bits
//
//unsigned int MBR;                           // 32 bits
//
//unsigned short int MAR, IBR, IR, IMM, PC;   //16 bits
//
//unsigned char E, L, G, LR;                  //8 bits
//
//unsigned short int A, B, T;                 //16 bits
//
//int ciclo = 0;                              //Contador de Ciclo
//
//
//
//void busca() {
//    printf(" \t\t\t\tCICLO: %i",++ciclo);
//    MAR = PC;
//    MBR = MEMORIA[MAR++];
//
//    int i;
//    for (i = 0; i < 3; i++) {
//        MBR = (MBR << 8) | MEMORIA[MAR++];
//    };
//}
//
//
//void decodifica() {
//
//
//    if(LR == 0){
//        IBR = (MBR&maskibr);
//        IR = (MBR&maskir1)>>27;
//        printf("\n\t\t\t\t\t INSTRUCAO DO MAL: %x", IR);
//
//        printf("\n\nEstou na esquerda");
//
//
//        //Instrucao Tipo 1 & 2
//        if (IR >= hlt && IR <= stb) {
//            MAR = (MBR&maskmar1)>>16;
//        }
//
//        //Instrucao Tipo 3
//        else if (IR >= movial && IR <= rsh) {
//            IMM = (MBR&maskmar1)>>16;
//
//
//
//        }
//        printf("\n O valor da Flag e: %i", LR);
//        printf("\n\n\t\t O VALOR DE PC: %x",PC);
//        printf("\n O valor do IR e: %x",IR);
//        printf("\n O valor do IBR e: %x",IBR);
//        printf("\n O valor do MBR e: %x",MBR);
//        printf("\n O valor do MAR e: %x",MAR);
//        printf("\n");
//
//    }else{
//        IR = (IBR&maskir2)>>11;
//
//
//        //Instrucao Tipo 1 & 2
//        if (IR >= hlt && IR <= stb) {
//            MAR = IBR&0x007ff;
//        }
//
//        //Instrucao Tipo 3
//        else if (IR >= movial && IR <= rsh) {
//
//            IMM = (IBR&maskmar2);
//
//
//        }
//        printf("\n\nEstou na direita");
//        printf("\n O valor da Flag e: %i", LR);
//        printf("\n\n\t\t O VALOR DE PC: %x",PC);
//        printf("\n O valor do IR e: %x",IR);
//        printf("\n O valor do IBR e: %x",IBR);
//        printf("\n O valor do MBR e: %x",MBR);
//        printf("\n O valor do MAR e: %x",MAR);
//        printf("\n O valor d o IMM e: %x", IMM);
//        printf("\n");
//
//
//    }
//
//}
//
//
//void executa() {
//
//    printf("\t\t\t\t\t\t IR: %x", IR);
//
//    if (IR == hlt) {
////        condicao de parada
//    }
//    if (IR == nop) {
//        printf("A instrucao e a: %x", IR);
//        if(LR==1){
//            PC += 4;
//        }
//
//        LR = !LR;
//
//    }
//    if (IR == add) {
//        printf("A instrucao e a: %x", IR);
//
//        A = A + B;
//        if(LR==1){
//            PC += 4;
//        }
//
//        LR = !LR;
//
//    }
//    if (IR == sub) {
//        printf("A instrucao e a: %x", IR);
//
//        A = A - B;
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//    if (IR == mul) {
//        printf("A instrucao e a: %x", IR);
//        A = A*B;
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//    if (IR == div) {
//        printf("A instrucao e a: %x", IR);
//        A = A/B;
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//    if (IR == cmp) {
//        printf("A instrucao e a: %x", IR);
//
//        if (A == B) {
//            E = 1;
//        } else {
//            E = 0;
//        }
//
//        if (A < B) {
//            L = 1;
//        } else {
//            L = 0;
//        }
//
//        if (A > B) {
//            G = 1;
//        } else {
//            G = 0;
//        }
//        printf("\nVALOR DE E: %x \n VALOR DE L: %x \n VALOR DE G: %x", E,L,G);
//
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//
//    if (IR == xchg) {
//        printf("A instrucao e a: %x", IR);
//
//        T = A;
//
//        A = B;
//
//        B = T;
//
//
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//    if (IR == and) {
//        printf("\nA instrucao e a: %x", IR);
//        A = A & B;
//
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//    if (IR == or) {
//        printf("\nA instrucao e a: %x", IR);
//        A = A | B;
//
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//    if (IR == xor) {
//        printf("\nA instrucao e a: %x", IR);
//        A = A ^ B;
//
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//    if (IR == not) {
//        printf("\nA instrucao e a: %x", IR);
//        A = !A;
//
//        if(LR==1){
//            PC += 4;
//        }
//        LR = !LR;
//    }
//
//
//    //INSTRUCOES DO TIPO 2
//    if (IR == je) {
//        printf("\nA instrucao e a: %x", IR);
//        if (E == 1) {
//            LR = 0;
//            PC = MAR;
//        } else {
//            LR = 0;
//            PC += 4;
//        }
//    }
//    if (IR == jne) {
//        printf("\nA instrucao e a: %x", IR);
//        if (E == 0) {
//            LR = 0;
//            PC = MAR;
//        } else {
//            LR = !LR;
//            PC += 4;
//        }
//
//    }
//    if (IR == jl) {
//        printf("\nA instrucao e a: %x", IR);
//        if (L == 1) {
//            LR=0;
//            PC = MAR;
//        } else {
//            LR = !LR;
//            PC += 4;
//        }
//    }
//    if (IR == jle) {
//        printf("\nA instrucao e a: %x", IR);
//
//        if (E == 1 | L == 1) {
//            LR = 0;
//            PC = MAR;
//        } else {
//            LR = !LR;
//            PC += 4;
//        }
//    }
//    if (IR == jg) {
//        printf("\nA instrucao e a: %x", IR);
//
//        if (G == 1) {
//            LR = 0;
//            PC = MAR;
//        } else {
//            LR = !LR;
//            PC += 4;
//        }
//    }
//
//    if (IR == jge) {
//        printf("\nA instrucao e a: %x", IR);
//        if (E == 1 | G == 1) {
//            LR = 0;
//            PC = MAR;
//        } else {
//            LR = !LR;
//            PC += 4;
//        }
//    }
//    if (IR == jmp) {
//        printf("\nA instrucao e a: %x", IR);
//        LR = 0;
//        PC = MAR;
//    }
//
//
//    if (IR == lda) {
//        printf("\nA instrucao e a: %x", IR);
//        printf("\nFAZENDO O LOAD A");
//
//
//        MAR = PC;
//        if(LR == 0){
//            MBR = MEMORIA[MAR];
//
//            int i;
//            for (i = 0; i < 2; i++) {
//                MBR = (MBR << 8) | MEMORIA[MAR++];
//            };
//            MAR = MBR & maskstA;
//
//            printf("\n\n\n\t\t\t\t MAR: %x", MAR);
//            A = MEMORIA[MAR];
//            printf("\n\n\n\t\t\t\t A: %x",A);
//        }else{
//
//            MBR = MEMORIA[MAR];
//
//            MAR = IBR & maskstA;
//            A = MEMORIA[MAR];
//
//            PC += 4;
//        }
//        LR= !LR;
//    }
//
//    if (IR == ldb) {
//        printf("\nA instrucao e a: %x", IR);
//        printf("\nFAZENDO O LOAD B");
//        printf("\n O valor da Flag e: %i", LR);
//
//        if(LR == 0){
//            MAR = PC;
//            MBR = MEMORIA[MAR];
//            int i;
//            for (i = 0; i < 2; i++) {
//                MBR = (MBR << 8) | MEMORIA[MAR++];
//            };
//            MAR = MBR & maskstA;
//            B = MEMORIA[MAR];
//
//        }else{
//            MAR = PC;
//            MBR = MEMORIA[MAR];
//
//            MAR = IBR & maskstA;
//            B = MEMORIA[MAR];
//
//            PC += 4;
//        }
//        LR= !LR;
//    }
//
//    if (IR == sta) {
//        printf("\nA instrucao e a: %x", IR);
//
//        if(LR==0){
//
//            MEMORIA[MAR] = (A & 0x00ff);
//
//        } else{
//
////            MEMORIA[MAR++] = (A & 0xff00) >> 8;
//            MEMORIA[MAR] = (A & 0x00ff);
//
//            PC += 4;
//        }
//
//        LR = !LR;
//
//    }
//    if (IR == stb) {
//        printf("\nA instrucao e a: %x", IR);
//        MEMORIA[MAR] = (B & maskstA);
//        if(LR == 1){
////            MEMORIA[MAR+0x2] = B & 0xff00;
//            MEMORIA[MAR] = B & 0x00ff;
//
//            PC += 4;
//
//        }
//        LR= !LR;
//
//    }
//
//    //INSTRUCAO TIPO 1
//    if (IR == ldrb) {
//        printf("\nA instrucao e a: %x", IR);
//        A = B;
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//
//
//    //INSTRUCAO TIPO 3
//    if (IR == movial) {
//        printf("\nA instrucao e a: %x", IR);
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//    if (IR == moviah) {
//        printf("\nA instrucao e a: %x", IR);
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//
//    if (IR == addia) {
//        printf("\nA instrucao e a: %x", IR);
//        A = A + IMM;
//        printf("\n\n\n A no addia = %x %i",A, A);
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//    if (IR == subia) {
//        printf("\nA instrucao e a: %x", IR);
//        A = A - IMM;
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//    if (IR == mulia) {
//        printf("\nA instrucao e a: %x", IR);
//        A = A * IMM;
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//    if (IR == divia) {
//        printf("\nA instrucao e a: %x", IR);
//        A = A / IMM;
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//    if (IR == lsh) {
//        printf("\nA instrucao e a: %x", IR);
//        A = (A << IMM);
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//    if (IR == rsh) {
//        printf("\nA instrucao e a: %x", IR);
//        A = (A >> IMM);
//        if(LR==1){
//            PC += 4;
//        }
//        LR= !LR;
//    }
//
//}
//
//unsigned char *pt;
//
//void guardarMemoria(unsigned int mem ,unsigned int aux){
//    MEMORIA[mem++] = (aux & 0xff000000) >> 24;
//    MEMORIA[mem++] = (aux & 0x00ff0000) >> 16;
//    MEMORIA[mem++] = (aux & 0x0000ff00) >> 8;
//    MEMORIA[mem] = (aux & 0x0000ff);
//}
//
//void colocarInstru(int mem){
//    char mine[8], mine2[8]; // aux recebe rg0
//    unsigned char rg0;
//    char *ponteiro;
//    unsigned int count = 0, imediatoMem, palavra, palavra2;
//
//    ponteiro = strtok(pt," /");
//
//    while(ponteiro){
//        if(strcmp(ponteiro, "add") == 0 || strcmp(ponteiro, "hlt") == 0 ||strcmp(ponteiro, "nop") == 0 ||strcmp(ponteiro, "sub") == 0 ||
//           strcmp(ponteiro, "mul") == 0 ||strcmp(ponteiro, "div") == 0 ||strcmp(ponteiro, "cmp") == 0 ||strcmp(ponteiro, "xchg") == 0  ||
//           strcmp(ponteiro, "and") == 0 ||strcmp(ponteiro, "or") == 0 |strcmp(ponteiro, "xor") == 0 ||strcmp(ponteiro, "not") == 0 ||
//           strcmp(ponteiro, "ldrb") == 0 ){
//            strcpy(mine,ponteiro);
//
//            ponteiro = strtok(NULL," /");
//            while (ponteiro){
//                if(strcmp(ponteiro, "add") == 0 || strcmp(ponteiro, "hlt") == 0 ||strcmp(ponteiro, "nop") == 0 ||strcmp(ponteiro, "sub") == 0 ||
//                   strcmp(ponteiro, "mul") == 0 ||strcmp(ponteiro, "div") == 0 ||strcmp(ponteiro, "cmp") == 0 ||strcmp(ponteiro, "xchg") == 0  ||
//                   strcmp(ponteiro, "and") == 0 ||strcmp(ponteiro, "or") == 0 |strcmp(ponteiro, "xor") == 0 ||strcmp(ponteiro, "not") == 0 ||
//                   strcmp(ponteiro, "ldrb") == 0 ){
//                    strcpy(mine2,ponteiro);
//                } else{
//                    if(count == 0){
//                        strcpy(mine2,ponteiro);
//
//                    }
//                    if(count == 1){
//                        imediatoMem = (int)strtol(ponteiro,NULL,16);
//
//                    }
//                    ponteiro = strtok(NULL," /");
//                    count++;
//                }
//            }
//        } else{
//            if(count == 0){
//                strcpy(mine,ponteiro);
//            }
//            if (count== 1){
//                rg0 = (int)strtol(ponteiro,NULL,16);
//            }
//            if(count == 2){
//                strcpy(mine2,ponteiro);
//            }
//            if(count == 3){
//                imediatoMem = (int)strtol(ponteiro,NULL,16);
//
//            }
//            ponteiro = strtok(NULL," /");
//            count++;
//        }
//    }
//
//    if(strcmp(mine,"nop")== 0) {
//        palavra = nop;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"add")== 0){
//        palavra = add;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"sub")== 0) {
//        palavra = sub;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"mul")== 0) {
//        palavra = mul;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"div")== 0) {
//        palavra = div;
//        palavra = (palavra << 11)| 00;
//    } else if(strcmp(mine,"cmp")== 0) {
//        palavra = cmp;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"xchg")== 0) {
//        palavra = xchg;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"ldrb")== 0) {
//        palavra = ldrb;
//        palavra = (palavra << 11);
//    }
//    else if(strcmp(mine,"and")== 0) {
//        palavra = and;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"or")== 0) {
//        palavra = or;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"xor")== 0) {
//        palavra = xor;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"not")== 0) {
//        palavra = not;
//        palavra = (palavra << 11);
//    } else if(strcmp(mine,"je")== 0) {
//        palavra = je;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"jne")== 0) {
//        palavra = jne;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"jl")== 0) {
//        palavra = jl;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"jle")== 0) {
//        palavra = jle;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"jg")== 0) {
//        palavra = jg;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"jge")== 0) {
//        palavra = jge;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"jmp")== 0) {
//        palavra = jmp;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"lda")== 0){
//        palavra = lda;
//        palavra = (palavra << 11)| rg0;
//    }else if(strcmp(mine,"ldb")== 0){
//        palavra = ldb;
//        palavra = (palavra << 11)| rg0;
//    }
//    else if(strcmp(mine,"sta")== 0){
//        palavra = sta;
//        palavra = (palavra << 11)| rg0;
//
//    }  else if(strcmp(mine,"stb")== 0){
//        palavra = stb;
//        palavra = (palavra << 11)| rg0;
//
//    } else if(strcmp(mine,"movial")== 0) {
//        palavra = movial;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"moviah")== 0) {
//        palavra = moviah;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"addia")== 0) {
//        palavra = addia;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"subia")== 0) {
//        palavra = subia;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"mulia")== 0) {
//        palavra = mulia;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"divia")== 0) {
//        palavra = divia;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"lsh")== 0) {
//        palavra = lsh;
//        palavra = (palavra << 11)| rg0;
//    } else if(strcmp(mine,"rsh")== 0) {
//        palavra = rsh;
//        palavra = (palavra << 11)| rg0;
//    } else {
//        palavra = hlt;
//        palavra = (palavra << 11);
//    }
//
//    if(strcmp(mine2,"nop")== 0) {
//        palavra2 = nop;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"add")== 0){
//        palavra2 = add;
//
//        palavra2 = palavra2 << 11;
//
//    } else if(strcmp(mine2,"sub")== 0) {
//        palavra2 = sub;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"mul")== 0) {
//        palavra2 = mul;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"div")== 0) {
//        palavra2 = div;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"cmp")== 0) {
//        palavra2 = cmp;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"xchg")== 0) {
//        palavra2 = xchg;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"ldrb")== 0) {
//        palavra2 = ldrb;
//
//        palavra2 = palavra2 << 11;
//    }
//    else if(strcmp(mine2,"and")== 0) {
//        palavra2 = and;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"or")== 0) {
//        palavra2 = or;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"xor")== 0) {
//        palavra2 = xor;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"not")== 0) {
//        palavra2 = not;
//
//        palavra2 = palavra2 << 11;
//    } else if(strcmp(mine2,"je")== 0) {
//        palavra2 = je;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"jne")== 0) {
//        palavra2 = jne;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"jl")== 0) {
//        palavra2 = jl;
//
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"jle")== 0) {
//        palavra2 = jle;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"jg")== 0) {
//        palavra2 = jg;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"jge")== 0) {
//        palavra2 = jge;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"jmp")== 0) {
//        palavra2 = jmp;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"lda")== 0){
//        palavra2 = lda;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//
//    }else if(strcmp(mine2,"ldb")== 0){
//        palavra2 = ldb;
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    }
//    else if(strcmp(mine2,"sta")== 0){
//        palavra2 = sta;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//
//    }  else if(strcmp(mine2,"stb")== 0){
//        palavra2 = stb;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//
//    } else if(strcmp(mine2,"movial")== 0) {
//        palavra2 = movial;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"moviah")== 0) {
//        palavra2 = moviah;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"addia")== 0) {
//        palavra2 = addia;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"subia")== 0) {
//        palavra2 = subia;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"mulia")== 0) {
//        palavra2 = mulia;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"divia")== 0) {
//        palavra2 = divia;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"lsh")== 0) {
//        palavra2 = lsh;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else if(strcmp(mine2,"rsh")== 0) {
//        palavra2 = rsh;
//
//        palavra2 = (palavra2 << 11)| imediatoMem;
//    } else {
//        palavra2 = 0x0000;
//    }
//
//    palavra = palavra << 16 | palavra2;
//    printf("%x",palavra);
//    guardarMemoria(mem,palavra);
//}
//
//void lerArquivo(){
//
//    unsigned int mem, valor;
//    FILE *arq;
//    unsigned char tipo, linha[99];
//    unsigned int count = 0;
//    arq = fopen("instrucoes.txt", "r");
//
//    while (fgets(linha, 99, arq) != NULL){
//        pt = strtok(linha, "; ");
//        mem = (int)strtol(pt,NULL,16);
//        while(pt){
//            if(count == 1){
//                tipo = *pt;
//            }else if(count == 2){
//                if(tipo == 0x64){
//                    valor = (int)strtol(pt,NULL,16);
//                    MEMORIA[mem++] = (valor & 0x0000ff00) >> 8;
//                    MEMORIA[mem]   = (valor & 0x000000ff);
//                }else{
//                    colocarInstru(mem);
//                }
//            }
//
//            pt = strtok(NULL ,";");
//            count++;
//        }
//        count = 0;
//    }
//
//    if (NULL == arq)
//        printf("Erro ao tentar abrir programa.txt \n");
//    fclose(arq);
//}
//
//int main() {
//
//
//    MEMORIA[0x00] = 0x98;
//    MEMORIA[0x01] = 0x90;
//    MEMORIA[0x02] = 0xa0;
//    MEMORIA[0x03] = 0x92;
//
//    MEMORIA[0x04] = 0x18;
//    MEMORIA[0x05] = 0x00;
//    MEMORIA[0x06] = 0xa8;
//    MEMORIA[0x07] = 0x88;
//
//    MEMORIA[0x08] = 0x98;
//    MEMORIA[0x09] = 0x96;
//    MEMORIA[0x0a] = 0x98;
//    MEMORIA[0x0b] = 0x98;
//
//    while(IR!=0){
//        if(LR == 0) {
//            busca();
//        }
//
//        decodifica();
//        executa();
//
//
//        printf("\nRegistrador A tem o valor %x", A);
//        printf("\nRegistrador B tem o valor %x\n", B);
//
//        printf("---------------Memorias-----------------\n");
//        int i;
//        for(i = 0; i < 154 ; i++) {
//            printf("%d=[%x]  ",i,MEMORIA[i]);
//            if(i%10 == 0 && i!=0){
//                printf("\n");
//            }
//        }
//        printf("\n\t\t\t\t========== FIM DO CICLO ==========");
//        printf("\n");
//        printf("\nPressione enter para executar o proximo ciclo de instrucao\n");
////        getchar();
//
//
////24;i;cmp / jle 0
//    MEMORIA[0x24] = 0x30;
//    MEMORIA[0x25] = 0x00;
//    MEMORIA[0x26] = 0x78;
//    MEMORIA[0x27] = 0x00;
//
//
//    return 0;
//}
