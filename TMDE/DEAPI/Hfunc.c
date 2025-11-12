#include "Hfunc.h"


internal void memorycopy(int8 *dst, int8 *src, int16 len, bool string) {
    int16 n;
    int8 *dp, *sp;

    for(dp=dst, sp=src, n=len; n; dp++, sp++, n-- ){
        if((string) && !(*sp))
            break;
        else   
            *dp = *sp;
    }
    if (string)
        *dp = (int8)0;
    
    return;
}

internal int16 stringlen(int8 *str) {
    int16 n;
    int8 *p;

    for(p = str, n=0; *p; p++, n++){}
    
    return n;
}

internal int8 *strnum(int8* str, int8 num) {
    static int8 buf[256];
    int16 n;
    int8 c;

    n = stringlen(str);
    if (!n)
        return str;
    else if (n > 250)
        return str;
    else if (num > 9)
        return str;
    
    zero($1 &buf, 256);
    copy($1 &buf, str, n);

    c = num + 0x30;
    buf[n++] = c;
    buf[n] = 0; // for the trailing zero \0 

    return buf;
}