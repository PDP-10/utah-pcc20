! File to recompile and rebuild Pass 1 of PCC compiler

@cc -c cgram.c clocal.c code.c comm1.c local.c optim.c pftn.c scan.c trees.c xdefs.c
@link
*@c1.ccl
