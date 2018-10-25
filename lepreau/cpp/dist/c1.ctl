! File to recompile and rebuild Pass 1 of PCC compiler

@pcc cgram.c
@pcc clocal.c
@pcc code.c
@pcc comm1.c
@pcc local.c
@pcc optim.c
@pcc pftn.c
@pcc scan.c
@pcc trees.c
@pcc xdefs.c
@link
*@c1.ccl
