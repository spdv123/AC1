#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int minus[11] = {-1, -1, -1,-1,-1,-1,5,1,9,5}
int plus[11] = {8,7,-1,9,-1,9,8,-1,-1,8}
int self[11] = {9,1,3,3,4/*11*/,5,9,7,8,9}

char buf[1010], solved[1010];
int a[1010];

void solve() {
  int len = strlen(buf);
  for(int i=0;i<len;i++) a[i] = buf[i] - '0';

}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%s", buf);
    solve();
    printf("%s\n", solved);
  }
  return 0;
}
