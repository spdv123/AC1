#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int x0, y0, x1, y1, x2, y2;


int solve() {
  if(x0 == x1 && y0 == y1) {
    if(x1 == x2 && y1 == y2) {
      return 2;
    } else {
      return 1;
    }
  } else if(x1 == x2 && y1 == y2) {
    return 1;
  } else if(x0 == x2 && y0 == y2) {
    return 1;
  }
  else if(((y1-y0)*(x2-x0))==((x1-x0)*(y2-y0))) return 1;
  else return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2);
    printf("%d\n", solve());
  }
  return 0;
}
