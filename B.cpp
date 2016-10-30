#pragma comment(linker, "/STACK:1024000000,1024000000") //??
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
typedef long long LL;
const double eqs=1e-9;
//freopen("data.in", "r", stdin);
#define maxd 10005
int d[3][maxd][2];
int c[105][3],w[105][3];
int m, n;
void init();
void proc();
int get_res();
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("data.in", "r", stdin);
    #endif
    scanf("%d %d", &m, &n);
    memset(c,0,sizeof(c));
    memset(w,0,sizeof(w));
    for (int i=0; i < n; i++)
    {
    	scanf("%d %d %d %d", &c[i][1], &w[i][1], &c[i][2], &w[i][2]);
    }
    init();
    proc();
    int res = get_res();
    printf("%d\n",res);
    return 0;
}
void init()
{
	memset(d,0,sizeof(d));
}
void proc()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = m; j >= 0; j--)
		{
			for (int from = 0; from < 3; from++)
			{
				for (int to = 0; to < 3; to++)
				{
					if(j >= c[i][to])
					{
						d[to][j-c[i][to]][i % 2] = max(d[from][j][(i-1)%2] + w[i][to],d[to][j-c[i][to]][i % 2]);
					}
				}
			}
		}
	}
}
int get_res()
{
	int res = 0;
	for(int i = 0; i < 3; i++)
	{
		res = max(res, d[i][0][(n-1) % 2]);
	}
	return res;
}
/*
20
5
10 1 10 2
10 8 10 9
5 3 4 7
10 20 10 10
10 3 10 4
*/
/*
2
3
50 100 50 1
4 50 5 50
4 60 5 70
*/
/*
5
1
6 100 4 50
*/
