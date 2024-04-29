#include <stdio.h>

struct command;
struct plugin;

int rpmb_cmd_option(int argc, char **argv, struct command *cmd, struct plugin *plugin)
{
	fprintf(stderr, "The rpmb command requires AF_ALG support\n");
	return -1;
}

