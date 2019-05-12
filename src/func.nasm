global INIT_FPU

global f1
global f2
global f3

global a
global b

section .rodata
    a dq -0.5
    b dq 3.0
    const1 dq 2.0


section .text
INIT_FPU:
    finit
    ret

f1:
    fldz
    ret

f2:
    fld qword[esp + 4]
    ret

f3:
    fld qword[esp + 4]
    fld qword[esp + 4]
    fmulp
    fld qword[const1]
    fsubp
    ret