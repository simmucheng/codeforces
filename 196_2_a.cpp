#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int s[1010];
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(int ii=0;ii<n;ii++)
            scanf("%d",&s[ii]);
        sort(s,s+n);
        int get_min=1e8;
        if(m>n){printf("%d\n",s[n-1]-s[0]);continue;}
        for(int ii=0;ii<n-m+1;ii++)
        {
            for(int jj=ii+m-1;jj<n;jj++)
            {
                if(s[jj]-s[ii]<get_min)
                    get_min=s[jj]-s[ii];
            }
        }
        printf("%d\n",get_min);
    }
    return 0;
}
