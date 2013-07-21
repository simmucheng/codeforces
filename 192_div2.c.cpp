#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[110][110];
int rr[110];
int ll[110];
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m)!=EOF)
    {
        memset(ll,-1,sizeof(ll));
        memset(rr,-1,sizeof(rr));
        for(i=1;i<=m;i++)
            scanf("%s",s[i]);
        for(i=1;i<=m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='.')
                {
                    rr[i]=j;
                    ll[j]=i;
                }
            }
        }
        int mark=0;
        for(i=0;i<m;i++)
        {
            if(ll[i]==-1)
            {
                mark=1;
                break;
            }
        }
        if(!mark)
        {
            for(i=0;i<m;i++)
                printf("%d %d\n",ll[i],i+1);
        }
        else
        {
            mark=0;
            for(i=1;i<=m;i++)
            {
                if(rr[i]==-1)
                {
                    mark=1;
                    break;
                }
            }
            if(!mark)
            {
                for(i=1;i<=m;i++)
                    printf("%d %d\n",i,rr[i]+1);

            }
            else
                printf("-1\n");
        }
    }
    return 0;
}


