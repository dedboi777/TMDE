#pragma once
#include <stdio.h>
#include <os.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define getposixfd(x) fds[(x)]
#define assert_initialized() if (!initialized) reterr(ErrInit)

#ifdef Library
 private bool isopen(fd);
 private void setupfds(void);
#endif

internal int8 *strnum(int8*,int8);
