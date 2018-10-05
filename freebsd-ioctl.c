
#ifdef __FreeBSD__

#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
#include <stdarg.h>

#include "linux/nvme_ioctl.h"

#include <dev/nvme/nvme.h>

#define XXX(x)						\
	case x:						\
	fprintf(stderr, #x ": not implemented\n");	\
	errno = ENOTTY;					\
	return -1;					\

#undef ioctl

static int
freebsd_submit_admin(int fd, unsigned long cmd, struct nvme_admin_cmd *arg)
{
	struct nvme_pt_command pt;
	int rv;

	pt.cmd.opc	= arg->opcode;
	pt.cmd.fuse	= arg->flags;
	pt.cmd.cid	= arg->rsvd1;
	pt.cmd.nsid	= arg->nsid;
	pt.cmd.rsvd2	= arg->cdw2;
	pt.cmd.rsvd3	= arg->cdw3;
//	pt.cmd.mptr	= arg->metadata;
//	pt.cmd.prp1	= arg->addr;
//	pt.cmd.prp2
	pt.cmd.cdw10	= arg->cdw10;
	pt.cmd.cdw11	= arg->cdw11;
	pt.cmd.cdw12	= arg->cdw12;
	pt.cmd.cdw13	= arg->cdw13;
	pt.cmd.cdw14	= arg->cdw14;
	pt.cmd.cdw15	= arg->cdw15;
	pt.buf		= (void *)arg->addr;
	pt.len		= arg->data_len;
	pt.is_read	= (arg->opcode & 1) == 0;
	pt.driver_lock	= 0;
	rv = ioctl(fd, NVME_PASSTHROUGH_CMD, &pt);
	if (rv == -1)
		return (rv);
	arg->result	= htole16(pt.cpl.cid) | htole16(pt.cpl.status) << 16;
	return (rv);
}

int
freebsd_ioctl(int fd, unsigned long cmd, ...)
{
	va_list ap;
	void *arg;

	va_start(ap, cmd);
	arg = va_arg(ap, void *);
	va_end(ap);

	switch (cmd) {
	case NVME_IOCTL_ADMIN_CMD:
		return (freebsd_submit_admin(fd, cmd, arg));
	XXX(NVME_IOCTL_ID);
	XXX(NVME_IOCTL_SUBMIT_IO);
	XXX(NVME_IOCTL_IO_CMD);
	XXX(NVME_IOCTL_RESET);
	XXX(NVME_IOCTL_SUBSYS_RESET);
	XXX(NVME_IOCTL_RESCAN);
	default:
		return (ioctl(fd, cmd, arg));
	}
}

#endif /* __FreeBSD__ */
