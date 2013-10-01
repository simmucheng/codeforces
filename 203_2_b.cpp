#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
const int inf=(1<<30);
int mark[101000];
int num[101000];
int s[101000];
int pre[101000];
vector<int> w[101000];
vector<int> q;
int mm,get_max;
void dfs(int sta,int nn,int ci)
{
    w[sta].push_back(nn);
    mark[nn]=1;
    if(s[pre[nn]]==1||num[pre[nn]]>1||mark[pre[nn]]||pre[nn]==0)
    {
        if(ci>get_max)
        {
            get_max=ci;
            mm=sta;
        }
        return ;
    }
    dfs(sta,pre[nn],ci+1);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        q.clear();
        memset(num,0,sizeof(num));
        get_max=0;
        for(int ii=1;ii<=n;ii++)
        {
            scanf("%d",&s[ii]);
            if(s[ii]==1)q.push_back(ii);
        }

        for(int ii=1;ii<=n;ii++)
        {
            scanf("%d",&pre[ii]);
            num[pre[ii]]++;
        }
        int len=q.size();
        for(int ii=0;ii<len;ii++)w[ii].clear();
        for(int ii=0;ii<len;ii++){memset(mark,0,sizeof(mark));dfs(ii,q[ii],1);}
        len=w[mm].size();
        printf("%d\n",len);
        printf("%d",w[mm][len-1]);
        for(int ii=len-2;ii>=0;ii--)printf(" %d",w[mm][ii]);
        printf("\n");
    }
    return 0;
}

