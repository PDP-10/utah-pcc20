/*****************************************************************************
     monerr.h - Created from monsym.mac by J.Lepreau, Univ. of Utah, 4/10/81

 Most recent edit history:
 ;PS:<4.SUBSYS-SOURCES>MONSYM.MAC.9 15-Mar-81 15:35:53, Edit by FRANK
 ;ADD .GOPLT AND .GOPRT AND .GOSPL (PLOT AND PRINT AND SPOOL)
 ;PS:<4.SUBSYS-SOURCES>MONSYM.MAC.6 12-Feb-81 19:08:13, Edit by FRANK
 ;ADD .GOATC FOR ATTACH
 ;PS:<4.SUBSYS-SOURCES>MONSYM.MAC.3  7-Oct-80 20:22:30, Edit by FRANK
 ;add SMAP jsys to monitor
 ;<4.UTILITIES>MONSYM.MAC.262,  3-Jan-80 15:26:07, EDIT BY R.ACE
 ;UPDATE COPYRIGHT DATE

******************************************************************************/
 
#define ERb 0600000		/* "Error base" */

#define ERlginx1 (ERb|010) /* Invalid account identifier */
#define ERlginx2 (ERb|011) /* Directory is "files-only" and cannot be logged in to */
#define ERlginx3 (ERb|012) /* Internal format of directory is incorrect */
#define ERlginx4 (ERb|013) /* Invalid password */
#define ERlginx5 (ERb|014) /* Job is already logged in */
#define ERcrjbx1 (ERb|020) /* Invalid parameter or function bit combination */
#define ERcrjbx2 (ERb|021) /* Illegal for created job to enter MINI-EXEC */
#define ERcrjbx3 (ERb|022) /* Reserved */
#define ERcrjbx4 (ERb|023) /* Terminal is not available */
#define ERcrjbx5 (ERb|024) /* Unknown name for LOGIN */
#define ERcrjbx6 (ERb|025) /* Insufficient system resources */
#define ERcrjbx7 (ERb|026) /* Reserved */
#define ERloutx1 (ERb|035) /* Illegal to specify job number when logging out own job */
#define ERloutx2 (ERb|036) /* Invalid job number */
#define ERcactx1 (ERb|045) /* Invalid account identifier */
#define ERcactx2 (ERb|046) /* Job is not logged in */
#define ERefctx1 (ERb|050) /* WHEEL or OPERATOR capability required */
#define ERefctx2 (ERb|051) /* Entry cannot be longer than 64 words */
#define ERefctx3 (ERb|052) /* Fatal error when accessing FACT file */
#define ERgjfx1 (ERb|055) /* Desired JFN invalid */
#define ERgjfx2 (ERb|056) /* Desired JFN not available */
#define ERgjfx3 (ERb|057) /* No JFN available */
#define ERgjfx4 (ERb|060) /* Invalid character in filename */
#define ERgjfx5 (ERb|061) /* Field cannot be longer than 39 characters */
#define ERgjfx6 (ERb|062) /* Device field not in a valid position */
#define ERgjfx7 (ERb|063) /* Directory field not in a valid position */
#define ERgjfx8 (ERb|064) /* Directory terminating delimiter is not preceded by a valid beginning delimiter */
#define ERgjfx9 (ERb|065) /* More than one name field is not allowed */
#define ERgjfx10 (ERb|066) /* Generation number is not numeric */
#define ERgjfx11 (ERb|067) /* More than one generation number field is not allowed */
#define ERgjfx12 (ERb|070) /* More than one account field is not allowed */
#define ERgjfx13 (ERb|071) /* More than one protection field is not allowed */
#define ERgjfx14 (ERb|072) /* Invalid protection */
#define ERgjfx15 (ERb|073) /* Invalid confirmation character */
#define ERgjfx16 (ERb|074) /* No such device */
#define ERgjfx17 (ERb|075) /* No such directory name */
#define ERgjfx18 (ERb|076) /* No such filename */
#define ERgjfx19 (ERb|077) /* No such file type */
#define ERgjfx20 (ERb|0100) /* No such generation number */
#define ERgjfx21 (ERb|0101) /* File was expunged */
#define ERgjfx22 (ERb|0102) /* Insufficient system resources (Job Storage Block full) */
#define ERgjfx23 (ERb|0103) /* Exceeded maximum number of files per directory */
#define ERgjfx24 (ERb|0104) /* File not found */
#define ERgjfx27 (ERb|0107) /* File already exists (new file required) */
#define ERgjfx28 (ERb|0110) /* Device is not on line */
#define ERgjfx29 (ERb|0111) /* Device is not available to this job */
#define ERgjfx30 (ERb|0112) /* Account is not numeric */
#define ERgjfx31 (ERb|0113) /* Invalid wildcard designator */
#define ERgjfx32 (ERb|0114) /* No files match this specification */
#define ERgjfx33 (ERb|0115) /* Filename was not specified */
#define ERgjfx34 (ERb|0116) /* Invalid character "?" in file specification */
#define ERgjfx35 (ERb|0117) /* Directory access privileges required */
#define ERopnx1 (ERb|0120) /* File is already open */
#define ERopnx2 (ERb|0121) /* File does not exist */
#define ERopnx3 (ERb|0122) /* Read access required */
#define ERopnx4 (ERb|0123) /* Write access required */
#define ERopnx5 (ERb|0124) /* Execute access required */
#define ERopnx6 (ERb|0125) /* Append access required */
#define ERopnx7 (ERb|0126) /* Device already assigned to another job */
#define ERopnx8 (ERb|0127) /* Device is not on line */
#define ERopnx9 (ERb|0130) /* Invalid simultaneous access */
#define ERopnx10 (ERb|0131) /* Entire file structure full */
#define ERopnx12 (ERb|0133) /* List access required */
#define ERopnx13 (ERb|0134) /* Invalid access requested */
#define ERopnx14 (ERb|0135) /* Invalid mode requested */
#define ERopnx15 (ERb|0136) /* Read/write access required */
#define ERopnx16 (ERb|0137) /* File has bad index block */
#define ERopnx17 (ERb|0140) /* No room in job for long file page table */
#define ERopnx18 (ERb|0141) /* Unit Record Devices are not available */
#define ERopnx19 (ERb|0142) /* IMP is not up */ ;TOPS20AN
#define ERopnx20 (ERb|0143) /* Host is not up */ ;TOPS20AN
#define ERopnx21 (ERb|0144) /* Connection refused */ ;TOPS20AN
#define ERopnx22 (ERb|0145) /* Connection byte size does not match */ ;TOPS20AN
#define ERdesx1 (ERb|0150) /* Invalid source/destination designator */
#define ERdesx2 (ERb|0151) /* Terminal is not available to this job */
#define ERdesx3 (ERb|0152) /* JFN is not assigned */
#define ERdesx4 (ERb|0153) /* Invalid use of terminal designator or string pointer */
#define ERdesx5 (ERb|0154) /* File is not open */
#define ERdesx6 (ERb|0155) /* Device is not a terminal */
#define ERdesx7 (ERb|0156) /* JFN cannot refer to output wildcard designators */
#define ERdesx8 (ERb|0157) /* File is not on disk */
#define ERclsx1 (ERb|0160) /* File is not open */
#define ERclsx2 (ERb|0161) /* File cannot be closed by this process */
#define ERrjfnx1 (ERb|0165) /* File is not closed */
#define ERrjfnx2 (ERb|0166) /* JFN is being used to accumulate filename */
#define ERrjfnx3 (ERb|0167) /* JFN is not accessible by this process */
#define ERdelfx1 (ERb|0170) /* Delete access required */
#define ERsfptx1 (ERb|0175) /* File is not open */
#define ERsfptx2 (ERb|0176) /* Illegal to reset pointer for this file */
#define ERsfptx3 (ERb|0177) /* Invalid byte number */
#define ERcndix1 (ERb|0200) /* Invalid password */
#define ERcndix3 (ERb|0202) /* Invalid directory number */
#define ERcndix5 (ERb|0204) /* Job is not logged in */
#define ERsfbsx1 (ERb|0210) /* Illegal to change byte size for this opening of file */
#define ERsfbsx2 (ERb|0211) /* Invalid byte size */
#define ERiox1 (ERb|0215) /* File is not opened for reading */
#define ERiox2 (ERb|0216) /* File is not opened for writing */
#define ERiox3 (ERb|0217) /* File is not open for random access */
#define ERiox4 (ERb|0220) /* End of file reached */
#define ERiox5 (ERb|0221) /* Device or data error */
#define ERiox6 (ERb|0222) /* Illegal to write beyond absolute end of file */
#define ERpmapx1 (ERb|0240) /* Invalid access requested */
#define ERpmapx2 (ERb|0241) /* Invalid use of PMAP */
#define ERspacx1 (ERb|0245) /* Invalid access requested */
#define ERfrkhx1 (ERb|0250) /* Invalid process handle */
#define ERfrkhx2 (ERb|0251) /* Illegal to manipulate a superior process */
#define ERfrkhx3 (ERb|0252) /* Invalid use of multiple process handle */
#define ERfrkhx4 (ERb|0253) /* Process is running */
#define ERfrkhx5 (ERb|0254) /* Process has not been started */
#define ERfrkhx6 (ERb|0255) /* All relative process handles in use */
#define ERsplfx1 (ERb|0260) /* Process is not inferior or equal to self */
#define ERsplfx2 (ERb|0261) /* Process is not inferior to self */
#define ERsplfx3 (ERb|0262) /* New superior process is inferior to intended inferior */
#define ERgtabx1 (ERb|0267) /* Invalid table number */
#define ERgtabx2 (ERb|0270) /* Invalid table index */
#define ERgtabx3 (ERb|0271) /* GETAB capability required */
#define ERruntx1 (ERb|0273) /* Invalid process handle -3 or -4 */
#define ERstadx1 (ERb|0275) /* WHEEL or OPERATOR capability required */
#define ERstadx2 (ERb|0276) /* Invalid date or time */
#define ERasndx1 (ERb|0300) /* Device is not assignable */
#define ERasndx2 (ERb|0301) /* Illegal to assign this device  */
#define ERasndx3 (ERb|0302) /* No such device */
#define ERatacx1 (ERb|0320) /* Invalid job number */
#define ERatacx2 (ERb|0321) /* Job already attached */
#define ERatacx3 (ERb|0322) /* Incorrect user number */
#define ERatacx4 (ERb|0323) /* Invalid password */
#define ERatacx5 (ERb|0324) /* This job has no controlling terminal */
#define ERstdvx1 (ERb|0332) /* No such device */
#define ERdevx1 (ERb|0335) /* Invalid device designator */
#define ERdevx2 (ERb|0336) /* Device already assigned to another job */
#define ERdevx3 (ERb|0337) /* Device is not on line */
#define ERmntx1 (ERb|0345) /* Internal format of directory is incorrect */
#define ERmntx2 (ERb|0346) /* Device is not on line */
#define ERmntx3 (ERb|0347) /* Device is not mountable */
#define ERtermx1 (ERb|0350) /* Invalid terminal code */
#define ERtlnkx1 (ERb|0351) /* Illegal to set remote to object before object to remote */
#define ERatix1 (ERb|0352) /* Invalid software interrupt channel number */
#define ERatix2 (ERb|0353) /* Control-C capability required */
#define ERtlnkx2 (ERb|0356) /* Link was not received within 15 seconds */
#define ERtlnkx3 (ERb|0357) /* Links full */
#define ERttyx1 (ERb|0360) /* Device is not a terminal */
#define ERrscnx1 (ERb|0361) /* Overflowed rescan buffer, input string truncated */
#define ERrscnx2 (ERb|0362) /* Invalid function code */
#define ERcfrkx3 (ERb|0363) /* Insufficient system resources */
#define ERkfrkx1 (ERb|0365) /* Illegal to kill top level process */
#define ERkfrkx2 (ERb|0366) /* Illegal to kill self */
#define ERrfrkx1 (ERb|0367) /* Processes are not frozen */
#define ERhfrkx1 (ERb|0370) /* Illegal to halt self with HFORK */
#define ERgfrkx1 (ERb|0371) /* Invalid process handle */
#define ERgetx1 (ERb|0373) /* Invalid save file format */
#define ERgetx2 (ERb|0374) /* System Special Pages Table full */
#define ERtfrkx1 (ERb|0375) /* Undefined function code */
#define ERtfrkx2 (ERb|0376) /* Unassigned fork handle or not immediate inferior */
#define ERsfrvx1 (ERb|0377) /* Invalid position in entry vector */
#define ERnoutx1 (ERb|0407) /* Radix is not in range 2 to 36  */
#define ERnoutx2 (ERb|0410) /* Column overflow */
#define ERtfrkx3 (ERb|0411) /* Fork(s) not frozen */
#define ERifixx1 (ERb|0414) /* Radix is not in range 2 to 10 */
#define ERifixx2 (ERb|0415) /* First nonspace character is not a digit */
#define ERifixx3 (ERb|0416) /* Overflow (number is greater than 2**35 ) */
#define ERgfdbx1 (ERb|0424) /* Invalid displacement */
#define ERgfdbx2 (ERb|0425) /* Invalid number of words */
#define ERgfdbx3 (ERb|0426) /* List access required */
#define ERcfdbx1 (ERb|0430) /* Invalid displacement */
#define ERcfdbx2 (ERb|0431) /* Illegal to change specified bits */
#define ERcfdbx3 (ERb|0432) /* Write or owner access required */
#define ERcfdbx4 (ERb|0433) /* Invalid value for specified bits */
#define ERdumpx1 (ERb|0440) /* Command list error */
#define ERdumpx2 (ERb|0441) /* JFN is not open in dump mode */
#define ERdumpx3 (ERb|0442) /* Address error (too big or crosses end of memory) */
#define ERdumpx4 (ERb|0443) /* Access error (cannot read or write data in memory) */
#define ERrnamx1 (ERb|0450) /* Files are not on same device */
#define ERrnamx2 (ERb|0451) /* Destination file expunged */
#define ERrnamx3 (ERb|0452) /* Write or owner access to destination file required */
#define ERrnamx4 (ERb|0453) /* Quota exceeded in destination of rename */
#define ERbkjfx1 (ERb|0454) /* Illegal to back up terminal pointer twice */
#define ERtimex1 (ERb|0460) /* Time cannot be greater than 24 hours */
#define ERzonex1 (ERb|0461) /* Time zone out of range */
#define ERodtnx1 (ERb|0462) /* Time zone must be USA or Greenwich */
#define ERdilfx1 (ERb|0464) /* Invalid date format */
#define ERtilfx1 (ERb|0465) /* Invalid time format */
#define ERdatex1 (ERb|0466) /* Year out of range */
#define ERdatex2 (ERb|0467) /* Month is not less than 12 */
#define ERdatex3 (ERb|0470) /* Day of month too large */
#define ERdatex4 (ERb|0471) /* Day of week is not less than 7 */
#define ERdatex5 (ERb|0472) /* Date out of range */
#define ERdatex6 (ERb|0473) /* System date and time are not set */
#define ERsmonx1 (ERb|0516) /* WHEEL or OPERATOR capability required */
#define ERsactx1 (ERb|0530) /* File is not on multiple-directory device */
#define ERsactx2 (ERb|0531) /* Insufficient system resources (Job Storage Block full) */
#define ERsactx3 (ERb|0532) /* Directory requires numeric account */
#define ERsactx4 (ERb|0533) /* Write or owner access required */
#define ERgactx1 (ERb|0540) /* File is not on multiple-directory device */
#define ERgactx2 (ERb|0541) /* File expunged */
#define ERffufx1 (ERb|0544) /* File is not open */
#define ERffufx2 (ERb|0545) /* File is not on multiple-directory device */
#define ERffufx3 (ERb|0546) /* No used page found */
#define ERdsmx1 (ERb|0555) /* File(s) not closed */
#define ERrddix1 (ERb|0560) /* Illegal to read directory for this device */
#define ERsirx1 (ERb|0570) /* Table address is not greater than 20 */
#define ERssavx1 (ERb|0600) /* Illegal to save files on this device */
#define ERssavx2 (ERb|0601) /* Page count is not less than or equal to 1000 */
#define ERsevex1 (ERb|0610) /* Entry vector is not less than 1000 */
#define ERwhelx1 (ERb|0614) /* WHEEL or OPERATOR capability required */
#define ERcapx1 (ERb|0615) /* WHEEL or OPERATOR capability required */
#define ERpeekx2 (ERb|0617) /* Read access failure on monitor page */
#define ERcrdix1 (ERb|0620) /* WHEEL or OPERATOR capability required */
#define ERcrdix2 (ERb|0621) /* Illegal to change number of old directory */
#define ERcrdix3 (ERb|0622) /* Insufficient system resources (Job Storage Block full) */
#define ERcrdix4 (ERb|0623) /* Superior directory full */
#define ERcrdix5 (ERb|0624) /* Directory name not given */
#define ERcrdix7 (ERb|0626) /* File(s) open in directory */
#define ERgtdix1 (ERb|0640) /* WHEEL or OPERATOR capability required */
#define ERgtdix2 (ERb|0641) /* Invalid directory number */
#define ERflinx1 (ERb|0650) /* First character is not blank or numeric */
#define ERflinx2 (ERb|0651) /* Number too small */
#define ERflinx3 (ERb|0652) /* Number too large */
#define ERflinx4 (ERb|0653) /* Invalid format */
#define ERflotx1 (ERb|0660) /* Column overflow in field 1 or 2 */
#define ERflotx2 (ERb|0661) /* Column overflow in field 3 */
#define ERflotx3 (ERb|0662) /* Invalid format specified */
#define ERhptx1 (ERb|0670) /* Undefined clock number */
#define ERfdfrx1 (ERb|0700) /* Not a multiple-directory device */
#define ERfdfrx2 (ERb|0701) /* Invalid directory number */
#define ERgthsx1 (ERb|0704) /* Unknown host number *//* ;TOPS20AN */
#define ERgthsx2 (ERb|0705) /* No number for that host name *//* ;TOPS20AN */
#define ERgthsx3 (ERb|0707) /* No string for that Host number *//* ;TOPS20AN */
#define ERatnx1 (ERb|0710) /* Invalid receive JFN *//* ;TOPS20AN */
#define ERatnx2 (ERb|0711) /* Receive JFN not opened for read *//* ;TOPS20AN */
#define ERatnx3 (ERb|0712) /* Receive JFN not open *//* ;TOPS20AN */
#define ERatnx4 (ERb|0713) /* Receive JFN is not a NET connection *//* ;TOPS20AN */
#define ERatnx5 (ERb|0714) /* Receive JFN has been used *//* ;TOPS20AN */
#define ERatnx6 (ERb|0715) /* Receive connection refused *//* ;TOPS20AN */
#define ERatnx7 (ERb|0716) /* Invalid send JFN *//* ;TOPS20AN */
#define ERatnx8 (ERb|0717) /* Send JFN not opened for write *//* ;TOPS20AN */
#define ERatnx9 (ERb|0720) /* Send JFN not open *//* ;TOPS20AN */
#define ERatnx10 (ERb|0721) /* Send JFN is not a NET connection *//* ;TOPS20AN */
#define ERatnx11 (ERb|0722) /* Send JFN has been used *//* ;TOPS20AN */
#define ERatnx12 (ERb|0723) /* Send connection refused *//* ;TOPS20AN */
#define ERatnx13 (ERb|0724) /* Insufficient system resources (No NVT's) *//* ;TOPS20AN */
#define ERcvhst1 (ERb|0727) /* No string for that Host number *//* ;TOPS20AN */
#define ERcvskx1 (ERb|0730) /* Invalid network JFN *//* ;TOPS20AN */
#define ERcvskx2 (ERb|0731) /* Local socket invalid in this context *//* ;TOPS20AN */
#define ERsndix1 (ERb|0732) /* Invalid message size *//* ;TOPS20AN */
#define ERsndix2 (ERb|0733) /* Insufficient system resources (No buffers available) *//* ;TOPS20AN */
#define ERsndix3 (ERb|0734) /* Illegal to specify NCP links (ERb|0 - 72 *//* ;TOPS20AN */
#define ERsndix4 (ERb|0735) /* Invalid header value for this queue *//* ;TOPS20AN */
#define ERsndix5 (ERb|0736) /* IMP down *//* ;TOPS20AN */
#define ERntwzx1 (ERb|0737) /* NET WIZARD capability  required *//* ;TOPS20AN */
#define ERasnsx1 (ERb|0740) /* Insufficient system resources (All special queues in use) *//* ;TOPS20AN */
#define ERasnsx2 (ERb|0741) /* Link(s) assigned to another special queue *//* ;TOPS20AN */
#define ERsqx1 (ERb|0742) /* Special network queue handle out of range *//* ;TOPS20AN */
#define ERsqx2 (ERb|0743) /* Special network queue not assigned *//* ;TOPS20AN */
#define ERgtncx1 (ERb|0746) /* Invalid network JFN *//* ;TOPS20AN */
#define ERgtncx2 (ERb|0747) /* Invalid or inactive NVT *//* ;TOPS20AN */
#define ERrnamx5 (ERb|0750) /* Destination file is not closed */
#define ERrnamx6 (ERb|0751) /* Destination file has bad page table */
#define ERrnamx7 (ERb|0752) /* Source file expunged */
#define ERrnamx8 (ERb|0753) /* Write or owner access to source file required */
#define ERrnamx9 (ERb|0754) /* Source file is nonexistent */
#define ERrnmx10 (ERb|0755) /* Source file is not closed */
#define ERrnmx11 (ERb|0756) /* Source file has bad page table */
#define ERrnmx12 (ERb|0757) /* Illegal to rename to self */
#define ERgjfx36 (ERb|0760) /* Internal format of directory is incorrect */
#define ERilins1 (ERb|0770) /* Undefined operation code */
#define ERilins2 (ERb|0771) /* Undefined JSYS */
#define ERilins3 (ERb|0772) /* UUO simulation facility not available */
#define ERcrlnx1 (ERb|01000) /* Logical name is not defined */
#define ERinlnx1 (ERb|01001) /* Index is beyond end of logical name table */
#define ERlnstx1 (ERb|01002) /* No such logical name */
#define ERmlkbx1 (ERb|01003) /* Lock facility already in use */
#define ERmlkbx2 (ERb|01004) /* Too many pages to be locked */
#define ERmlkbx3 (ERb|01005) /* Page is not available */
#define ERmlkbx4 (ERb|01006) /* Illegal to remove previous contents of user map */
#define ERvbcx1 (ERb|01007) /* Display data area not locked in core */
#define ERrdtx1 (ERb|01010) /* Invalid string pointer */
#define ERgfksx1 (ERb|01011) /* Area too small to hold process structure */
#define ERgtjix1 (ERb|01013) /* Invalid index */
#define ERgtjix2 (ERb|01014) /* Invalid terminal line number */
#define ERgtjix3 (ERb|01015) /* Invalid job number */
#define ERipcfx1 (ERb|01016) /* Length of packet descriptor block cannot be less than 4 */
#define ERipcfx2 (ERb|01017) /* No message for this PID */
#define ERipcfx3 (ERb|01020) /* Data too long for user's buffer */
#define ERipcfx4 (ERb|01021) /* Receiver's PID invalid */
#define ERipcfx5 (ERb|01022) /* Receiver's PID disabled */
#define ERipcfx6 (ERb|01023) /* Send quota exceeded */
#define ERipcfx7 (ERb|01024) /* Receiver quota exceeded */
#define ERipcfx8 (ERb|01025) /* IPCF free space exhausted */
#define ERipcfx9 (ERb|01026) /* Sender's PID invalid */
#define ERipcf10 (ERb|01027) /* WHEEL capability required */
#define ERipcf11 (ERb|01030) /* WHEEL or IPCF capability required */
#define ERipcf12 (ERb|01031) /* No free PID's available */
#define ERipcf13 (ERb|01032) /* PID quota exceeded */
#define ERipcf14 (ERb|01033) /* No PID's available to this job */
#define ERipcf15 (ERb|01034) /* No PID's available to this process */
#define ERipcf16 (ERb|01035) /* Receive and message data modes do not match */
#define ERipcf17 (ERb|01036) /* Argument block too small */
#define ERipcf18 (ERb|01037) /* Invalid MUTIL JSYS function */
#define ERipcf19 (ERb|01040) /* No PID for [SYSTEM] INFO */
#define ERipcf20 (ERb|01041) /* Invalid process handle */
#define ERipcf21 (ERb|01042) /* Invalid job number */
#define ERipcf22 (ERb|01043) /* Invalid software interrupt channel number */
#define ERipcf23 (ERb|01044) /* [SYSTEM] INFO already exists */
#define ERipcf24 (ERb|01045) /* Invalid message size */
#define ERipcf25 (ERb|01046) /* PID does not belong to this job */
#define ERipcf26 (ERb|01047) /* PID does not belong to this process */
#define ERipcf27 (ERb|01050) /* PID is not defined */
#define ERipcf28 (ERb|01051) /* PID not accessible by this process */
#define ERipcf29 (ERb|01052) /* PID already being used by another process */
#define ERipcf30 (ERb|01053) /* Job is not logged in */
#define ERgnjfx1 (ERb|01054) /* No more files in this specification */
#define ERenqx1 (ERb|01055) /* Invalid function */
#define ERenqx2 (ERb|01056) /* Level number too small */
#define ERenqx3 (ERb|01057) /* Request and lock level numbers do not match */
#define ERenqx4 (ERb|01060) /* Number of pool and lock resources do not match */
#define ERenqx5 (ERb|01061) /* Lock already requested */
#define ERenqx6 (ERb|01062) /* Requested locks are not all locked */
#define ERenqx7 (ERb|01063) /* No ENQ on this lock */
#define ERenqx8 (ERb|01064) /* Invalid access change requested */
#define ERenqx9 (ERb|01065) /* Invalid number of blocks specified */
#define ERenqx10 (ERb|01066) /* Invalid argument block length */
#define ERenqx11 (ERb|01067) /* Invalid software interrupt channel number */
#define ERenqx12 (ERb|01070) /* Invalid number of resources requested */
#define ERenqx13 (ERb|01071) /* Indirect or indexed byte pointer not allowed */
#define ERenqx14 (ERb|01072) /* Invalid byte size */
#define ERenqx15 (ERb|01073) /* ENQ/DEQ capability required */
#define ERenqx16 (ERb|01074) /* WHEEL or OPERATOR capability required */
#define ERenqx17 (ERb|01075) /* Invalid JFN */
#define ERenqx18 (ERb|01076) /* Quota exceeded */
#define ERenqx19 (ERb|01077) /* String too long */
#define ERenqx20 (ERb|01100) /* Locked JFN cannot be closed */
#define ERenqx21 (ERb|01101) /* Job is not logged in */
#define ERipcf31 (ERb|01102) /* Invalid page number */
#define ERipcf32 (ERb|01103) /* Page is not private */
#define ERpmapx3 (ERb|01104) /* Illegal to move shared page into file */
#define ERpmapx4 (ERb|01105) /* Illegal to move file page into process */
#define ERpmapx5 (ERb|01106) /* Illegal to move special page into file */
#define ERpmapx6 (ERb|01107) /* Disk quota exceeded */
#define ERsnopx1 (ERb|01110) /* WHEEL or OPERATOR capability required */
#define ERsnopx2 (ERb|01111) /* Invalid function */
#define ERsnopx3 (ERb|01112) /* .SNPLC function must be first */
#define ERsnopx4 (ERb|01113) /* Only one .SNPLC function allowed */
#define ERsnopx5 (ERb|01114) /* Invalid page number */
#define ERsnopx6 (ERb|01115) /* Invalid number of pages to lock */
#define ERsnopx7 (ERb|01116) /* Illegal to define breakpoints after inserting them */
#define ERsnopx8 (ERb|01117) /* Breakpoint is not set on instruction */
#define ERsnopx9 (ERb|01120) /* No more breakpoints allowed */
#define ERsnop10 (ERb|01121) /* Breakpoints already inserted */
#define ERsnop11 (ERb|01122) /* Breakpoints not inserted */
#define ERsnop12 (ERb|01123) /* Invalid format for program name symbol */
#define ERsnop13 (ERb|01124) /* No such program name symbol */
#define ERsnop14 (ERb|01125) /* No such symbol */
#define ERsnop15 (ERb|01126) /* Not enough free pages for snooping */
#define ERsnop16 (ERb|01127) /* Multiply defined symbol */
#define ERipcf33 (ERb|01130) /* Invalid index into system PID table */
#define ERsnop17 (ERb|01131) /* Breakpoint already defined */
#define ERopnx23 (ERb|01132) /* Disk quota exceeded */
#define ERgjfx37 (ERb|01133) /* Input deleted */
#define ERcrlnx2 (ERb|01134) /* WHEEL or OPERATOR capability required */
#define ERinlnx2 (ERb|01135) /* Invalid function */
#define ERlnstx2 (ERb|01136) /* Invalid function */
#define ERalcx1 (ERb|01137) /* Invalid function */
#define ERalcx2 (ERb|01140) /* WHEEL or OPERATOR capability required */
#define ERalcx3 (ERb|01141) /* Device is not assignable */
#define ERalcx4 (ERb|01142) /* Invalid job number */
#define ERalcx5 (ERb|01143) /* Device already assigned to another job */
#define ERsplx1 (ERb|01144) /* Invalid function */
#define ERsplx2 (ERb|01145) /* Argument block too small */
#define ERsplx3 (ERb|01146) /* Invalid device designator */
#define ERsplx4 (ERb|01147) /* WHEEL or OPERATOR capability required */
#define ERsplx5 (ERb|01150) /* Illegal to specify (ERb|0 as generation number for first file */
#define ERclsx3 (ERb|01151) /* File still mapped */
#define ERcrlnx3 (ERb|01152) /* Invalid function */
#define ERalcx6 (ERb|01153) /* Device assigned to user job, but will be given to allocator when released */
#define ERckax1 (ERb|01154) /* Argument block too small */
#define ERckax2 (ERb|01155) /* Invalid directory number */
#define ERckax3 (ERb|01156) /* Invalid access code */
#define ERtimx1 (ERb|01157) /* Invalid function */
#define ERtimx2 (ERb|01160) /* Invalid process handle */
#define ERtimx3 (ERb|01161) /* Time limit already set */
#define ERtimx4 (ERb|01162) /* Illegal to clear time limit */
#define ERsnop18 (ERb|01163) /* Data page is not private or copy-on-write */
#define ERgjfx38 (ERb|01164) /* File not found because output-only device was specified */
#define ERgjfx39 (ERb|01165) /* Logical name loop detected */
#define ERcrdix8 (ERb|01166) /* Invalid directory number */
#define ERcrdix9 (ERb|01167) /* Internal format of directory is incorrect */
#define ERcrdi10 (ERb|01170) /* Maximum directory number exceede/*d;  index table needs expanding */ */
#define ERdeldx1 (ERb|01171) /* WHEEL or OPERATOR capability required */
#define ERdeldx2 (ERb|01172) /* Invalid directory number */
#define ERgactx3 (ERb|01173) /* Internal format of directory is incorrect */
#define ERdiagx1 (ERb|01174) /* Invalid function */
#define ERdiagx2 (ERb|01175) /* Device is not assigned */
#define ERdiagx3 (ERb|01176) /* Argument block too small */
#define ERdiagx4 (ERb|01177) /* Invalid device type */
#define ERdiagx5 (ERb|01200) /* WHEEL, OPERATOR, or MAINTENANCE capability required */
#define ERdiagx6 (ERb|01201) /* Invalid channel command list */
#define ERdiagx7 (ERb|01202) /* Illegal to do I/O across page boundary */
#define ERdiagx8 (ERb|01203) /* No such device */
#define ERdiagx9 (ERb|01204) /* Unit does not exist */
#define ERdiag10 (ERb|01205) /* Subunit does not exist */
#define ERsyex1 (ERb|01206) /* Unreasonable SYSERR block size */
#define ERsyex2 (ERb|01207) /* No buffer space available for SYSERR */
#define ERmtox1 (ERb|01210) /* Invalid function */
#define ERiox7 (ERb|01211) /* Insufficient system resources (Job Storage Block full) */
#define ERiox8 (ERb|01212) /* Monitor internal error */
#define ERmtox5 (ERb|01213) /* Invalid hardware data mode for magnetic tape */
#define ERdumpx5 (ERb|01214) /* No-wait dump mode not supported for this device */
#define ERdumpx6 (ERb|01215) /* Dump mode not supported for this device */
#define ERiox9 (ERb|01216) /* Function legal for sequential write only */
#define ERclsx4 (ERb|01217) /* Device still active */
#define ERmtox2 (ERb|01220) /* Record size was not set before I/O was done */
#define ERmtox3 (ERb|01221) /* Function not legal in dump mode */
#define ERmtox4 (ERb|01222) /* Invalid record size */
#define ERmtox6 (ERb|01223) /* Invalid magnetic tape density */
#define ERopnx25 (ERb|01224) /* Device is write locked */
#define ERgjfx40 (ERb|01225) /* Undefined attribute in file specification */
#define ERmtox7 (ERb|01226) /* WHEEL or OPERATOR capability required */
#define ERloutx3 (ERb|01227) /* WHEEL or OPERATOR capability required */
#define ERloutx4 (ERb|01230) /* LOG capability required */
#define ERcapx2 (ERb|01231) /* WHEEL, OPERATOR, or MAINTENANCE capability required */
#define ERssavx3 (ERb|01232) /* Insufficient system resources (Job Storage Block full) */
#define ERssavx4 (ERb|01233) /* Directory area of EXE file is more than one page */
#define ERtdelx1 (ERb|01234) /* Table is empty */
#define ERtaddx1 (ERb|01235) /* Table is full */
#define ERtaddx2 (ERb|01236) /* Entry is already in table */
#define ERtlukx1 (ERb|01237) /* Internal format of table is incorrect */
#define ERiox10 (ERb|01240) /* Record is longer than user requested */
#define ERcndix2 (ERb|01241) /* WHEEL or OPERATOR capability required */
#define ERcndix4 (ERb|01242) /* Invalid job number */
#define ERcndix6 (ERb|01243) /* Job is not logged in */
#define ERsjbx1 (ERb|01244) /* Invalid function */
#define ERsjbx2 (ERb|01245) /* Invalid magnetic tape density */
#define ERsjbx3 (ERb|01246) /* Invalid magnetic tape data mode */
#define ERtmonx1 (ERb|01247) /* Invalid TMON function */
#define ERsmonx2 (ERb|01250) /* Invalid SMON function */
#define ERsjbx4 (ERb|01251) /* Invalid job number */
#define ERsjbx5 (ERb|01252) /* Job is not logged in */
#define ERsjbx6 (ERb|01253) /* WHEEL or OPERATOR capability required */
#define ERgtjix4 (ERb|01254) /* No such job */
#define ERilins4 (ERb|01255) /* UUO simulation is disabled */
#define ERilins5 (ERb|01256) /* RMS facility is not available */
#define ERcomnx1 (ERb|01257) /* Invalid COMND function code */
#define ERcomnx2 (ERb|01260) /* Field too long for internal buffer */
#define ERcomnx3 (ERb|01261) /* Command too long for internal buffer */
#define ERcomnx4 (ERb|01262) /* Invalid character in input */
#define ERprax1 (ERb|01263) /* Invalid PRARG function code */
#define ERprax2 (ERb|01264) /* No room in monitor data base for argument block */
#define ERcomnx5 (ERb|01265) /* Invalid string pointer argument */
#define ERcomnx6 (ERb|01266) /* Problem in indirect file */
#define ERcomnx7 (ERb|01267) /* Error in command */
#define ERprax3 (ERb|01270) /* PRARG argument block too large */
#define ERckax4 (ERb|01271) /* File is not on disk */
#define ERgaccx1 (ERb|01272) /* Invalid job number */
#define ERgaccx2 (ERb|01273) /* No such job */
#define ERmtox8 (ERb|01274) /* Argument block too long */
#define ERdbrkx1 (ERb|01275) /* No interrupts in progress */
#define ERsjprx1 (ERb|01276) /* Job is not logged in */
#define ERgjfx41 (ERb|01277) /* File name must not exceed 6 characters */
#define ERgjfx42 (ERb|01300) /* File type must not exceed 3 characters */
#define ERgaccx3 (ERb|01301) /* Confidential Information Access capability required */
#define ERtimex2 (ERb|01302) /* Downtime cannot be more than 7 days in the future */
#define ERdelfx2 (ERb|01303) /* File cannot be expunged because it is currently open */
#define ERdelfx3 (ERb|01304) /* System scratch area depleted; file not deleted */
#define ERdelfx4 (ERb|01305) /* Directory symbol table could not be rebuilt */
#define ERdelfx5 (ERb|01306) /* Directory symbol table needs rebuilding */
#define ERdelfx6 (ERb|01307) /* Internal format of directory is incorrect */
#define ERdelfx7 (ERb|01310) /* FDB formatted incorrectly; file not deleted */
#define ERdelfx8 (ERb|01311) /* FDB not found; file not deleted */
#define ERfrkhx7 (ERb|01312) /* Process page cannot exceed 777 */
#define ERdirx1 (ERb|01313) /* Invalid directory number */
#define ERdirx2 (ERb|01314) /* Insufficient system resources */
#define ERdirx3 (ERb|01315) /* Internal format of directory is incorrect */
#define ERufpgx1 (ERb|01316) /* File is not open for write */
#define ERlngfx1 (ERb|01317) /* Page table does not exist and file not open for write */
#define ERipcf34 (ERb|01320) /* Cannot receive into an existing page */
#define ERcomnx8 (ERb|01321) /* Number base out of range 2-10 */
#define ERmtox9 (ERb|01322) /* Output still pending */
#define ERmtox10 (ERb|01323) /* VFU or RAM file cannot be OPENed */
#define ERmtox11 (ERb|01324) /* Data too large for buffers */
#define ERmtox12 (ERb|01325) /* Input error or not all data read */
#define ERmtox13 (ERb|01326) /* Argument block too small */
#define ERmtox14 (ERb|01327) /* Invalid software interrupt channel number */
#define ERsavx1 (ERb|01330) /* Illegal to save files on this device */
#define ERmtox15 (ERb|01331) /* Device does not have Direct Access (programmable) VFU */
#define ERmtox16 (ERb|01332) /* VFU or Translation Ram file must be on disk */
#define ERlpinx1 (ERb|01333) /* Invalid unit number */
#define ERlpinx2 (ERb|01334) /* WHEEL or OPERATOR capability required */
#define ERlpinx3 (ERb|01335) /* Illegal to load RAM or VFU while device is OPEN */
#define ERmtox17 (ERb|01336) /* Device is not on line */
#define ERlginx6 (ERb|01337) /* No more job slots available for logging-in */
#define ERdesx9 (ERb|01340) /* Invalid operation for this device */
#define ERacesx1 (ERb|01341) /* Argument block too small */
#define ERacesx2 (ERb|01342) /* Insufficient system resources */
#define ERdskox1 (ERb|01343) /* Channel number too large */
#define ERdskox2 (ERb|01344) /* Unit number too large */
#define ERmstrx1 (ERb|01345) /* Invalid function */
#define ERmstrx2 (ERb|01346) /* WHEEL or OPERATOR capability required */
#define ERmstrx3 (ERb|01347) /* Argument block too small */
#define ERmstrx4 (ERb|01350) /* Insufficient system resources */
#define ERmstrx5 (ERb|01351) /* Drive is not on-line */
#define ERmstrx6 (ERb|01352) /* Home blocks are bad */
#define ERmstrx7 (ERb|01353) /* Invalid structure name */
#define ERmstrx8 (ERb|01354) /* Could not get OFN for ROOT-DIRECTORY */
#define ERmstrx9 (ERb|01355) /* Could not MAP ROOT-DIRECTORY */
#define ERmstx10 (ERb|01356) /* ROOT-DIRECTORY bad */
#define ERmstx11 (ERb|01357) /* Could not initialize Index Table */
#define ERmstx12 (ERb|01360) /* Could not OPEN Bit Table File */
#define ERmstx13 (ERb|01361) /* Backup copy of ROOT-DIRECTORY is bad */
#define ERmstx14 (ERb|01362) /* Invalid channel number */
#define ERmstx15 (ERb|01363) /* Invalid unit number */
#define ERmstx16 (ERb|01364) /* Invalid controller number */
#define ERdskx01 (ERb|01365) /* Invalid structure number */
#define ERdskx02 (ERb|01366) /* Bit table is being initialized */
#define ERdskx03 (ERb|01367) /* Bit table has not been initialized */
#define ERdskx04 (ERb|01370) /* Bit table being initialized by another job */
#define ERgfusx1 (ERb|01371) /* Invalid function */
#define ERgfusx2 (ERb|01372) /* Insufficient system resources */
#define ERsfusx1 (ERb|01373) /* Invalid function */
#define ERsfusx2 (ERb|01374) /* Insufficient system resources */
#define ERsfusx3 (ERb|01375) /* No such user name */
#define ERrcdix1 (ERb|01376) /* Insufficient system resources */
#define ERrcdix2 (ERb|01377) /* Invalid directory specification */
#define ERrcdix3 (ERb|01400) /* Invalid structure name */
#define ERrcdix4 (ERb|01401) /* Monitor internal error */
#define ERrcusx1 (ERb|01402) /* Insufficient system resources */
#define ERtdelx2 (ERb|01403) /* Invalid table entry location */
#define ERtimx5 (ERb|01404) /* Invalid software interrupt channel number */
#define ERlstrx1 (ERb|01405) /* Process has not encountered any errors */
#define ERswjfx1 (ERb|01406) /* Illegal to swap same JFN */
#define ERmtox18 (ERb|01407) /* Invalid software interrupt channel number */
#define ERopnx26 (ERb|01410) /* Illegal to open a string pointer */
#define ERdelfx9 (ERb|01411) /* File is not a directory file */
#define ERcrdix6 (ERb|01412) /* Directory file is mapped */
#define ERcomnx9 (ERb|01413) /* End of input file reached */
#define ERstypx1 (ERb|01414) /* Invalid terminal type */
#define ERpmapx7 (ERb|01415) /* Illegal to map file on dismounted structure */
#define ERdskox3 (ERb|01416) /* Invalid structure number */
#define ERdesx10 (ERb|01417) /* Structure is dismounted */
#define ERdskox4 (ERb|01420) /* Invalid address type specified */
#define ERmstx17 (ERb|01421) /* All units in a structure must be of the same type */
#define ERmstx18 (ERb|01422) /* No more units in system */
#define ERmstx19 (ERb|01423) /* Unit is already part of a mounted structure */
#define ERmstx20 (ERb|01424) /* Data error reading HOME blocks */
#define ERmstx21 (ERb|01425) /* Structure is not mounted */
#define ERmstx22 (ERb|01426) /* Illegal to change specified bits */
#define ERcrdi11 (ERb|01427) /* Invalid terminating bracket on directory */
#define ERmstx23 (ERb|01430) /* Could not write HOME blocks */
#define ERacesx3 (ERb|01431) /* Password is required */
#define ERacesx4 (ERb|01432) /* Function not allowed for another job */
#define ERacesx5 (ERb|01433) /* No function specified for ACCES */
#define ERstrx05 (ERb|01434) /* No such user name */
#define ERacesx6 (ERb|01435) /* Directory is not accessed */
#define ERstrx01 (ERb|01436) /* Structure is not mounted */
#define ERstrx02 (ERb|01437) /* Insufficient system resources */
#define ERiox11 (ERb|01440) /* Quota exceeded or disk full */
#define ERiox12 (ERb|01441) /* Insufficient system resources (Swapping space full) */
#define ERstrx03 (ERb|01442) /* No such directory name */
#define ERstrx04 (ERb|01443) /* Ambiguous directory specification */
#define ERppnx1 (ERb|01444) /* Invalid PPN */
#define ERppnx2 (ERb|01445) /* Structure is not mounted */
#define ERppnx3 (ERb|01446) /* Insufficient system resources */
#define ERppnx4 (ERb|01447) /* Invalid directory number */
#define ERsplx6 (ERb|01450) /* No directory to write spooled files into */
#define ERcrdi12 (ERb|01451) /* Structure is not mounted */
#define ERgfusx3 (ERb|01452) /* File expunged */
#define ERgfusx4 (ERb|01453) /* Internal format of directory is incorrect */
#define ERrnmx13 (ERb|01454) /* Insufficient system resources */
#define ERsjbx8 (ERb|01455) /* Illegal to perform this function */
#define ERdecrsv (ERb|01456) /* DEC reserved bits not zero */
#define ERffffx1 (ERb|01457) /* No free pages in file */
#define ERwildx1 (ERb|01460) /* Second JFN cannot be wild */

/*** ; ERROR 1461 CODES-1534 ARE AVAILABLE******/

#define ERtimx6 (ERb|01535) /* Time has already passed */
#define ERtimx7 (ERb|01536) /* No space available for a clock */
#define ERtimx8 (ERb|01537) /* User clock allocation exceeded */
#define ERtimx9 (ERb|01540) /* No such clock entry found */
#define ERtimx10 (ERb|01541) /* No system date and time */

#define ERsctx1 (ERb|01550) /* Invalid function code */
#define ERsctx2 (ERb|01551) /* Terminal already in use as controlling terminal */
#define ERsctx3 (ERb|01552) /* Illegal to redefine the job's controlling terminal */
#define ERsctx4 (ERb|01553) /* SC%SCT capability required */

/**** ; Error 1554 codes-1677 are available ******/

#define ERsfusx4 (ERb|01700) /* File expunged */
#define ERsfusx5 (ERb|01701) /* Write or owner access required */
#define ERsfusx6 (ERb|01702) /* No such user name */
#define ERgetx3 (ERb|01703) /* Illegal to overlay existing pages */
#define ERfilx01 (ERb|01704) /* File is not open */
#define ERargx01 (ERb|01705) /* Invalid password */
#define ERcapx3 (ERb|01706) /* WHEEL capability required */
#define ERcapx4 (ERb|01707) /* WHEEL or IPCF capability required */
#define ERcapx6 (ERb|01711) /* ENQ/DEQ capability required */
#define ERcapx7 (ERb|01712) /* Confidential Information Access Capability required */
#define ERargx02 (ERb|01713) /* Invalid function */
#define ERargx03 (ERb|01714) /* Illegal to change specified bits */
#define ERargx04 (ERb|01715) /* Argument block too small */
#define ERargx05 (ERb|01716) /* Argument block too long */
#define ERargx06 (ERb|01717) /* Invalid page number */
#define ERargx07 (ERb|01720) /* Invalid job number */
#define ERargx08 (ERb|01721) /* No such job */
#define ERargx09 (ERb|01722) /* Invalid byte size */
#define ERargx10 (ERb|01723) /* Invalid access requested */
#define ERargx11 (ERb|01724) /* Invalid directory number */
#define ERargx12 (ERb|01725) /* Invalid process handle */
#define ERargx13 (ERb|01726) /* Invalid software interrupt channel number */
#define ERmonx01 (ERb|01727) /* Insufficient system resources */
#define ERmonx02 (ERb|01730) /* Insufficient system resources (JSB full) */
#define ERmonx03 (ERb|01731) /* Monitor internal error */
#define ERmonx04 (ERb|01732) /* Insufficient system resources (Swapping space full) */
#define ERargx14 (ERb|01733) /* Invalid account identifier */
#define ERargx15 (ERb|01734) /* Job is not logged in */
#define ERfilx02 (ERb|01735) /* Write or owner access required */
#define ERfilx03 (ERb|01736) /* List access required */
#define ERdevx4 (ERb|01737) /* Device is not assignable */
#define ERfilx04 (ERb|01740) /* File is not on multiple-directory device */
#define ERargx16 (ERb|01741) /* Password is required */
#define ERargx17 (ERb|01742) /* Invalid argument block length */
#define ERargx18 (ERb|01743) /* Invalid structure name */
#define ERdevx5 (ERb|01744) /* No such device */
#define ERdirx4 (ERb|01745) /* Invalid directory specification */
#define ERfilx05 (ERb|01746) /* File expunged */
#define ERstrx06 (ERb|01747) /* No such user number */
#define ERmstx24 (ERb|01750) /* Illegal to dismount the Public Structure */
#define ERmstx25 (ERb|01751) /* Invalid number of swapping pages */
#define ERmstx26 (ERb|01752) /* Invalid number of Front-End-Filesystem pages */
#define ERloutx5 (ERb|01753) /* Illegal to log out job (ERb|0 */
#define ERgjfx43 (ERb|01754) /* More than one ;T specification is not allowed */
#define ERmtox19 (ERb|01755) /* Invalid terminal page width */
#define ERmtox20 (ERb|01756) /* Invalid terminal page length */
#define ERmstx27 (ERb|01757) /* Specified unit is not a disk */
#define ERmstx28 (ERb|01760) /* Could not initialize bit table for structure */
#define ERmstx29 (ERb|01761) /* Could not reconstruct ROOT-DIRECTORY */
#define ERdskx05 (ERb|01763) /* Disk assignments and deassignments are currently prohibited */
#define ERdskx06 (ERb|01764) /* Invalid disk address */
#define ERdskx07 (ERb|01765) /* Address cannot be deassigned because it is not assigned */
#define ERdskx08 (ERb|01766) /* Address cannot be assigned because it is already assigned */
#define ERcomx10 (ERb|01767) /* Invalid default string */
#define ERmstx30 (ERb|01770) /* Incorrect Bit Table counts on structure */
#define ERlockx1 (ERb|01771) /* Illegal to lock other than a private page */
#define ERlockx2 (ERb|01772) /* Requested page unavailable */
#define ERlockx3 (ERb|01773) /* Attempt to lock too much memory */
#define ERillx01 (ERb|01774) /* Illegal memory read */
#define ERillx02 (ERb|01775) /* Illegal memory write */
#define ERillx03 (ERb|01776) /* Memory data parity error  */
#define ERillx04 (ERb|01777) /* Reference to non-existent page */
#define ERmstx31 (ERb|02000) /* Structure already mounted */
#define ERmstx32 (ERb|02001) /* Structure was not mounted */
#define ERmstx33 (ERb|02002) /* Structure is unavailable for mounting */
#define ERstdix1 (ERb|02003) /* The STDIR JSYS has been replaced by RCDIR and RCUSR */
#define ERcndix7 (ERb|02004) /* The CNDIR JSYS has been replaced by ACCES */
#define ERpmclx1 (ERb|02005) /* Illegal page state or state transition */
#define ERpmclx2 (ERb|02006) /* Requested physical page is unavailable */
#define ERpmclx3 (ERb|02007) /* Requested physical page contains errors */
#define ERdlfx10 (ERb|02010) /* Cannot delete directory; file still mapped */
#define ERdlfx11 (ERb|02011) /* Cannot delete directory file in this manner */
#define ERgjfx44 (ERb|02012) /* Account string does not match */
#define ERutstx1 (ERb|02013) /* Invalid function code */
#define ERutstx2 (ERb|02014) /* Area of code too large to test */
#define ERutstx3 (ERb|02015) /* UTEST facility in use by another process */
#define ERbotx01 (ERb|02016) /* Invalid DTE-20 number */
#define ERbotx02 (ERb|02017) /* Invalid byte size */
#define ERdcnx1 (ERb|02020) /* Invalid network file name */
#define ERdcnx5 (ERb|02021) /* No more logical links available */
#define ERdcnx3 (ERb|02022) /* Invalid object */
#define ERdcnx4 (ERb|02023) /* Invalid task name */
#define ERdcnx9 (ERb|02024) /* Object is already defined */
#define ERdcnx8 (ERb|02025) /* Invalid network operation */
#define ERdcnx11 (ERb|02026) /* Link aborted */
#define ERdcnx12 (ERb|02027) /* String exceeds 16 bytes */
#define ERttyx01 (ERb|02030) /* Line is not active */
#define ERbotx03 (ERb|02031) /* Invalid protocol version number */
#define ERmonx05 (ERb|02032) /* Insufficient system resources (no resident free space) */
#define ERargx19 (ERb|02033) /* Invalid unit number */
#define ERcomx11 (ERb|02035) /* Invalid CMRTY pointer */
#define ERcomx12 (ERb|02036) /* Invalid CMBFP pointer */
#define ERcomx13 (ERb|02037) /* Invalid CMPTR pointer */
#define ERcomx14 (ERb|02040) /* Invalid CMABP pointer */
#define ERcomx15 (ERb|02041) /* Invalid default string pointer */
#define ERcomx16 (ERb|02042) /* Invalid help message pointer */
#define ERcomx17 (ERb|02043) /* Invalid byte pointer in function block */
#define ERnpxamb (ERb|02044) /* Ambiguous */
#define ERnpxnsw (ERb|02045) /* Not a switch - does not begin with slash */
#define ERnpxnom (ERb|02046) /* Does not match switch or keyword */
#define ERnpxnul (ERb|02047) /* Null switch or keyword given */
#define ERnpxinw (ERb|02050) /* Invalid guide word */
#define ERnpxnc (ERb|02051) /* Not confirmed */
#define ERnpxicn (ERb|02052) /* Invalid character in number */
#define ERnpxidt (ERb|02053) /* Invalid device terminator */
#define ERnpxnqs (ERb|02054) /* Not a quoted string - quote missing at beginning or end */
#define ERnpxnmt (ERb|02055) /* Does not match token */
#define ERnpxnmd (ERb|02056) /* Does not match directory or user name */
#define ERnpxcma (ERb|02057) /* Comma not given */
#define ERgjfx45 (ERb|02060) /* Illegal to request multiple specifications for the same attribute */
#define ERgjfx46 (ERb|02061) /* Attribute value is required */
#define ERgjfx47 (ERb|02062) /* Attribute does not take a value */
#define ERmstx34 (ERb|02063) /* Unit is write-locked */
#define ERgjfx48 (ERb|02064) /* GTJFN input buffer is empty */
#define ERgjfx49 (ERb|02065) /* Invalid attribute for this device */
#define ERsjbx7 (ERb|02077) /* Remark exceeds 39 characters */
#define ERdelf10 (ERb|02100) /* Directory still contains subdirectory */
#define ERcrdi13 (ERb|02101) /* Request exceeds superior directory working quota */
#define ERcrdi14 (ERb|02102) /* Request exceeds superior directory permanent quota */
#define ERcrdi15 (ERb|02103) /* Request exceeds superior directory subdirectory quota */
#define ERcrdi16 (ERb|02104) /* Invalid user group */
#define ERenacx1 (ERb|02105) /* Account validation data base file not completely closed */
#define ERenacx2 (ERb|02106) /* Cannot get a JFN for <SYSTEM>ACCOUNTS-TABLE.BIN */
#define ERenacx3 (ERb|02107) /* Account validation data base file too long */
#define ERenacx4 (ERb|02110) /* Cannot get an OFN for <SYSTEM>ACCOUNTS-TABLE.BIN */
#define ERvaccx0 (ERb|02111) /* Invalid account */
#define ERvaccx1 (ERb|02112) /* Account string exceeds 39 characters */
#define ERusgx01 (ERb|02113) /* Invalid USAGE entry type code */
#define ERbotx04 (ERb|02114) /* Byte count is not positive */
#define ERnodx01 (ERb|02115) /* Node name exceeds 6 characters */
#define ERusgx02 (ERb|02116) /* Item not found in argument list */
#define ERcrdi17 (ERb|02117) /* Illegal to create non-files-only subdirectory under files-only directory */
#define ERenqx23 (ERb|02120) /* Mismatched mask block lengths */
#define ERenqx22 (ERb|02121) /* Invalid mask block length */
#define ERdcnx2 (ERb|02122) /* Interrupt message must be read first */
#define ERabrkx1 (ERb|02123) /* Address break not available on this system */
#define ERusgx03 (ERb|02124) /* Default item not allowed */
#define ERipcf35 (ERb|02125) /* Invalid IPCF quota */
#define ERvaccx2 (ERb|02126) /* Account has expired */
#define ERcrdi18 (ERb|02127) /* Illegal to delete logged-in directory */
#define ERcrdi19 (ERb|02130) /* Illegal to delete connected directory */
#define ERbotx05 (ERb|02132) /* Protocol initialization failed */
#define ERcrdi20 (ERb|02133) /* WHEEL, OPERATOR, or requested capability required */
#define ERcomx18 (ERb|02134) /* Invalid character in node name */
#define ERcomx19 (ERb|02135) /* Too many characters in node name */
#define ERcrdi21 (ERb|02136) /* Working space insufficient for current allocation */
#define ERacesx7 (ERb|02137) /* Directory is "files-only" and cannot be accessed */
#define ERcrdi22 (ERb|02140) /* Subdirectory quota insufficient for existing subdirectories */
#define ERcrdi23 (ERb|02141) /* Superior directory does not exist */
#define ERstrx07 (ERb|02142) /* Invalid user number */
#define ERstrx08 (ERb|02143) /* Invalid user name */
#define ERcrdi24 (ERb|02144) /* Invalid subdirectory quota */
#define ERatsx01 (ERb|02146) /* Invalid mode */
#define ERatsx02 (ERb|02147) /* Illegal to declare mode twice */
#define ERatsx03 (ERb|02150) /* Illegal to declare mode after acquiring terminal */
#define ERatsx04 (ERb|02151) /* Invalid event code */
#define ERatsx05 (ERb|02152) /* Invalid function code for channel assignment */
#define ERatsx06 (ERb|02153) /* JFN is not an ATS JFN */
#define ERatsx07 (ERb|02154) /* Table length too small */
#define ERatsx08 (ERb|02155) /* Table lengths must be the same */
#define ERatsx09 (ERb|02156) /* Table length too large */
#define ERatsx10 (ERb|02157) /* Maximum applications terminals for system already assigned */
#define ERatsx11 (ERb|02160) /* Byte count is too large */
#define ERatsx12 (ERb|02161) /* Terminal not assigned to this JFN */
#define ERatsx13 (ERb|02162) /* Terminal is XOFF'd */
#define ERatsx14 (ERb|02163) /* Terminal has been released */
#define ERatsx15 (ERb|02164) /* Terminal identifier is not assigned */
#define ERpmclx4 (ERb|02165) /* No more error information */
#define ERatsx16 (ERb|02166) /* Invalid Host Terminal Number */
#define ERatsx17 (ERb|02167) /* Output failed -- monitor internal error */
#define ERfrkhx8 (ERb|02170) /* Illegal to manipulate an execute-only process */
#define ERargx20 (ERb|02171) /* Invalid arithmetic trap argument */
#define ERargx21 (ERb|02172) /* Invalid LUUO trap argument */
#define ERargx22 (ERb|02173) /* Invalid flags */
#define ERatsx18 (ERb|02174) /* ATS input message too long for internal buffers */
#define ERatsx19 (ERb|02175) /* Monitor internal error - ATS input message truncated */
#define ERatsx20 (ERb|02176) /* Illegal to close JFN with terminal assigned */
#define ERargx23 (ERb|02177) /* Invalid section number */
#define ERargx24 (ERb|02200) /* Invalid count */
#define ERmstx35 (ERb|02201) /* Too many units in structure */
#define ERdcnx13 (ERb|02202) /* Node not accessible */
#define ERdcnx14 (ERb|02203) /* Previous interrupt message outstanding */
#define ERdcnx15 (ERb|02204) /* No interrupt message available */
#define ERgjfx50 (ERb|02205) /* Invalid argument for attribute */
#define ERkdpx01 (ERb|02206) /* KMC11 not running */
#define ERnodx02 (ERb|02207) /* Line not turned off */
#define ERnodx03 (ERb|02210) /* Another line already looped */
#define ERgjfx51 (ERb|02211) /* Byte count too small */
#define ERcomx20 (ERb|02212) /* Invalid node name */
#define ERatsx21 (ERb|02213) /* Maximum applications terminals for job already assigned */
#define ERatsx22 (ERb|02214) /* Failed to acquire applications terminal */
#define ERatsx23 (ERb|02215) /* Invalid device name */
#define ERatsx24 (ERb|02216) /* Invalid server name */
#define ERatsx25 (ERb|02217) /* Terminal is already released */
#define ERgoker1 (ERb|02220) /* Illegal function */
#define ERgoker2 (ERb|02221) /* Request denied by Access Control Facility */
#define ERstrx09 (ERb|02222) /* Prior structure mount required */
#define ERmstx36 (ERb|02223) /* Illegal while JFNs assigned */
#define ERmstx37 (ERb|02224) /* Illegal while connected to structure */
#define ERmstx40 (ERb|02225) /* Invalid PSI channel number given */
#define ERatsx26 (ERb|02226) /* Invalid host name */
#define ERiox13 (ERb|02227) /* Invalid segment type */
#define ERiox14 (ERb|02230) /* Invalid segment size */
#define ERiox15 (ERb|02231) /* Illegal tape format for dump mode */
#define ERiox16 (ERb|02232) /* Density specified does not match tape density */
#define ERiox17 (ERb|02233) /* Invalid tape label */
#define ERiox20 (ERb|02234) /* Illegal tape record size */
#define ERiox21 (ERb|02235) /* Tape HDR1 missing */
#define ERiox22 (ERb|02236) /* Invalid tape HDR1 sequence number */
#define ERiox23 (ERb|02237) /* Tape label read error */
#define ERiox24 (ERb|02240) /* Logical end of tape encountered */
#define ERiox25 (ERb|02241) /* Invalid tape format */
#define ERswjfx2 (ERb|02242) /* Illegal to swap ATS JFN */
#define ERiox26 (ERb|02243) /* Tape write date has not expired */
#define ERiox27 (ERb|02244) /* Tape is domestic and HDR2 is missing */
#define ERiox30 (ERb|02245) /* Tape has invalid access character */
#define ERargx25 (ERb|02246) /* Invalid class */
#define ERskdx1 (ERb|02247) /* Cannot change class */
#define ERmreqx1 (ERb|02250) /* Request canceled by user */
#define ERmreqx2 (ERb|02251) /* Labeled tapes not permitted on 7-track drives */
#define ERmreqx3 (ERb|02252) /* Unknown density specified */
#define ERmreqx4 (ERb|02253) /* Unknown drive type specified */
#define ERmreqx5 (ERb|02254) /* Unknown label type specified */
#define ERmreqx6 (ERb|02255) /* Set name illegal or not specified */
#define ERmreqx7 (ERb|02256) /* Illegal starting-volume specification */
#define ERmreqx8 (ERb|02257) /* Attempt to switch to volume outside set */
#define ERmreqx9 (ERb|02260) /* Illegal volume identifier specified */
#define ERmreq10 (ERb|02261) /* Density mismatch between request and volume */
#define ERmreq11 (ERb|02262) /* Drive type mismatch between request and volume */
#define ERmreq12 (ERb|02263) /* Label type mismatch between request and volume */
#define ERmreq13 (ERb|02264) /* Structural error in mount message */
#define ERmreq14 (ERb|02265) /* Setname mismatch between request and volume */
#define ERmreq15 (ERb|02266) /* Mount refused by operator */
#define ERmreq16 (ERb|02267) /* Volume identifiers not supplied by operator */
#define ERmreq17 (ERb|02270) /* Volume-identifier list missing */
#define ERmreq18 (ERb|02271) /* End of volume-identifier list reached while reading */
#define ERmreq19 (ERb|02272) /* Requested tape drive type not available to system */
#define ERmreq20 (ERb|02273) /* Structural error in mount entry */
#define ERmreq21 (ERb|02274) /* Mount requested for unknown device type */
#define ERdevx6 (ERb|02275) /* Job has open JFN on device */
#define ERatsx27 (ERb|02276) /* Terminal is not open */
#define ERatsx28 (ERb|02277) /* Unknown error received */
#define ERatsx29 (ERb|02300) /* Receive error threshold exceeded */
#define ERatsx30 (ERb|02301) /* Reply threshold exceeded */
#define ERatsx31 (ERb|02302) /* NAK threshold exceeded */
#define ERatsx32 (ERb|02303) /* Terminal protocol error */
#define ERatsx33 (ERb|02304) /* Intervention required at terminal */
#define ERatsx34 (ERb|02305) /* Powerfail */
#define ERatsx35 (ERb|02306) /* Data pipe was disconnected */
#define ERatsx36 (ERb|02307) /* Dialup terminal was attached */
#define ERdatex7 (ERb|02310) /* Julian day is out of range */
#define ERmreq22 (ERb|02311) /* Structure name not specified */
#define ERarcfx2 (ERb|02312) /* File already has archive status */
#define ERarcfx3 (ERb|02313) /* Cannot perform ARCF functions on non-multiple directory devices */
#define ERarcfx4 (ERb|02314) /* File is not on-line */
#define ERarcfx5 (ERb|02315) /* Files not on the same device or structure */
#define ERarcfx6 (ERb|02316) /* File does not have archive status */
#define ERarcfx7 (ERb|02317) /* Invalid parameter */
#define ERarcfx8 (ERb|02320) /* Archive not complete */
#define ERarcfx9 (ERb|02321) /* File not off-line */
#define ERarcx10 (ERb|02322) /* Archive prohibited */
#define ERarcx11 (ERb|02323) /* Archive requested, modification prohibited */
#define ERarcx12 (ERb|02324) /* Archive requested, delete prohibited */
#define ERarcx13 (ERb|02325) /* Archive system request not completed */
#define ERopnx30 (ERb|02326) /* File has archive status, modification is prohibited */
#define ERopnx31 (ERb|02327) /* File is off-line */
#define ERdelx11 (ERb|02330) /* File has archive status, delete is not permitted */
#define ERdelx12 (ERb|02331) /* File has no pointer to offline storage */
#define ERarcx14 (ERb|02332) /* File restore failed */
#define ERarcx15 (ERb|02333) /* Migration prohibited */
#define ERarcx16 (ERb|02334) /* Cannot exempt offline file */
#define ERarcx17 (ERb|02335) /* FDB incorrect format for ARCF JSYS */
#define ERarcx18 (ERb|02336) /* Retrieval request cannot be fulfilled for waiting process */
#define ERarcx19 (ERb|02337) /* Migration already pending */
#define ERargx26 (ERb|02340) /* File is offline */
#define ERargx27 (ERb|02341) /* Offline expiration time cannot exceed system maximum */
#define ERdirx5 (ERb|02342) /* Directory too large */
#define ERiox31 (ERb|02343) /* Invalid record descriptor in labeled tape */
#define ERmreq23 (ERb|02344) /* Dismount refused by operator */
#define ERmreq24 (ERb|02345) /* Illegal to dismount connected structure */
#define ERmreq25 (ERb|02346) /* Structure not found */
#define ERltlblx (ERb|02347) /* Too many user labels */
#define ERltlbx1 (ERb|02350) /* Undefined record format on non-TOPS20 tape */
#define ERmreq26 (ERb|02351) /* Tape mounting function disabled by installation */
#define ERmetrx1 (ERb|02352) /* METER% not supported on this processor */
#define ERnspx00 (ERb|02353) /* Connection not accepted */
#define ERnspx01 (ERb|02354) /* Resource allocation failure */
#define ERnspx02 (ERb|02355) /* Destination node does not exist */
#define ERnspx03 (ERb|02356) /* Node shutting down */
#define ERnspx04 (ERb|02357) /* Destination process does not exist */
#define ERnspx05 (ERb|02360) /* Invalid process name */
#define ERnspx06 (ERb|02361) /* Destination process queue overflow */
#define ERnspx07 (ERb|02362) /* Unspecified error */
#define ERnspx08 (ERb|02363) /* Connection aborted by third party */
#define ERnspx09 (ERb|02364) /* Link aborted by process */
#define ERnspx10 (ERb|02365) /* NSP Failure - Flow control violation */
#define ERnspx11 (ERb|02366) /* Too many connections to node */
#define ERnspx12 (ERb|02367) /* Too many connections to destination process */
#define ERnspx13 (ERb|02370) /* Access denied due to unacceptable user name or password */
#define ERnspx14 (ERb|02371) /* NSP failure - invalid SERVICES field */
#define ERnspx15 (ERb|02372) /* Invalid account */
#define ERnspx16 (ERb|02373) /* NSP failure - invalid SEGSIZ field */
#define ERnspx17 (ERb|02374) /* Process aborted, timed out, or cancelled request */
#define ERnspx18 (ERb|02375) /* No path to destination node */
#define ERnspx19 (ERb|02376) /* NSP failure - flow control failure */
#define ERnspx20 (ERb|02377) /* NSP failure - invalid DSTADDR */
#define ERnspx21 (ERb|02400) /* Disconnect confirmation */
#define ERnspx22 (ERb|02401) /* NSP failure - image data field too long */
#define ERmreq27 (ERb|02402) /* Structure is set IGNORED */
#define ERmreq28 (ERb|02403) /* Cannot overwrite volume - first file is not expired */
#define ERmreq29 (ERb|02404) /* Cannot overwrite volume - write access required */
#define ERmreq30 (ERb|02405) /* Tape label format error */
#define ERdiag11 (ERb|02406) /* Unit already online */
#define ERdiag12 (ERb|02407) /* Unit not online */
#define ERdesx11 (ERb|02410) /* Invalid operation for this label type */
#define ERnspx23 (ERb|02411) /* Invalid NSP reason code */
#define ERargx28 (ERb|02412) /* not available on this system */
#define ERnpx2cl (ERb|02413) /* Two colons required on node name */
#define ERargx29 (ERb|02414) /* Invalid class share */
#define ERargx30 (ERb|02415) /* Invalid KNOB value */
#define ERargx31 (ERb|02416) /* Class Scheduler already enabled */
#define ERdevx7 (ERb|02417) /* Null device name given */
#define ERgjfx52 (ERb|02420) /* End of tape encountered while searching for file */
#define ERgoker3 (ERb|02421) /* JSYS not executed within ACJ fork */
#define ERiox32 (ERb|02422) /* Tape position is indeterminate */
#define ERiox33 (ERb|02423) /* TTY input buffer full */
#define ERxsirx1 (ERb|02424) /* Channel table crosses section boundary */
#define ERsirx2 (ERb|02425) /* SIR JSYS invoked from non-zero section */
#define ERrirx1 (ERb|02426) /* RIR JSYS incompatible with previous XSIR */
#define ERxsirx2 (ERb|02427) /* Level table crosses section boundary */
#define ERmreq31 (ERb|02430) /* Insufficient MOUNTR resources */
#define ERsmapx1 (ERb|02431) /* Attempt to delete a section still shared */
