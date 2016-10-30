#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define N 10010

struct fenz {
    int v,w;
} a[110][5];
int dp[N];

int main() {
  int n, m, i, j, k;
  while(~scanf("%d", &m)) {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=2;j++) {
        scanf("%d %d", &a[i][j].w, &a[i][j].v);
      }
    }
    memset(dp, 0, sizeof(dp));
    for(int k=1; k<=n; k++) {
      for(int i=m; i>=0; i--) {
        for(int j=1;j<=2;j++) {
          if(a[k][j].w<=i)
            dp[i] = max(dp[i],dp[i-a[k][j].w]+a[k][j].v);
          }
      }
    }
    printf("%d\n",dp[m]);
  }
  return 0;
}
