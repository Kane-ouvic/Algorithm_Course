#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#define INF 2e8
#define MAXN 2010
using namespace std;

int dis[MAXN], vis[MAXN], Map[MAXN][MAXN];
int n;
char code[MAXN][10];


 
int Prim() {
    int i, j, k, tmp, ans;
    int mindis = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1;i <= n;i++) dis[i] = Map[1][i];
    vis[1] = 1;
    for (i = 1;i < n;i++) {
        tmp = INF;
        for (int j = 1;j <= n;j++) {
            if (!vis[j] && tmp>dis[j]) {
                tmp = dis[j];
                k = j;
            }//找出最小距離的節點 
        }
        vis[k] = 1;//標記已訪問節點
        mindis += tmp;
//        mindis = max(mindis, tmp);
         for (j = 1;j <= n;j++) {
             if (!vis[j] && dis[j]>Map[k][j]) {
                 dis[j] = Map[k][j];
             }//更新加入最近點後對未加入點的距離 
         }
        
    }
    return mindis;//返回MST的權值 
}


 
void init() {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (i == j) Map[i][j] = 0;
            else Map[i][j] = INF;
        }
    }
}

int cal(int a, int b) {
    int sum = 0;
    for (int i = 0;i < 7;i++) {
        if (code[a][i] != code[b][i])
            sum++;
    }
    return sum;
}

int main()
{
    char c, v;
    int a, b, k, cost;
    while((cin >> n) && n != 0) {
        init();
        for (int d = 1;d <= n;d++) {
            cin >> code[d];
        }
        for (int i = 1;i <= n-1;i++) {
            for (int j = i+1;j <= n;j++) {
                Map[i][j] = Map[j][i] = cal(i, j);
            }
        }
        int ans = Prim();
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}