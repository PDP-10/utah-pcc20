#include <pwd.h>

static struct passwd pwd;

static struct passwd pnull = {"", "", 0, 0, 0, "", "", "", ""};

extern char *getlogin();

struct passwd *
getpwuid(uid)
{
    pwd = pnull;
    if (uid == getuid()) {
	pwd.pw_name = getlogin();
	pwd.pw_uid = uid;
	pwd.pw_gecos =  pwd.pw_name;		/* good enuf for now */
	pwd.pw_dir = pwd.pw_name;		/* same as login name */
	pwd.pw_shell = "/system/exec.exe";
	return &pwd;
    }
    return 0;
}

struct passwd *
getpwnam(name)
register char *name;
{
    register char *cp;
    static char	buf[100];

    pwd = pnull;
    pwd.pw_name = name;
    pwd.pw_uid = _rcusr(name);
    pwd.pw_gecos =  name;			/* good enuf for now */
    for (cp = buf; *name; cp++, name++)		/* replace dots with slashes */
	*cp = *name == '.' ? '/' : *name;
    *cp = '\0';
    pwd.pw_dir = buf;				/* almost same as login name */
    pwd.pw_shell = "/system/exec.exe";
    return &pwd;
}
