#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAXN  = 1010;
const int MAXM = 1010;
const int MOD = 1000000007;

int C[MAXN], W[MAXN], V, N, F[MAXN];

int solve() {
  memset(F, 0, sizeof(F));
  F[0] = 1;
  for (int i=1;i<=N;i++) {
    for (int j = V; j >= C[i]; j--) {
      if (j >= C[i])
        F[j] = F[j]+F[j-C[i]];
        if(F[j] >= MOD) F[j] -= MOD;
    }
  }
  return F[V];
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &N, &V);
    for(int i=1;i<=N;i++) scanf("%d", &C[i]);
    printf("%d\n", solve());
  }
  return 0;
}
