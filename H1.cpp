#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
#define M 10010
#define INF 1<<30
struct Edge
{
    int v,next,w;
}edge[M];
int n,m;
int vis[N][2];
int d[N][2],dp[N][2];
int head[N],cnt;
void init()
{
   cnt=0;
   memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void djstl(int s,int e)
{
    for(int i=1; i<=n; i++)
        d[i][0]=d[i][1]=INF;
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    d[s][0]=0;
    dp[s][0]=1;
    while(1)
    {
        int maxn=INF;
        int v,flag;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j][0]&&maxn>d[j][0])
            {
                maxn=d[j][0];
                v=j;flag=0;
            }
            else if(!vis[j][1]&&maxn>d[j][1])
            {
                maxn=d[j][1];
                v=j;flag=1;
            }
        }
        if(v==e&&flag==1) break;
        if(maxn==INF) break;
        vis[v][flag]=1;
        for(int u=head[v]; u!=-1; u=edge[u].next)
        {
            int j=edge[u].v,w=edge[u].w;
            if(!vis[j][0]&&d[v][flag]+w<d[j][0])
            {
                d[j][1]=d[j][0];
                d[j][0]=d[v][flag]+w;
                dp[j][1]=dp[j][0];
                dp[j][0]=dp[v][flag];
            }
            else if(!vis[j][0]&&d[v][flag]+w==d[j][0])
                dp[j][0]+=dp[v][flag];
            else if(!vis[j][1]&&d[v][flag]+w<d[j][1])
            {
                d[j][1]=d[v][flag]+w;
                dp[j][1]=dp[v][flag];
            }
            else if(!vis[j][1]&&d[v][flag]+w==d[j][1])
                dp[j][1]+=dp[v][flag];
        }
    }
}

int main()
{
    int s,e,T;
    int x,y,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        init();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            addedge(x,y,w);
            //addedge(y,x,w);
        }
        scanf("%d %d",&s,&e);
        djstl(1,n);
        printf("%d\n",dp[e][1]);
    }
    return 0;
}
