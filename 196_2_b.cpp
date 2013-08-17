#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
__int64 get(__int64 mm,__int64 nn)
{
    while(nn)
    {
        int tt=mm%nn;
        mm=nn;
        nn=tt;
    }
    return mm;
}
int main()
{
     __int64 n,m,x,y;
    while(scanf("%I64d%I64d%I64d%I64d",&m,&n,&x,&y)!=EOF)
    {

           __int64 xx=x*n;
           __int64 yy=y*n;
           __int64 mm=m*y;
           __int64 nn=n*y;
           __int64 ans;
           if(xx-mm>0)
           {
               __int64 ads=xx-mm;
               ans=get(ads,xx);
               printf("%I64d/%I64d\n",ads/ans,xx/ans);
           }
           else if(xx-mm<0)
           {
               __int64 tt=mm;
               mm*=xx;
               nn*=xx;
               xx*=tt;
               yy*=tt;
               __int64 ads=yy-nn;
               ans=get(ads,yy);
               printf("%I64d/%I64d\n",ads/ans,yy/ans);
           }
           else printf("0/1\n");
    }
    return 0;
}

