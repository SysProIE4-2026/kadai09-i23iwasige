/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif

extern char **environ;

int main(int argc, char *argv[], char *envp[]) {
  int i;

  for(i = 1;i < argc; i++) {
    if(putenv(argv[i]) != 0) {
      break;
    }
  }

  if(i >= argc) {
    char **e;
    for(e = environ; *e != NULL; e++) {
      printf("%s\n", *e);
    }
    return 0;
  }

  execvp(argv[i], &argv[i]);

  perror(argv[i]);
  return 1;
}

/* 実行例
% ./myenv
__CFBundleIdentifier=com.apple.Terminal
TMPDIR=/var/folders/2j/5thsvrb96mb6s3kcbslxzmbw0000gn/T/
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/var/run/com.apple.launchd.VAUnJhupAV/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
COLORTERM=truecolor
OSLogRateLimit=64
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=A8EFD44C-8887-4957-B67F-0242D72FCFC4
SHELL=/bin/zsh
HOME=/Users/iwashigesorato116
LOGNAME=iwashigesorato116
USER=iwashigesorato116
PATH=/opt/homebrew/bin:/Library/Frameworks/Python.framework/Versions/3
.12/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/us
r/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstr
ap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/boo
tstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/boots
trap/usr/appleinternal/bin:/Users/iwashigesorato116/apache-maven-3.9.9
/bin
SHLVL=1
PWD=/Users/iwashigesorato116/SysPro/kadai09-i23iwasige
OLDPWD=/Users/iwashigesorato116/SysPro
LANG=ja_JP.UTF-8
_=/Users/iwashigesorato116/SysPro/kadai09-i23iwasige/./myenv
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--  1 iwashigesorato116  staff     132  6月 29 22:00 Makefile
-rwxr-xr-x  1 iwashigesorato116  staff   33736  6月 29 22:30 myenv
-rw-r--r--  1 iwashigesorato116  staff     560  6月 29 22:30 myenv.c
-rwxr-xr-x  1 iwashigesorato116  staff     216  6月 29 22:00 myputenv.c
-rw-r--r--  1 iwashigesorato116  staff      93  6月 29 22:00 myputenv.h
-rw-r--r--  1 iwashigesorato116  staff    1268  6月 29 22:00 README.md
-rw-r--r--  1 iwashigesorato116  staff  139098  6月 29 22:00 README.pdf
% ./myenv FOO=bar
__CFBundleIdentifier=com.apple.Terminal
TMPDIR=/var/folders/2j/5thsvrb96mb6s3kcbslxzmbw0000gn/T/
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/var/run/com.apple.launchd.VAUnJhupAV/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
COLORTERM=truecolor
OSLogRateLimit=64
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=A8EFD44C-8887-4957-B67F-0242D72FCFC4
SHELL=/bin/zsh
HOME=/Users/iwashigesorato116
LOGNAME=iwashigesorato116
USER=iwashigesorato116
PATH=/opt/homebrew/bin:/Library/Frameworks/Python.framework/Versions/
3.12/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/
usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/boot
strap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system
/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/
bootstrap/usr/appleinternal/bin:/Users/iwashigesorato116/apache-maven
-3.9.9/bin
SHLVL=1
PWD=/Users/iwashigesorato116/SysPro/kadai09-i23iwasige
OLDPWD=/Users/iwashigesorato116/SysPro
LANG=ja_JP.UTF-8
_=/Users/iwashigesorato116/SysPro/kadai09-i23iwasige/./myenv
FOO=bar
% ./myenv FOO=bar nonexistent_command
nonexistent_command: No such file or directory
*/
