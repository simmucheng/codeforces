#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int inf=(1<<30);
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int get_min,get_max;
        get_min=inf;
        get_max=-inf;
        for(int ii=1;ii<=m;ii++)
        {
            int x;
            scanf("%d",&x);
            get_min=min(x,get_min);
            get_max=max(x,get_max);
        }
        int tt=max(get_max,get_min*2);
        int get_aa=inf;
        for(int ii=1;ii<=n;ii++)
        {
            int x;
            scanf("%d",&x);
            get_aa=min(get_aa,x);
        }
        if(get_aa<=tt)printf("-1\n");
        else printf("%d\n",tt);
    }
    return 0;
}
