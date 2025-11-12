#include <stdlib.h>

#define bool int8
#define true 1
#define false 0

typedef unsigned char int8;
typedef unsigned short int16;
typedef unsigned int int32;
typedef unsigned long long int int64;
typedef int8 fd;
typedef int8 error;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $c (char *)
#define $i (int)
#define $8 (int64)

#define packed __attribute__((packed))
#define internal __attribute__((visibility("hidden")))
#define public __attribute__((visibility("default")))
#define private static

#define reterr(x) do{\
    errnumber = (x); \
    return 0;        \
} while(false);

#define throw return 0
#define reserve(x) malloc($i x)
#define release(x) free(x)

#ifdef Library
    public bool initialized = false;
    public error errnumber;
#else 
    extern public bool initialized;
    extern public error errnumber;
#endif

public packed enum {
    Clean,
    InitErr,
    IOErr,
    InvFdErr,
    NotMountedErr,
    InsufMemErr,
    BusyErr,
    InvArgErr,
    InvFNameErr,
    InodeErr,
    InvDirErr,
    PtrNotFoundErr,
    InvDriveNoErr,
    ErrPath
};



public bool load(fd,int8);
public int8 store(fd);
public void dinit(void);