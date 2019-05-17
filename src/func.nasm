global INIT_FPU

global f1
global f2
global f3

global a
global b

section .rodata
	a dq -0.500000
	b dq 3.000000

	const0 dq 0.000000
	const1 dq 2.000000

section .text
INIT_FPU:
	finit
	ret

f1:
	push ebp
	mov ebp, esp
	fld qword[const0]
	sub esp, 8
	fstp qword[esp]
	fld qword[esp]
	mov esp, ebp
	pop ebp
	ret

f2:
	push ebp
	mov ebp, esp
	fld qword[ebp + 8]
	sub esp, 8
	fstp qword[esp]
	fld qword[esp]
	mov esp, ebp
	pop ebp
	ret

f3:
	push ebp
	mov ebp, esp
	fld qword[ebp + 8]
	sub esp, 8
	fstp qword[esp]
	fld qword[ebp + 8]
	sub esp, 8
	fstp qword[esp]
	fld qword[esp + 8]
	fld qword[esp]
	fmulp
	add esp, 8
	fstp qword[esp]
	fld qword[const1]
	sub esp, 8
	fstp qword[esp]
	fld qword[esp + 8]
	fld qword[esp]
	fsubp
	add esp, 8
	fstp qword[esp]
	fld qword[esp]
	mov esp, ebp
	pop ebp
	ret

