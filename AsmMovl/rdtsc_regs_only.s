# original version of this code was generated using gcc -S
# this file can be compiled using gcc <this_file.s>
	.file	"inlined_rdtsc.cpp"
	.text
	.section .rdata,"dr"
	.align 4
	.def	__main;	.scl	2;	.type	32;	.endef
	.def	__main;	.scl	2;	.type	32;	.endef
.LC1:
	.ascii "diffC: %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB50:
# this is standard routine which main function normally starts with
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
# end of standard foutine
	
#while (true) {
.L2:
	rdtscp               #TimeStampCounter such that LO goes to EAX, HI goes to EDX.
						 
	movl	%eax, %ebx   # Save captured LO cycles counter to EBX.
                         # We don't care about EDX because we never exceed 2^32 cycles.
						 
 	rdtscp               # Capture cycles counter again to EAX,EDX.
	
	subl	%ebx, %eax   # compute EAX:=EAX-EBX
	movl	%eax, %edx   # and prepare arguments for printf
	
	leaq	.LC1(%rip), %rcx # printf format string ("diffC: %d\12\0")
	call	printf       # invoke printf("diffC: %d\12\0", ...)
	
	jmp	.L2              # repeat
# }
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
