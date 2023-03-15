#include <stdio.h>
#include "cpu.h"

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


int main() {
   teste();


    return 0;
}
