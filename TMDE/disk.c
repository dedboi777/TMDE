#include <disk.h>


internal int8 mounted;

internal void zero(int8 *str, int16 size) {
    int8 *p;
    int16 n;

    for(n = size, p = str; n; n--, p++) {
        *p = 0;
    }
    
    return;
}

internal void dshow(disk *dd){
    if (dd)
        printf(
                "drive 0x%.02hhx\n"
                "fd=%d\n"
                "NumOfBlocks%d\n",
                    (char)dd->driveNo, $i dd->fd, $i dd->blocks
            );
    return;
}

public disk *DiskDescriptor[Maxdrive];
public void dinit() {
    int8 n;

    mounted = 0;
    for (n=1; n<=Maxdrive; n++)
        *(DiskDescriptor+(n-1))= dmount(n);
     
    /*
    MOUNT YOUR FILESYSTEM HERE    
    */


    for (n=1; n<=Maxdrive; n++)
        dunmount(DiskDescriptor[n-1]);
    
    return;
}

internal void dunmount(disk *dd) {
    int8 x;
    if (!dd)
        return;
    
    close($i dd->fd);
    x = ~(dd->driveNo) & mounted;
    mounted = x;
    destroy(dd);

    return;
}

internal disk *dmount(int8 driveNo){
    disk *dd;
    int16 size;
    int8 *file;
    signed int tmp;
    struct stat sbuf;

    if ((driveNo==1) || (driveNo==2));
    else return (disk *)0;

    if(mounted & driveNo)
        return (disk *)0;

    size = sizeof(struct sdisk);
    dd = (disk *)malloc($i size);
    if(!dd)
        return (disk *)0;

    zero($1 dd, size);
    file = strnum(BasePath, driveNo);
    tmp = open($c file, O_RDWR);
    if (tmp < 3){
        free(dd);
        return (disk *)0;
    }
    dd->fd = $4 tmp;
    tmp = fstat( dd->fd, &sbuf);
    if(tmp ||  !sbuf.st_blocks){
        close(dd->fd);
        free(dd);

        return (disk *)0;
    }
    dd->blocks = $2 (sbuf.st_blocks-1);
    dd->driveNo = driveNo;
    mounted |= driveNo;

    return dd;
}


/* (notfinished )*/
internal int16 openfiles(disk *dd) {
    return 0;
}
internal void closeallfiles(disk *dd) {
    return;
}

