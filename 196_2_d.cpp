#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int step[3][101000];
vector<int>w[101000];
int mark[101000];
void dfs(int nn,int mm,int id,int dd)
{
    step[id][nn]=dd;
    int len=w[nn].size();
    for(int ii=0;ii<len;ii++)
    {
        int son=w[nn][ii];
        if(son!=mm)dfs(son,nn,id,dd+1);
    }
    return ;
}
void init(int nn)
{
    for(int ii=1;ii<=nn;ii++)w[ii].clear();
    return ;
}
int main()
{
    int i,j,m,n,k;
    while(scanf("%d%d%d",&m,&n,&k)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        init(m);
        for(int ii=1;ii<=n;ii++)
           {
               int uu;
               scanf("%d",&uu);
               mark[uu]=1;
           }
        for(int ii=1;ii<=m-1;ii++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            w[x].push_back(y);
            w[y].push_back(x);
        }
        int xx;
        for(int ii=1;ii<=m;ii++)
        if(mark[ii]){xx=ii;dfs(ii,-1,0,0);break;}
        int yy=xx;
        for(int ii=1;ii<=m;ii++)
        if(mark[ii]&&step[0][ii]>step[0][yy])yy=ii;
        dfs(yy,-1,1,0);
        int zz;
        zz=yy;
        for(int ii=1;ii<=m;ii++)
        if(mark[ii]&&step[1][ii]>step[1][zz])zz=ii;
        dfs(zz,-1,2,0);
        int num=0;
        for(int ii=1;ii<=m;ii++)
            if(step[1][ii]<=k&&step[2][ii]<=k)num++;
        printf("%d\n",num);
    }
    return 0;
}
