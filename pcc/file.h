/* Partial file.h from 4.2bsd */

#define FATT_RDONLY     0x000   /* open for reading only */
#define FATT_WRONLY     0x001   /* open for writing only */
#define FATT_RDWR       0x002   /* open for reading and writing */
#define FATT_APPEND     0x004   /* append on each write */
#define FATT_CREATE     0x008   /* create file if nonexistent */
#define FATT_TRUNCATE   0x010   /* truncate to size 0 on open */
#define FATT_RDLOCK     0x020   /* apply read lock */
#define FATT_WRLOCK     0x040   /* apply write lock */
#define FATT_UNLOCK     0x080   /* unlock file */
#define FATT_NBLOCK     0x100   /* open should not block */

/* Modes added for BlackJack */

#define FATT_BINARY	0x1000		/* binary: don't map to 7 bit bytes */
#define FATT_DEFSIZE	0x2000		/* default byte size: use size in fdb*/
#define FATT_SETSIZE	0x4000		/* use byte size from 3rd open param */

#include "tops20.h"

/* #define DF_exp		01:35-1	 expunge contents */

#define UNLK_EXPUNGE	Value(/* DF_exp */ 01:35-1)
