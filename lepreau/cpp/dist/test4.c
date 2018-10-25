main()
{
    char *c;
    *c = 'X';
    foo4(1.0,2.0,3.0, 1,2,c);
}

foo4(x,y,z,a,b,c)
register float x;
float y;
float z;
int a;
register int b;
register char * c;
{

    char c1;
    float r1;
    int i1;
    long l1;
    short s1;

    static char c2;
    static float r2;
    static int i2;
    static long l2;
    static short s2;

    unsigned char c3;
    unsigned int i3;
    unsigned long l3;
    unsigned short s3;

    static unsigned char c4;
    static unsigned int i4;
    static unsigned long l4;
    static unsigned short s4;

    struct 
    {
        float mosr1;
	int   mosi1;
    } st1;

    static struct 
    {
        float mosr2;
	int   mosi2;
    } st2;

    enum spectrum
    {
	red, orange, yellow, green, blue, indigo, violet
    } color1;

    static enum spectrum color2;

    x = y*z;
    *c = (char)(a+b);
    bar((int)x);
    return (x);
}

bar(a)
register int a;
{
    register int b;

    mung(a);
    mung(b);
}

mung(c)
int c;
{
    printf("mung(%d)\n",c);
}
