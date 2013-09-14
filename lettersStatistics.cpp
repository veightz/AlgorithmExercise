#include "stdio.h"
#include "string.h"
#include "header.h"

int length;

int main()
{
    char str[200];
    int    times[26];
    gets_s(str);
    length = strlen(str);
    convert(str);
    cal(str, times);
    out(times);
}