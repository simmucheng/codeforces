#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
    int xx;
    int yy;
    int step;
};
int dir[][2]={1,0,-1,0,0,1,0,-1};
char s[1010][1010];
int mm[1010][1010];
queue<node> q;
int main()
{
    int i,j,m,n;
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        memset(mm,0,sizeof(mm));
        int ww=-1;
        for(i=0;i<a;i++)
        scanf("%s",s[i]);
        int mark=0;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if(s[i][j]=='E')
                {
                    node tt;
                    tt.xx=i;
                    tt.yy=j;
                    tt.step=0;
                    mm[i][j]=1;
                    q.push(tt);
                    mark=1;
                    break;
                }
                if(mark==1)break;
            }
        }
        int sum=0;
        while(!q.empty())
        {
            node rr=q.front();
            q.pop();
           // cout<<s[rr.xx][rr.yy]<<endl;
            if(ww!=-1&&rr.step>ww)break;
            if(s[rr.xx][rr.yy]>='0'&&s[rr.xx][rr.yy]<='9')sum+=(s[rr.xx][rr.yy]-'0');
            else if(s[rr.xx][rr.yy]=='S')ww=rr.step;
            for(i=0;i<4;i++)
            {
                int x1=rr.xx+dir[i][0];
                int y1=rr.yy+dir[i][1];
                if(x1<0||y1<0||x1>=a||y1>=b||mm[x1][y1]||s[x1][y1]=='T')continue;
                node pp;
                pp.xx=x1;
                pp.yy=y1;
                pp.step=rr.step+1;
                q.push(pp);
                mm[x1][y1]=1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
/*
直接找出对终点的距离即可
*/
