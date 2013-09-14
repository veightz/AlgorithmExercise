//求当前最大频率字母下标
int maxMark(int times[])
{
    int i, mark;
    mark = 0;
    for(i = 1; i < 26;++i)
    {
        if(times[i] > times[mark])
        {
            mark = i;
        }
    }
    return mark;
}