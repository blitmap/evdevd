#ifndef EVDEVD_H
#define EVDEVD_H

struct command_t {
	const int code;
	const char *name;
	char * const * argv;
} Keys[] = {
	{
		.code = KEY_VOLUMEUP,
		.name = "amixer",
		.argv = (char *const []){ "/usr/bin/amixer", "-q", "set", "Master", "3dB+", NULL }
	},
	{
		.code = KEY_VOLUMEDOWN,
		.name = "amixer",
		.argv = (char *const []){ "/usr/bin/amixer", "-q", "set", "Master", "3dB-", NULL }
	}
};

#endif
