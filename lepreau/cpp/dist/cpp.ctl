; Make sure your comand.cmd file gets the pcc & clink PCL cmds defined.
yacc cpy.y
ren ytab.c cpy.c
pcc cpy.c /kill /link:no
pcc cpp.c
clink cpp.rel,cpy.rel
