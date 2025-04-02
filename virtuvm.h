#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "errno.h"
#include "virtuvm_utils.h"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int 8 *)
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


struct s_instruction {
    Opcode o;
    Args a[]; // Opcode Args 0-2 bytes
};
typedef struct s_instruction Instuction;

typedef int8 Stack[-1];
typedef Instuction Program;

struct s_vm {
    CPU c,
    Stack s;
    Program *p;
};
typedef struct s_vm VM;

int main(int, char**);
