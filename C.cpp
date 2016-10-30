#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int x, y;

int gcd(int a,int b){
    return b==0 ? a : gcd(b,a%b);
}

int solve() {
  int sum=0;
  if(x % y != 0) return 0;
  int a = x / y;
  for(int i=1;i<a;i++) {
    if(a % i == 0) {
      if(gcd(i, a / i) == 1) sum ++;
    }
  }
  return sum;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &x, &y);
    if(x < y) {
      int cc = y;
      y = x;
      x = cc;
    }
    printf("%d\n", solve());
  }
  return 0;
}
