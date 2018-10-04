
#include <sys/ioctl.h>

#define ioctl freebsd_ioctl
int freebsd_ioctl(int fd, unsigned long cmd, ...);
