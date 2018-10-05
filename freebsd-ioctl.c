
#ifdef __FreeBSD__

#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>

#include "linux/nvme_ioctl.h"

#include <dev/nvme/nvme.h>

int
freebsd_ioctl(int fd, unsigned long cmd, ...)
{
	switch (cmd) {
	case NVME_IOCTL_ID:
	case NVME_IOCTL_ADMIN_CMD:
	case NVME_IOCTL_SUBMIT_IO:
	case NVME_IOCTL_IO_CMD:
	case NVME_IOCTL_RESET:
	case NVME_IOCTL_SUBSYS_RESET:
	case NVME_IOCTL_RESCAN:
	default:
		errno = ENOTTY;
		printf("Unknown ioctl %#lx\n", cmd);
		return -1;
	}
}

#endif /* __FreeBSD__ */
