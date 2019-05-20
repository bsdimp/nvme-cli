#ifndef _DISCOVER_H
#define _DISCOVER_H

extern int fabric_discover(const char *desc, int argc, char **argv, bool connect);
extern int fabric_connect(const char *desc, int argc, char **argv);
extern int fabric_disconnect(const char *desc, int argc, char **argv);
extern int fabric_disconnect_all(const char *desc, int argc, char **argv);

#endif
