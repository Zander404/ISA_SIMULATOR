//Formato de Instrucao 1
#define hlt 0b00000     //0x00  //0x00
#define nop 0b00001     //0x08  //0x01

#define add 0b00010     //0x10  //0x02
#define sub 0b00011     //0x18  //0x03
#define mul 0b00100     //0x20  //0x04
#define div 0b00101     //0x28  //0x05

#define cmp 0b000110    //0x30  //0x06
#define xchg 0b00111    //0x38  //0x07

#define and 0b01000     //0x40  //0x08
#define or 0b01001      //0x48  //0x09
#define xor 0b01010     //0x50  //0x0a
#define not 0b01011     //0x58  //0x0b

//Formato de instrucao 2
#define je 0b01100      //0x60  //0x0c
#define jne 0b01101     //0x68  //0x0d

#define jl 0b01110      //0x70  //0x0e
#define jle 0b01111     //0x78  //0x0f

#define jg 0b10000      //0x80  //0x10
#define jge 0b10001     //0x88  //0x11

#define jmp 0b10010     //0x90  //0x12

//Carrega o registrador com uma palavra de 16 bits
#define lda 0b10011     //0x98  //0x13
#define ldb 0b10100     //0xa0  //0x14

//Armazena em uma palavra de 16 bits
#define sta 0b10101     //0xa8  //0x15
#define stb 0b10110     //0xb0  //0x16


//Formato de Instrucao 1
#define ldrb 0b10111    //0xb8  //0x17


//Formato de Instrucao 3
#define movial 0b11000  //0xc0  //0x18
#define moviah 0b11001  //0xc8  //0x19

#define addia 0b11010   //0xd0  //0x1a
#define subia 0b11011   //0xd8  //0x1b
#define mulia 0b11100   //0xe0  //0x1c
#define divia 0b11101   //0xe8  //0x1d

#define lsh 0b11110     //0xf0  //0x1e
#define rsh 0b11111     //0xf8  //0x1f

// Aplicando maskara no IBR basta copiar a mask IR1 e mask MAR1
#define maskir1 0xf8000000      //| 1111 1xxx | xxxx xxxx | xxxx xxxx | xxxx xxxx
#define maskmar1 0x07FF0000     //| xxxx x111 | 1111 1111 | xxxx xxxx | xxxx xxxx

// Aplicando maskara no IBR basta copiar a mask IR2 e mask MAR2
#define maskir2 0xf800           //| 1111 1xxx | xxxx xxxx |
#define maskmar2 0x07FF          //|  | xxxx x111 | 1111 1111

// Maskara IBR
#define maskibr 0x0000ffff      //| xxxx xxxx | xxxx xxxx | 1111 1111 | 1111 1111

// Maskara REG A e REG B
#define maskA 0xffff0000         //| 1111 1111 | 1111 1111 | xxxx xxxx | xxxx xxxx
#define maskB 0x0000ffff         //| xxxx xxxx | xxxx xxxx | 1111 1111 | 1111 1111

#define maskstA 0x7ff           //| xxxx x111 | 1111 1111 |
#define lixo 0x8e                //| xxxx xxxx | 1111 1111 |
#define lixo2 0x                 //| xxxx x111 | 1111
//curl 10.42.0.137 -o "nome do arquivo"