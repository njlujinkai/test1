#include "func.h"
//字符串长度
int mystrlen(char* a)
{
    int len=0;
    while(*a!='\0')
    {
        a++;
        len++;
    }
    return len;
}
//判断字符串是否相等
bool mystrcmp(char* a,char* b)
{
    int len1=mystrlen(a);
    int len2=mystrlen(b);
    if(len1==len2)
    {   
        int i;
        for(i=0;i<len1;i++)
        {
            if(a[i]!=b[i])
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
//判断字符串大小
bool mystrcmps(char* a,char*b)
{
    while(*a==*b)
    {
        a++;
        b++;
    }
    return *a>*b? 1:0;
}

