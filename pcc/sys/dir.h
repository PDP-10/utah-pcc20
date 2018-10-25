#ifndef	DIRSIZ
#define	DIRSIZ	26
#endif
struct	dir			/* this is plain dir.h, not used much */
{
	ino_t	d_ino;
	char	d_name[DIRSIZ];
};

struct	direct			/* this is sys/dir.h */
{
	ino_t	d_ino;
	char	d_name[DIRSIZ];
};
