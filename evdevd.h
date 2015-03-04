#ifndef EVDEVD_H
#define EVDEVD_H

struct command_t { int code; const char *name; char * const * argv; };

static int Key_compare(const void *x, const void *y)
{
    const struct command_t *key  = (const struct command_t *) x;
    const struct command_t *elem = (const struct command_t *) y;

    if (key->code == elem->code)
        return 0;

    return key->code > elem->code ? 1 : -1;
}

struct command_t Keys[] = {
	{
		.code = KEY_VOLUMEDOWN,
		.name = "amixer",
		.argv = (char *const []){ "/usr/bin/amixer", "-q", "set", "Master", "3dB-", NULL }
	},
	{
		.code = KEY_VOLUMEUP,
		.name = "amixer",
		.argv = (char *const []){ "/usr/bin/amixer", "-q", "set", "Master", "3dB+", NULL }
	},
	{
		.code = KEY_MUTE,
		.name = "amixer",
		.argv = (char *const []){ "/usr/bin/amixer", "-q", "set", "Master", "3dB+", NULL }
	},
	{
		.code = KEY_KBDILLUMUP,
		.name = "kbdlight",
		.argv = (char *const []){ "/usr/bin/kbdlight", "up", NULL }
	},
	{
		.code = KEY_KBDILLUMDOWN,
		.name = "kbdlight",
		.argv = (char *const []){ "/usr/bin/kbdlight", "down", NULL }
	},
	{
		.code = KEY_PREVIOUSSONG,
		.name = "mocp",
		.argv = (char *const []){ "/usr/bin/mocp", "--previous", NULL }
	},
	{
		.code = KEY_NEXTSONG,
		.name = "mocp",
		.argv = (char *const []){ "/usr/bin/mocp", "--next", NULL }
	},
	{
		.code = KEY_PLAYPAUSE,
		.name = "mocp",
		.argv = (char *const []){ "/usr/bin/mocp", "--toggle-pause", NULL }
	},
	{
		.code = KEY_BRIGHTNESSUP,
		.name = "backlight-utility",
		.argv = (char *const []){ "/usr/bin/backlight-utility", "someday..", "up", NULL }
	},
	{
		.code = KEY_BRIGHTNESSDOWN,
		.name = "backlight-utility",
		.argv = (char *const []){ "/usr/bin/backlight-utility", "someday...", "down", NULL }
	}
};

#endif
