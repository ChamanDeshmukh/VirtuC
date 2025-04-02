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

struct s_vm {
  CPU c,
  Stack *s;

};

int main(int, char**);
