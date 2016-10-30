#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAXX = 20;
const int MAXY = 20;
int map[MAXX][MAXY], X, Y;
bool vis[MAXX][MAXY];

int DIED = 1;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline bool check(int x, int y) {
  if(x >= X || y >= Y || x < 0 || y < 0 || map[x][y] == 1) return false;
  return true;
}

int dfs(int x, int y) {
  if(vis[x][y]) return 0;
  int ret = 1;
  vis[x][y] = 1;
  for(int o=0;o<4;o++) {
    int kx = x + dir[o][0];
    int ky = y + dir[o][1];
    if(check(kx, ky)) {
      if(map[kx][ky] == 0) DIED = 0;
      else if(map[kx][ky] == 2) ret += dfs(kx, ky);
    }
  }
  return ret;
}

int solve2() {
  int ret = 0;
  for(int i=0;i<X;i++) {
    for(int j=0;j<Y;j++) {
      if(map[i][j] == 2 && !vis[i][j]) {
        DIED = 1;
        int kuai = dfs(i, j);
        if(DIED) ret = ret > kuai ? ret : kuai;
      }
    }
  }
  return ret;
}

int solve() {
  int ret = 0;
  memset(vis, 0, sizeof(vis));
  for(int i=0;i<X;i++) {
    for (int j=0;j<Y;j++) {
      if(map[i][j] == 0) {
        map[i][j] = 1;
        memset(vis, 0, sizeof(vis));
        int ans = solve2();
        ret = ret > ans ? ret : ans;
        map[i][j] = 0;
      }
    }
  }
  return ret;
}

void test_show(int ma[][MAXX]) {
  for(int i=0;i<X;i++) {
    for(int j=0;j<Y;j++) {
      printf("%d ", ma[i][j]);
    }
    puts("");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    memset(map, -1, sizeof(map));
    scanf("%d %d", &X, &Y);
    for(int i=0;i<X;i++) {
      char buf[MAXX];
      scanf("%s", buf);
      for(int j=0;j<Y;j++) {
        if(buf[j] == 'E') map[i][j] = 0;
        else if(buf[j] == 'B') map[i][j] = 1;
        else if(buf[j] == 'W') map[i][j] = 2;
      }
    }
    //test_show(map);
    printf("%d\n", solve());
  }
  return 0;
}
