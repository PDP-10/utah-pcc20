! <SUBSYS.PCC>INIT.CMD.6, 14-May-83 15:04:38, Edit by BEEBE;
! Change system-dependenent directory names/logical names
! Define logical name SCRATCH: (required by compiler)
set no command-trace			!to be safe...
declare /noconfirm environment pcc:pcc-all.env
set string-variable pccfullcomp YES
set string-variable pcclink NO
set integer-variable pccflags 0
; INSTALLATION DEPENDENT:
set string-variable tempdir PS:<TEMP>
define SCRATCH: PS:<TEMP>
take
