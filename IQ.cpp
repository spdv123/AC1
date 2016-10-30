#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int x0, y0, x1, y1, x2, y2;

inline void p(int k) {
  printf("%d\n", k);
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    scanf("%d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2);
    if(x0 == x1 && y0 == y1) {
      if(x1 == x2 && y1 == y2) {
        p(2);
      } else {
        p(1);
      }
    } else if(x1 == x2 && y1 == y2) {
      p(1);
    } else if(x0 == x2 && y0 == y2) {
      p(1);
    }
    else if(((y1-y0)*(x2-x0))==((x1-x0)*(y2-y0))) p(1);
    else p(0);
  }
  return 0;
}
