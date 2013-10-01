#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int inf=(1<<30);
struct node
{
    __int64 xx;
    __int64 yy;
}s[100100];
inline bool cmp(node aa,node bb)
{
    if(abs(aa.yy)!=abs(bb.yy))return abs(aa.yy)<abs(bb.yy);
    return abs(aa.xx)<abs(bb.xx);
}
void judge1(__int64 x1,__int64 y1)
{
    if(x1<0)printf("1 %d L\n",-x1);
    else if(x1>0)printf("1 %d R\n",x1);
    if(y1<0)printf("1 %d D\n",-y1);
    else if(y1>0)printf("1 %d U\n",y1);
}
void judge2(__int64 x1,__int64 y1)
{
    if(y1<0)printf("1 %d D\n",-y1);
    else if(y1>0)printf("1 %d U\n",y1);
    if(x1<0)printf("1 %d L\n",-x1);
    else if(x1>0)printf("1 %d R\n",x1);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        __int64 sum=0;
        for(int ii=0;ii<n;ii++)
        {
            scanf("%I64d%I64d",&s[ii].xx,&s[ii].yy);
            if(s[ii].xx==0)sum-=2;
            if(s[ii].yy==0)sum-=2;
            sum+=6;
        }
        sort(s,s+n,cmp);
        printf("%I64d\n",sum);
        for(int ii=0;ii<n;ii++)
        {
            judge1(s[ii].xx,s[ii].yy);
            printf("2\n");
            judge2(-s[ii].xx,-s[ii].yy);
            printf("3\n");
        }
    }
    return 0;
}

