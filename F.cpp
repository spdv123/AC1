#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAXN = 110;
int N, a[MAXN];

int solve() {
  int ok = 1;
  for(int i = N-1;i >= 2; i--) {
    for(int j = 0;j < i;j ++) {
      for(int k=j+1;k<i;k++) {
        if(a[j] > a[i] && a[i] > a[k]) return 0;
      }
    }
  }
  return 1;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    for (int i=0;i<N;i++) scanf("%d", &a[i]);
    if(solve()) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
  }
  return 0;
}
