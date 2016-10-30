#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int fac[10010], top;
int x, y;

void resolve(int a) {
    top=0;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            fac[top++]=i;
            while(a%i==0) a/=i;
        }
    }
    if(a>1) fac[top++]=a;
}

int fastpow(int p){
  int ans=1, temp=2;
  while(p){
    if(p&1) ans=ans * temp;
    temp=temp*temp;
    p>>=1;
  }
  return ans;
}

int solve() {
  if(y % x) return 0;
  int z = y / x;
  resolve(z);
  return fastpow(top) - 1;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &x, &y);
    printf("%d\n", solve());
  }
  return 0;
}
