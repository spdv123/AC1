#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

struct fenz {
    int c, w;
} pack[105][3];
int f[10005];

int main() {
  int n, m;
  while(~scanf("%d", &m)) {
  scanf("%d", &n);
  for(int i=1;i<=n;i++) {
    scanf("%d %d %d %d", &pack[i][1].c, &pack[i][1].w, &pack[i][2].c, &pack[i][2].w);
  }
  memset(f, 0, sizeof(f));
  for(int k=1; k<=n; k++) {
    for(int i=m; i>=0; i--) {
      if(pack[k][1].c<=i)
        f[i] = max(f[i],f[i-pack[k][1].c]+pack[k][1].w);
      if(pack[k][2].c<=i)
        f[i] = max(f[i],f[i-pack[k][2].c]+pack[k][2].w);
    }
  }
  printf("%d\n",f[m]);
}
  return 0;
}
