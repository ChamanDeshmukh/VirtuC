#include "virtuvm.h"

int8 map(Opcode o){

    int8 n,ret;
    IM *p;

    ret = 0;
    for(n=IMs, p=instrmap; n; n--,p++)
        if (p->o == o) {
            ret = p->s;
            break;
        }
    return ret;
}

VM *virtualmachine(){
    VM *p;
    // Program *pp;
    int16 size;

    size = $2 sizeof(struct s_vm);
    p = (VM *)malloc($i size);

    if(!p){
        errno = ErrMem;
        return (VM *)0; 
    }
    zero($1 p,size);

    /*
    zero($1 p,size);
    pp = (Program *)malloc($i progsz);
    if (!pp) {
        free(p);
        errno = ErrMem;

        return (VM *)0;
    }
    copy(pp, pr, progsz);
    */
    return p;
}


Program *exampleprogram(VM *vm){
    Program *p;
    Instruction *i1, *i2;
    Args *a1;
    int16 s1, s2, sa1, ps;

    s1 = map(mov);
    s2 = map(nop);

    i1 = (Instruction *)malloc($i s1);
    i2 = (Instruction *)malloc($i s2);
    assert(i1 && i2);
    zero($1 i1, s1);
    zero($1 i2, s2);

    i1->o = mov;
    sa1 = (s1 - 1);
    if (!s1) {
        a1 = (Args *)malloc($i sa1);
        assert(a1);

        zero(a1,sa1);

        *a1 = 0x00;
        *(a1+1) = 0x05;
    }

    ps = (s1 + s2);
    p = vm->m
    copy($1 p, i1, 1);
    p++;
    copy($i p, $1 a1, sa1);
    p += sa1;

}


int main(int argc, char *argv[]){

    int8 size;
    Program *prog;
    VM *vm;
    
    size = (map(mov) + map(nop));
    prog = exampleprogram();
    printf("Prog = %p\n",prog);

    vm = virtualmachine(prog, size);
    printf("VM = %p\n",vm);
    return 0;

}
