
/* */

#include <sys/disk.h>

/* FreeBSD calls BLKPBSZGET something else */
#define BLKPBSZGET DIOCGSECTORSIZE

/* FreeBSD doesn't need BLKRRPART, so don't define it */
