#pragma once
#include <stdio.h>
#include <Head.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define copy(dst,src,n)         memorycopy(dst,src,n,false)
#define stringcopy(dst,src,n)   memorycopy(dst,src,n,true)
#define getposixfd(x) fds[(x)]
#define assert_initialized() if (!initialized) reterr(InitErr)

#ifdef Library
 private bool isopen(fd);
 private void setupfds(void);
#endif

internal int16 stringlen(int8*);
internal int8 *strnum(int8*,int8);
internal void memorycopy(int8*, int8*, int16, bool);
internal void zero(int8*, int16);
