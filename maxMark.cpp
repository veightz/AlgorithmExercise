//��ǰ���Ƶ����ĸ�±�
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