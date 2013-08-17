#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1e9+9;
__int64 mm[3][3];
__int64 ans[3][3];
__int64 mark[3][3];
__int64 matrix(int nn)
{
    nn--;
    while(nn)
    {
        if(nn&1)
        {
            memset(mark,0,sizeof(mark));
            for(int ii=1;ii<=2;ii++)
                for(int jj=1;jj<=2;jj++)
                    for(int kk=1;kk<=2;kk++)
                       mark[ii][jj]=(mark[ii][jj]+(ans[ii][kk]*mm[kk][jj])%MAXN)%MAXN;
            for(int ii=1;ii<=2;ii++)
            for(int jj=1;jj<=2;jj++)
            ans[ii][jj]=mark[ii][jj];
        }
        memset(mark,0,sizeof(mark));
        for(int ii=1;ii<=2;ii++)
            for(int jj=1;jj<=2;jj++)
                for(int kk=1;kk<=2;kk++)
                    mark[ii][jj]=(mark[ii][jj]+(mm[ii][kk]*mm[kk][jj])%MAXN)%MAXN;
        for(int ii=1;ii<=2;ii++)
        for(int jj=1;jj<=2;jj++)
        mm[ii][jj]=mark[ii][jj];
        nn>>=1;
    }
    return ans[1][1];
}
void init(int nn)
{
    mm[1][1]=2;
    mm[1][2]=0;
    mm[2][1]=2;
    mm[2][2]=1;
    ans[1][1]=2*nn;
    ans[1][2]=nn;
    ans[2][1]=0;
    ans[2][2]=0;
}
int main()
{
    __int64 m,n,k;
    while(scanf("%I64d%I64d%I64d",&k,&m,&n)!=EOF)
    {
        init(n);
        __int64 ans=0;
        __int64 u=k-m;
        if((u+1)*(n-1)>=m)ans=m;
        else
        {
            m-=u*(n-1);
            __int64 kk=m/n;
            ans+=u*(n-1)+m%n;
            if(kk>0)ans+=matrix(kk);
        }
        printf("%I64d\n",ans%MAXN);
    }
    return 0;
}

