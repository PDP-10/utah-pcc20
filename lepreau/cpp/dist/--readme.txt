                      Notes on PCC-20

------------------------------------------------------------
[16-Jan-88]
I just fixed a bug in zecode() in code.c; trailing commas on
"exp n,n,n," result in generation of an (incorrect) extra  0
value.  I just used the REPEAT code (see below) from code2.c
in code.c, BUT HAVE NOT FIXED IT IN CODE2.  With the  advent
of KCC-20, I hadn't planned to  do any more work on  PCC-20,
so  the   glorious   plans  discussed   below   have   never
materialized.

------------------------------------------------------------
[24-Jan-86]
Two modules have been changed for this work, and are renamed
to CODE2.C and PFTN2.C to preserve the original ones.   They
affect only pass  one of  the compiler.  To  rebuild a  test
version of C1.EXE, C1TEST.EXE, do

@DO --C1TEST

To run a test C program, FOO.C, through this version, do

@DO CPP FOO

to create FOO.I, then either

@DO C1TEST FOO

to run just pass one creating FOO.M, or

@DO CC FOO

to run passes 1-3, and LINK the resulting program.

------------------------------------------------------------
[24-Jan-86]
The "extern  $start"  statement  issued in  CODE2.C  is  not
needed.  It should be removed the  next time we work on  the
compiler.

------------------------------------------------------------
[24-Jan-86]
One way to  handle the problem  of external names  discussed
below would  be  to  append "##"  to  all  external  symbols
referenced in the  MACRO output.  The  work of pextrns()  in
CODE2.C would  then  be unnecessary.   I  have  occasionally
found that large programs  confuse MACRO because of  delayed
symbol definitions; putting  the "##" suffix  on such  names
would probably resolve this problem.  This solution can only
work when  the  modules  are  output  with  separate  symbol
tables.

------------------------------------------------------------
[20-Jan-86]
An annoying feature of PCC-20 is that a LOAD of a compiled C
program, FOO.REL, followed by a SAVE will attempt to save it
on PLIB.EXE, instead of FOO.EXE.

This has been tracked down and determined to arise from  the
fact that the main program, $START, is defined in  PLIB.EXE,
and that is  apparently what  LINK uses to  set the  program
name, probably with  SETNM, since that  is what  INFORMATION
VERSION and SAVE both get.

CONCLUSION: Nothing can be done about it, short of  revising
the compiler to recognize when  a main() is being  compiled,
and insert the code for $START ..., which is a bad idea.

------------------------------------------------------------
[20-Jan-86]
It would be very nice  to have all local variables  declared
to MACRO so they get into the symbol table.

In CODE.C, when we have
	static int k;
we get in output FOO.M file

)$Snn:!
)	exp 0

and for
	static char* s = "something"

we get
)$Snn:!
	BYTE	(36),n1,n2,..,nk,0

All we need to do for these is emit extra labels:

)k:!
)s:!

For register variables,
	register int foo,bar;
we should emit
)foo=:13
)bar=:12
and for automatics,
	int x,y;
we should get something like
)x=:<6(16)>
)y=:<7(16)>
The latter two get defined as 16,,6 and 16,,7, which works
fine if we do "move 0,x"$X in DDT, but does not work if we
do
x/	! <- this looks at location 6
y/	! <- and 7
We need  to look  at the  LINK  manual to  find out  how  to
declare offset symbols in  Algol-like languages, or  perhaps
use something from extended addressing.

Code in CODE2.C and PFTN2.C delineated by

#ifdef GENLABELS
...
#endif

outputs symbol  definitions for  register variables  in  the
form

name=$nn

where nn (in  12 ..  15) is  one of  the standard  registers
defined in pcc:$cdefs.unv.

Argument variables are defined in the form

%name=-nn

which says that the variable "name" is found at  %name($fp).
The additional % character  was chosen to distinguish  stack
variables from static and register variables.

Still unresolved is  where all of  the local variables  are.
They do not seem to be  in the symbol table stab[],  because
print statements in a  loop over all  entries fails to  find
them.  Code is generated to define them at module ends  with
statements

; Begin Local Variables
...
; End Local Variables

but all that  appears there are  comments containing  global
variables.  The  files  TEST4.*  can  be  used  for  testing
purposes.

CONCLUSION:
The GENLOCALS  additions  are  okay,  but  further  work  is
necessary to track down the remaining locals.

------------------------------------------------------------
[20-Jan-86]

PROBLEM:
In CODE.C, zecode(n) emits n words of 0's, creating enormous
.M and .S files; surely we can use a repeat count!   Instead
of

)	exp	v,v,v,v,v,v,v,....
)	exp	v,v,v,v,v,v,v,....
...

generate

)	xlist
)	repeat 250,<exp	v>
)	list

SOLUTION:
Change zecode() to fix  it.  Defining symbol REPEAT  selects
this change.

------------------------------------------------------------
[24-Jan-86]
On the problem of making symbols available to DDT, we  tried
the following  with code  selected  by defining  the  symbol
GENMODULES in CODE2.C and PFTN2.C.

Instead of the current MACRO file structure of


	TITLE	foo
	entry	foo,bar,mung
foo:	...


	jrst	$cret
bar:	...


	jrst	$cret
mung:	...


	jrst	$cret
	END

which generates one symbol table FOO containing functions foo(),
bar(), and mung(), we could generate

	entry	foo

	TITLE	foo
foo:	jfcl
x:	0
	PRGEND

	TITLE	bar
bar:	jfcl
x:	0
	PRGEND


	TITLE	mung
mung:	jfcl
x:	0
	PRGEND

	END

This gives four  symbol tables:  FOO, BAR, MUNG,  and .MAIN;  the
latter comes from  the empty  module following  the last  PRGEND.
LINK just loads this as a zero length module, and doesn't care if
there is more than one of them.

This does not work for the following reasons:

	* CODE2.C generates an extra (illegal) "RELOC" after
	the "PRGEND" is emitted, and before the next "TITLE"
	is output.  This could probably be fixed by  further
	study of the code.

	* the function pextrns()  in CODE2.C is called  only
	at  the  end  of  the  entire  compilation  to  emit
	"EXTERN" statements for externals referenced in  the
	code body.   It  should  be called  in  ftnend()  in
	PFTN2.C   just   before   emitting   the   "PRGEND".
	Otherwise externals like "printf" are not defined.

	* MACRO supports  only one  level of  modularization
	with the symbol table being equivalent to a  program
	module, and symbols  not defined in  the module  are
	left to be  resolved by LINK,  making them  globally
	known.   C  has  two  levels  --  the  module  level
	(functions),  and  the   file  level.   A   function
	declared "static"  in a  file  is available  to  all
	functions in that file, but is invisible outside.  A
	function  not  declared   "static"  is  global   and
	available to functions  in all  other source  files.
	Although "static" functions are  not widely used  in
	C, they do allow multiple files to have functions of
	the   same   name    without   conflicts    arising.
	Consequently, MACRO's  TITLE  ...  PRGEND  mechanism
	simply cannot  work  with C;  the  only way  to  get
	around this problem would  be to generate  duplicate
	code for each  "static" function  inside each  TITLE
	... PRGEND sequence  encapsulating another  function
	which requires that "static" function.  Since  MACRO
	has a powerful macro facility, with further work, we
	could probably add  this via  macro definitions,  so
	that code generation would still only have to happen
	once.  There is  of course the  question of  whether
	the macro  would  be defined  at  the place  it  was
	referenced.

In summary, the code in CODE2.C and PFTN2.C delineated by

#ifdef GENMODULES
...
#endif

cannot be activated until the work described in these  three
points is completed.

The file TEST4.C is preserved as a test case for this work.

------------------------------------------------------------
