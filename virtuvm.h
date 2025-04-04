#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <virtuvm_utils.h>

#define ErrMem      0x01    /* 00 10 */
#define NoArgs      {0x00, 0x00}

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

/*
  this would be the 16bit VM with 65kb memory

  AX - Reg
  BX
  CX
  DX
  SP - Stack top pointer
  IP - Instuction pointer
  
*/

typedef unsigned short int Reg;

struct s_registers {
    Reg ax;
    Reg bx;
    Reg cx;
    Reg dx;
    Reg sp;
    Reg ip;
};
typedef struct s_registers Registers;

struct s_cpu {
    Registers r;
};
typedef struct s_cpu CPU;

/*
    To make this work many Instuction/Opcode 
    has to be implimented.
 */

enum e_opcode{
    mov = 0x01,
    nop = 0x02
};
typedef enum e_opcode Opcode;

struct s_instrmap {
    Opcode o;
    int8 s;
};
typedef struct s_instrmap IM;


typedef int8 Args;

struct s_instruction {
    Opcode o;
    Args a[]; // Opcode Args 0-2 bytes
};
typedef struct s_instruction *Instruction;

typedef int8 Memory[(unsigned int)(-1)];
typedef int8 Program; // <-- I could use it as array of Instructions. (maybe)

struct s_vm {
    CPU c;
    Memory m;
    Program *p;
};
typedef struct s_vm VM;
typedef Memory *Stack;
/* 
    mov ax 0x05 ==> (0x01 OR 0x02)
                // 0000 0011 = mov
                // 0000 0000 
                // 0000 0101 = 0x05
 */

static IM instrmap[] = {
    { mov, 0x03 },
    { nop, 0x01 }
};

#define IMs (sizeof(instrmap)/sizeof(struct s_instrmap))

Program exampleprogram(void);
int8 map(Opcode);
VM *virtualmachine(Program,int16);
int main(int, char**);
