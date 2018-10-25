#ifndef	NSIG
/** #define NSIG	32 **/
#define NSIG 15

#define	SIGHUP	1	/* hangup */
#define	SIGINT	2	/* interrupt */
#define	SIGQUIT	3	/* quit */
#define	SIGILL	4	/* illegal instruction (not reset when caught) */
#ifdef notdef
#define	    ILL_RESAD_FAULT	0x0	/* reserved addressing fault */
#define	    ILL_PRIVIN_FAULT	0x1	/* privileged instruction fault */
#define	    ILL_RESOP_FAULT	0x2	/* reserved operand fault */
#endif
/* CHME, CHMS, CHMU are not yet given back to users reasonably */
#define	SIGTRAP	5	/* trace trap (not reset when caught) */
#define	SIGIOT	6	/* IOT instruction */
#define	SIGEMT	7	/* EMT instruction */
#define	SIGFPE	8	/* floating point exception */
#ifdef notdef
#define	    FPE_INTOVF_TRAP	0x1	/* integer overflow */
#define	    FPE_INTDIV_TRAP	0x2	/* integer divide by zero */
#define	    FPE_FLTOVF_TRAP	0x3	/* floating overflow */
#define	    FPE_FLTDIV_TRAP	0x4	/* floating/decimal divide by zero */
#define	    FPE_FLTUND_TRAP	0x5	/* floating underflow */
#define	    FPE_DECOVF_TRAP	0x6	/* decimal overflow */
#define	    FPE_SUBRNG_TRAP	0x7	/* subscript out of range */
#define	    FPE_FLTOVF_FAULT	0x8	/* floating overflow fault */
#define	    FPE_FLTDIV_FAULT	0x9	/* divide by zero floating fault */
#define	    FPE_FLTUND_FAULT	0xa	/* floating underflow fault */
#endif
#define	SIGKILL	9	/* kill (cannot be caught or ignored) */
#define	SIGBUS	10	/* bus error */
#define	SIGSEGV	11	/* segmentation violation */
#define	SIGSYS	12	/* bad argument to system call */
#define	SIGPIPE	13	/* write on a pipe with no one to read it */
#define	SIGALRM	14	/* alarm clock */
#define	SIGTERM	15	/* software termination signal from kill */

#ifdef notdef
#define	SIGSTOP	17	/* sendable stop signal not from tty */
#define	SIGTSTP	18	/* stop signal from tty */
#define	SIGCONT	19	/* continue a stopped process */
#define	SIGCHLD	20	/* to parent on child stop or exit */
#define	SIGTTIN	21	/* to readers pgrp upon background tty read */
#define	SIGTTOU	22	/* like TTIN for output if (tp->t_local&LTOSTOP) */
#define SIGTINT	23	/* to pgrp on every input character if LINTRUP */
#define	SIGXCPU	24	/* exceeded CPU time limit */
#define	SIGXFSZ	25	/* exceeded file size limit */
#endif

#ifndef KERNEL
int	(*signal())();
#endif

#define	BADSIG		(int (*)())-1
#define	SIG_DFL		(int (*)())0
#define	SIG_IGN		(int (*)())1
#ifdef KERNEL
#define	SIG_CATCH	(int (*)())2
#endif
#define	SIG_HOLD	(int (*)())3

#define	SIGISDEFER(x)	(((int)(x) & 1) != 0)
#define	SIGUNDEFER(x)	(int (*)())((int)(x) &~ 1)
#define	DEFERSIG(x)	(int (*)())((int)(x) | 1)

#define	SIGNUMMASK	0377		/* to extract pure signal number */
#define	SIGDOPAUSE	0400		/* do pause after setting action */
#define	SIGDORTI	01000		/* do ret+rti after setting action */

#ifdef notdef

#define signal(a,b)	0
#define	BADSIG		-1
#define	SIG_DFL		0
#define	SIG_IGN		1

#endif notdef

#endif
