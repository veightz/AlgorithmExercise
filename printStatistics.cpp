#include "stdio.h"

extern int  maxMark(int times[]);
//¸ñÊ½Êä³ö
void out(int times[])
{
    int i,max;
    max = 0;
    for(i = 0; i < 26; ++i)
    {
        max = maxMark(times);
        printf("%c  %d\n",max + 97, times[max]);
        times[max] = -1;
    }
}