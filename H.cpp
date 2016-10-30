#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 1000 + 5;
const int MAXX = 1e9;

struct Edge{
    int to;
    int dis;
    Edge(int to,int dis){
        this -> to = to;
        this -> dis = dis;
    }
};

struct Node{
    int d;
    int v;
    int pose;
    friend bool operator<(Node x,Node y){
        if(x.d==y.d) return x.v>y.v;
        return x.d>y.d;
    }
};

int T,N,M;
int a,b,c, S, F;
bool vis[MAXN][2];
int dist[MAXN][2];
int degree[MAXN][2];
vector<Edge>G[MAXN];

void dij(int s,int e){

    for(int i=0;i<MAXN;i++){
        dist[i][0]=dist[i][1]=MAXX;
        degree[i][0]=degree[i][1]=0;
        vis[i][0]=vis[i][1]=false;
    }
    priority_queue<Node>q;
    while(q.size()) q.pop();
    Node p,w;
    p.d=0; p.v=s; p.pose=0;
    degree[p.v][p.pose]=1;
    q.push(p);
    while(q.size()){
        p=q.top(); q.pop();
        if(vis[p.v][p.pose]) continue;
        vis[p.v][p.pose]=true;
        for(int i=0;i<G[p.v].size();i++){

            Edge& e=G[p.v][i];
            if(!vis[e.to][0]&&p.d+e.dis<dist[e.to][0]){
                if(dist[e.to][0]!=MAXX){
                    w.v=e.to; w.d=dist[e.to][0]; w.pose=1;
                    dist[e.to][1]=dist[e.to][0];
                    degree[e.to][1]=degree[e.to][0];
                    q.push(w);
                }
                w.v=e.to; w.d=p.d+e.dis; w.pose=0;
                dist[e.to][0]=w.d; degree[e.to][0]=degree[p.v][p.pose];
                q.push(w);
            }

            else if(!vis[e.to][0]&&p.d+e.dis==dist[e.to][0]){
                degree[e.to][0]+=degree[p.v][p.pose];
            }

            else if(!vis[e.to][1]&&p.d+e.dis<dist[e.to][1]){
                w.v=e.to; w.d=p.d+e.dis; w.pose=1;
                dist[e.to][1]=w.d; degree[e.to][1]=degree[p.v][p.pose];
                q.push(w);
            }

            else if(!vis[e.to][1]&&p.d+e.dis==dist[e.to][1]){
                degree[e.to][1]+=degree[p.v][p.pose];
            }
        }
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<MAXN;i++) G[i].clear();
        scanf("%d %d",&N,&M);
        for(int i=0;i<M;i++){
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back(Edge(b,c));
        }
        S = 1; F = N;
        dij(1, N);
        printf("%d\n", degree[F][1]);
    }return 0;
}
