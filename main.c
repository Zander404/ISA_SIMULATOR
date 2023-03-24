#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"
                                            // Tamanho em bits
unsigned char MEMORIA[154];                 //8 bits

unsigned int MBR;                           // 32 bits

unsigned short int MAR, IBR, IR, IMM, PC;   //16 bits

unsigned char E, L, G, LR;                  //8 bits

unsigned short int A, B, T;                 //16 bits


//int criar_palavra(char instrucao[], unsigned short int regA, unsigned short int regB, unsigned int menOuImm, int inicio)
//{
//    int palavra;
//    if(strcmp(instrucao,"ld")== 0){
//        palavra = ld;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"st")== 0){
//        palavra = st;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"add")== 0){
//        palavra = add;
//        palavra = (palavra << 3) |reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra =  palavra << 18;
//    }else if(strcmp(instrucao,"sub")== 0) {
//        palavra = sub;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"mul")== 0) {
//        palavra = mul;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"div")== 0) {
//        palavra = div;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"cmp")== 0) {
//        palavra = cmp;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"movr")== 0) {
//        palavra = movr;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra = palavra << 18;
//    }
//    else if(strcmp(instrucao,"and")== 0) {
//        palavra = and;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"or")== 0) {
//        palavra = or;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 3) | reg2;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"xor")== 0) {
//        palavra = xor;
//        palavra = (palavra << 3) | ro0;
//        palavra = (palavra << 3) | palavra;
//        palavra = palavra << 18;
//    }else if(strcmp(instrucao,"not")== 0) {
//        palavra = not;
//        palavra = (palavra << 3)|ro0;
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
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"addi")== 0) {
//        palavra = addia;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"subi")== 0) {
//        palavra = subia;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"muli")== 0) {
//        palavra = mulia;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"divi")== 0) {
//        palavra = divia;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"lsh")== 0) {
//        palavra = lsh;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else if(strcmp(instrucao,"rsh")== 0) {
//        palavra = rsh;
//        palavra = (palavra << 3) | reg1;
//        palavra = (palavra << 21) | menOuImm;
//    }else{
//        palavra  = 0;
//    }
//    MEMORIA[inicio++] = palavra >> 24;
//    MEMORIA[inicio++] = (palavra & 0x00ff0000) >> 16;
//    MEMORIA[inicio++] = (palavra & 0x0000ff00) >> 16;
//    MEMORIA[inicio] = palavra & 0x000000ff;
//
//    return palavra;
//}
////
//void lerTexto()
//{
//    FILE *arq;
//    char *pl;
//    char str[50];
//    char instrucao[10];
//    int count = 0;
//    int inicio;
//    char tipo;
//    unsigned int palavra;
//    unsigned int reg1;
//    unsigned int reg2;
//    unsigned int menOuImm;
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
//                           strcmp(pl, "cmp") == 0 || strcmp(pl, "movr") == 0 ||
//                           strcmp(pl, "and") == 0 || strcmp(pl, "or") == 0 ||
//                           strcmp(pl, "xor") == 0)
//                        {
//                            strcpy(instrucao,pl);  //Pega a instrucao do texto
//                            pl = strtok(NULL,"r, ");
//                            reg1 = (int) strtol(pl, NULL, 16); //armazena no ro1
//                            pl = strtok(NULL,"r, ");
//                            reg2 = (int) strtol(pl, NULL, 16); //armazena no ro2
//
//                            criar_palavra(instrucao,reg1,reg2,0,inicio);
//                        } else if(strcmp(pl, "not") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            pl = strtok(NULL,"r, ");
//                            reg1 = (int) strtol(pl, NULL, 16);
//                            criar_palavra(instrucao,reg1,0x0,0x0,inicio);
//                        } else if(strcmp(pl, "je") == 0 || strcmp(pl, "jne") == 0 ||
//                                  strcmp(pl, "jl") == 0 || strcmp(pl, "jle") == 0 ||
//                                  strcmp(pl, "jg") == 0 || strcmp(pl, "jge") == 0 ||
//                                  strcmp(pl, "jmp") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            pl = strtok(NULL,", ");
//                            menOuImm = (int) strtol(pl, NULL, 16);
//                            palavra = criar_palavra(instrucao,0x00,0x00,menOuImm,inicio);
//                        } else if(strcmp(pl, "ld") == 0 || strcmp(pl,"st") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            pl = strtok(NULL, "r, ");
//                            reg1 = (int) strtol(pl,NULL,16);
//                            pl = strtok(NULL, ", ");
//                            menOuImm = (int) strtol(pl, NULL, 16);
//                            palavra = criar_palavra(instrucao,reg1,0x00,menOuImm,inicio);
//                        }else if(strcmp(pl, "addi") == 0 || strcmp(pl, "subi") == 0 ||
//                                 strcmp(pl, "muli") == 0 || strcmp(pl, "divi") == 0 ||
//                                 strcmp(pl, "movi") == 0 ||strcmp(pl, "lsh") == 0 ||
//                                 strcmp(pl, "rsh") == 0)
//                        {
//                            strcpy(instrucao, pl);
//                            pl = strtok(NULL,"r, ");
//                            reg1 = (int) strtol(pl, NULL, 16);
//                            pl = strtok(NULL,"r, ");
//                            menOuImm = (int) strtol(pl,NULL,16);
//                            palavra = criar_palavra(instrucao,reg1,0x00,menOuImm,inicio);
//                        }else if(strcmp(pl, "nop") == 0 || strcmp(pl, "hlt") == 0)
//                        {
//                            strcpy(instrucao,pl);
//                            palavra = criar_palavra(instrucao,0x00,0x00,0x00,inicio);
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


void busca() {
    MAR = PC;
    MBR = MEMORIA[MAR++];

    int i;
    for (i = 0; i < 3; i++) {
        MBR = (MBR << 8) | MEMORIA[MAR++];
    };

    printf("%x", MBR);

}


void decodifica() {


    if(LR == 0){
        IBR = (MBR&maskibr);
        IR = (MBR&maskir1)>>27;
        printf("\n\t\t\t\t\t INSTRUCAO DO MAL: %x", IR);

        printf("\n\nEstou na esquerda");


        //Instrucao Tipo 2
        //    XXXX XMMM MMMM MMMM
        if(IR >= hlt && IR<=not){
            MAR=0;
        }
        if (IR >= je && IR <= stb) {
            MAR = (MBR&maskmar1)>>16;

        }

        //Instrucao Tipo 3
        if (IR >= movial && IR <= rsh) {
            IMM = (MBR&maskmar1)>>16;



        }
        printf("\n O valor da Flag e: %i", LR);
        printf("\n\n\t\t O VALOR DE PC: %x",PC);
        printf("\n O valor do IR e: %x",IR);
        printf("\n O valor do IBR e: %x",IBR);
        printf("\n O valor do MBR e: %x",MBR);
        printf("\n O valor do MAR e: %x",MAR);
        printf("\n");

    }else{
        IR = (IBR&maskir2)>>11;
        //Instrucao Tipo 2
        //    XXXX XMMM MMMM MMMM
        if (IR >= je && IR <= stb) {
            MAR = IBR&0x007ff;
        }

        //Instrucao Tipo 3
        if (IR >= movial && IR <= rsh) {

            IMM = (IBR&maskmar2);


        }
        printf("\n\nEstou na direita");
        printf("\n O valor da Flag e: %i", LR);
        printf("\n\n\t\t O VALOR DE PC: %x",PC);
        printf("\n O valor do IR e: %x",IR);
        printf("\n O valor do IBR e: %x",IBR);
        printf("\n O valor do MBR e: %x",MBR);
        printf("\n O valor do MAR e: %x",MAR);
        printf("\n O valor d o IMM e: %x", IMM);
        printf("\n");


    }

}


void executa() {

    printf("\nTESTE DO CARALHO\t\t\t\t\t\t IR: %x", IR);

    if (IR == hlt) {
//        condicao de parada
    }
    if (IR == nop) {
        printf("A instrucao e a: %x", IR);
        if(LR==1){
            PC += 4;
        }

        LR = !LR;

    }
    if (IR == add) {
        printf("A instrucao e a: %x", IR);

        A = A + B;
        if(LR==1){
            PC += 4;
        }

        LR = !LR;

    }
    if (IR == sub) {
        printf("A instrucao e a: %x", IR);

        A = A - B;
        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }
    if (IR == mul) {
        printf("A instrucao e a: %x", IR);
        A = A*B;
        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }
    if (IR == div) {
        printf("A instrucao e a: %x", IR);
        A = A/B;
        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }
    if (IR == cmp) {
        printf("A instrucao e a: %x", IR);

        if (A == B) {
            E = 1;
        } else {
            E = 0;
        }

        if (A < B) {
            L = 1;
        } else {
            L = 0;
        }

        if (A > B) {
            G = 1;
        } else {
            G = 0;
        }
        printf("\nVALOR DE E: %x \n VALOR DE L: %x \n VALOR DE G: %x", E,L,G);

        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }

    if (IR == xchg) {
        printf("A instrucao e a: %x", IR);

        T = A;

        A = B;

        B = T;


        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }
    if (IR == and) {
        printf("\nA instrucao e a: %x", IR);
        A = A & B;

        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }
    if (IR == or) {
        printf("\nA instrucao e a: %x", IR);
        A = A | B;

        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }
    if (IR == xor) {
        printf("\nA instrucao e a: %x", IR);
        A = A ^ B;

        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }
    if (IR == not) {
        printf("\nA instrucao e a: %x", IR);
        A = !A;

        if(LR==1){
            PC += 4;
        }
        LR = !LR;
    }


    //INSTRUCOES DO TIPO 2
    if (IR == je) {
        printf("\nA instrucao e a: %x", IR);
        if (E == 1) {
            LR = 0;
            PC = MAR;
        } else {
            LR = 0;
            PC += 4;
        }
    }
    if (IR == jne) {
        printf("\nA instrucao e a: %x", IR);
        if (E == 0) {
            LR = 0;
            PC = MAR;
        } else {
            LR = !LR;
            PC += 4;
        }

    }
    if (IR == jl) {
        printf("\nA instrucao e a: %x", IR);
        if (L == 1) {
            LR=0;
            PC = MAR;
        } else {
            LR = !LR;
            PC += 4;
        }
    }
    if (IR == jle) {
        printf("\nA instrucao e a: %x", IR);
        printf("\nSOU O JUMP JLE");
        if (E == 1 | L == 1) {
            LR = 0;
            PC = MAR;
        } else {
            LR = !LR;
            PC += 4;
        }
    }
    if (IR == jg) {
        printf("\nA instrucao e a: %x", IR);

        if (G == 1) {
            LR = 0;
            PC = MAR;
        } else {
            LR = !LR;
            PC += 4;
        }
    }

    if (IR == jge) {
        printf("\nA instrucao e a: %x", IR);
        if (E == 1 | G == 1) {
            LR = 0;
            PC = MAR;
        } else {
            LR = !LR;
            PC += 4;
        }
    }
    if (IR == jmp) {
        printf("\nA instrucao e a: %x", IR);
        LR = 0;
        PC = MAR;
    }


    if (IR == lda) {
        printf("\nA instrucao e a: %x", IR);
        printf("\nFAZENDO O LOAD A");


        MAR = PC;
        if(LR == 0){
            MBR = MEMORIA[MAR];

            int i;
            for (i = 0; i < 2; i++) {
                MBR = (MBR << 8) | MEMORIA[MAR++];
            };
            MAR = MBR & maskstA;

            printf("\n\n\n\t\t\t\t MAR: %x", MAR);
            A = MEMORIA[MAR];
            printf("\n\n\n\t\t\t\t A: %x",A);
        }else{

            MBR = MEMORIA[MAR];

            MAR = IBR & maskstA;
            A = MEMORIA[MAR];

            PC += 4;
        }
        LR= !LR;
    }

    if (IR == ldb) {
        printf("\nA instrucao e a: %x", IR);
        printf("\nFAZENDO O LOAD B");
        printf("\n O valor da Flag e: %i", LR);

        if(LR == 0){
            MAR = PC;
            MBR = MEMORIA[MAR];
            int i;
            for (i = 0; i < 2; i++) {
                MBR = (MBR << 8) | MEMORIA[MAR++];
            };
            MAR = MBR & maskstA;
            B = MEMORIA[MAR];

        }else{
            MAR = PC;
            MBR = MEMORIA[MAR];

            MAR = IBR & maskstA;
            B = MEMORIA[MAR];

            PC += 4;
        }
        LR= !LR;
    }

    if (IR == sta) {
        printf("\nA instrucao e a: %x", IR);

        if(LR==0){
//            MEMORIA[MAR++] = (A & 0xff00) >> 8;
            MEMORIA[MAR] = (A & 0x00ff);

        } else{

//            MEMORIA[MAR++] = (A & 0xff00) >> 8;
            MEMORIA[MAR] = (A & 0x00ff);

            PC += 4;
        }

        LR = !LR;

    }
    if (IR == stb) {
        printf("\nA instrucao e a: %x", IR);
        MEMORIA[MAR] = (B & maskstA);
        if(LR == 1){
//            MEMORIA[MAR+0x2] = B & 0xff00;
            MEMORIA[MAR] = B & 0x00ff;

            PC += 4;

        }
        LR= !LR;

    }

    //INSTRUCAO TIPO 1
    if (IR == ldrb) {
        printf("\nA instrucao e a: %x", IR);
        A = B;
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }


    //INSTRUCAO TIPO 3
    if (IR == movial) {
        printf("\nA instrucao e a: %x", IR);
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }
    if (IR == moviah) {
        printf("\nA instrucao e a: %x", IR);
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }

    if (IR == addia) {
        printf("\nA instrucao e a: %x", IR);
        A = A + IMM;
        printf("\n\n\n A no addia = %x %i",A, A);
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }
    if (IR == subia) {
        printf("\nA instrucao e a: %x", IR);
        A = A - IMM;
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }
    if (IR == mulia) {
        printf("\nA instrucao e a: %x", IR);
        A = A * IMM;
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }
    if (IR == divia) {
        printf("\nA instrucao e a: %x", IR);
        A = A / IMM;
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }
    if (IR == lsh) {
        printf("\nA instrucao e a: %x", IR);
        A = (A << IMM);
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }
    if (IR == rsh) {
        printf("\nA instrucao e a: %x", IR);
        A = (A >> IMM);
        if(LR==1){
            PC += 4;
        }
        LR= !LR;
    }

}

int main() {

////    0;i;lda 96/ldb 98
//    MEMORIA[0x00] = 0x98;
//    MEMORIA[0x01] = 0x96;
//    MEMORIA[0x02] = 0xa0;
//    MEMORIA[0x03] = 0x98;
//
////    4;i;sub/xchg
//    MEMORIA[0x04] = 0x18;
//    MEMORIA[0x05] = 0x00;
//    MEMORIA[0x06] = 0x38;
//    MEMORIA[0x07] = 0x00;
//
////    8;i;lda 94/div
//    MEMORIA[0x08] = 0x98;
//    MEMORIA[0x09] = 0x94;
//    MEMORIA[0x0a] = 0x28;
//    MEMORIA[0x0b] = 0x00;
//
////    c;i;ldb 92/mul
//    MEMORIA[0x0c] = 0xa0;
//    MEMORIA[0x0d] = 0x92;
//    MEMORIA[0x0e] = 0x20;
//    MEMORIA[0x0f] = 0x00;
//
////    10;i;ldb 90/add
//    MEMORIA[0x10] = 0xa0;
//    MEMORIA[0x11] = 0x90;
//    MEMORIA[0x12] = 0x10;
//    MEMORIA[0x13] = 0x00;
//
////    14;i;sta 8e/hlt
//    MEMORIA[0x14] = 0xa8;
//    MEMORIA[0x15] = 0x8e;
//    MEMORIA[0x16] = 0x00;
//    MEMORIA[0x17] = 0x00;
//
////    90;d;20
//    MEMORIA[0x90] = 0x20;
//
////    92;d;3
//    MEMORIA[0x92] = 0x03;
////    94;d;4
//    MEMORIA[0x94] = 0x04;
//
////    96;d;5
//    MEMORIA[0x96] = 0x05;
//
////    98;d;3
//    MEMORIA[0x98] = 0x03;
//REPOSTA 38 OU 0X26


//    0;i;lda 90 / ldb 92 OKKKKKK
    MEMORIA[0x00] = 0x98;
    MEMORIA[0x01] = 0x90;
    MEMORIA[0x02] = 0xa0;
    MEMORIA[0x03] = 0x92;

//    4;i;div / sta 88 OKKKK
    MEMORIA[0x04] = 0x28;
    MEMORIA[0x05] = 0x00;
    MEMORIA[0x06] = 0xa8;
    MEMORIA[0x07] = 0x88;

//    8;i;lda 96 / lda 98 OKKKKK
    MEMORIA[0x08] = 0x98;
    MEMORIA[0x09] = 0x96;
    MEMORIA[0x0a] = 0x98;
    MEMORIA[0x0b] = 0x98;

//c;i;sub/lda 94 DUVIDOSO
    MEMORIA[0x0c] = 0x18;
    MEMORIA[0x0d] = 0x00;
    MEMORIA[0x0e] = 0x98;
    MEMORIA[0x0f] = 0x94;

//10;i;mul/lda 88 OKKKKKKK
    MEMORIA[0x10] = 0x20;
    MEMORIA[0x11] = 0x00;
    MEMORIA[0x12] = 0x98;
    MEMORIA[0x13] = 0x88;

//14;i;add / lda 8a  OKKKKKKK
    MEMORIA[0x14] = 0x10;
    MEMORIA[0x15] =0x00;
    MEMORIA[0x16] = 0x98;
    MEMORIA[0x17] = 0x8a;

//18;i;add / sta 8a OKKKKKKKK
    MEMORIA[0x18] = 0x10;
    MEMORIA[0x19] = 0x00;
    MEMORIA[0x1a] = 0xa8;
    MEMORIA[0x1b] = 0x8a;

//1c;i;lda 8c / ldb 8e OKKKKKKK
    MEMORIA[0x1c] = 0x98;
    MEMORIA[0x1d] = 0x8c;
    MEMORIA[0x1e] = 0xa0;
    MEMORIA[0x1f] = 0x8e;

//20;i;addia 1 / sta 8c ERRO ELE NAO COLOCA O VALOR DE MAR PARA A INSTRUCAO DA DIREITA LINHA 305
    MEMORIA[0x20] = 0xd0; //ELE LE O DECODIFICA DE ADDI 2 VEZES
    MEMORIA[0x21] = 0x01;
    MEMORIA[0x22] = 0xa8;
    MEMORIA[0x23] = 0x8c;

//24;i;cmp / jle 0
    MEMORIA[0x24] = 0x30;
    MEMORIA[0x25] = 0x00;
    MEMORIA[0x26] = 0x78;
    MEMORIA[0x27] = 0x00;

//28;i;hlt / hlt
    MEMORIA[0x28] = 0x00;
    MEMORIA[0x29] = 0x00;
    MEMORIA[0x2a] = 0x00;
    MEMORIA[0x2b] = 0x00;
// 8a;d;0
    MEMORIA[0x8a] = 0x00;
//8c;d;1
    MEMORIA[0x8c] = 0x01;
//8e;d;a
    MEMORIA[0x8e] = 0x0a;
//90;d;a
    MEMORIA[0x90] = 0x0a;
//92;d;5;
    MEMORIA[0x92] = 0x05;


    // NA POSICAO: 0x8a  RESPOSTA 50 OU 0X32
    //lerTexto();
    PC = 0;
    MAR = 0;
    IR=-1;



    while(IR!=0){
        busca();
        decodifica();
        executa();


        printf("\nRegistrador A tem o valor %x", A);
        printf("\nRegistrador B tem o valor %x\n", B);

        printf("---------------Memorias-----------------\n");
        int i;
        for(i = 0; i < 154 ; i++) {
            printf("%d=[%x]  ",i,MEMORIA[i]);
            if(i%10 == 0 && i!=0){
                printf("\n");
            }
        }
        printf("\nPressione enter para executar o proximo ciclo de instrucao\n");
//        getchar();
}


    return 0;
}
