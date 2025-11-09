#pragma once
#include <stdio.h>
#include <osapi.h>

#define driveC 0x01
#define driveD 0x02
#define BasePath $1 "/home/tameron/drives/disk."
#define Maxdrive 0x02

#define BlockSize 512

typedef int8 block[512];

internal struct sdisk {
    int32 fd;
    int16 blocks;
    int8 driveNo:2;
} packed;
typedef struct sdisk disk;

internal disk *dmount(int8);
internal void  dunmount(disk*);
internal void dshow(disk*);
internal int16 openfiles(disk *);
internal void closeallfiles(disk *);
internal void zero(int8 *, int16);
/*
bool dread(disk *dd, block *addr, int16 blockno);
bool dwrite(disk *dd, block *addr, int16 blockno);
*/
// disk input and output
#define dio(function,disk,address,blockIndex)    ( \
    (disk) && \
    (lseek($i (disk)->fd, $i (BlockSize*(blockIndex)), SEEK_SET) != -1) && \
    (((function)($i (disk)->fd, $c (address), BlockSize) == BlockSize)) \
)

#define dread(disk,address,blockIndex) dio(read,disk,address,blockIndex)
#define dwrite(disk,address,blockIndex) dio(write,disk,address,blockIndex)