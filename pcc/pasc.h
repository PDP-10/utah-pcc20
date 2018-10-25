#define Boolean char
#define byte char

#define false 0
#define true 1
#define maxint 2147483647

extern char *malloc();

#define pred(x) ((x)-1)
#define succ(x) ((x)+1)
#define odd(x) ((x)&1)

#define eof(p) (peek(p),feof(p))
#define peek(p) (((p)->_cnt<=0 ? ungetc(_filbuf(p),(p)) : 0), *(p)->_ptr&0377)
#define eoln(p) (peek(p)=='\n')

#define	readln(p) while ((getc(p))!='\n')
#define writeln(p) (putc('\n',p),(void)fflush(p))
