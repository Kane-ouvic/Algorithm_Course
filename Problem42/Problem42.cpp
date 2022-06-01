#include <bits/stdc++.h>
using namespace std;
int dis[2001];
bool visited[2001];
int maps[2001][2001];
char code[2001][7];
int prim(int n)
{
    int k, tmp, ans;
    int min = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
        dis[i] = maps[1][i];
    visited[1] = 1;
    for (int i = 1; i < n; i++)
    {
        tmp = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && tmp > dis[j])
            {
                tmp = dis[j];
                k = j;
            }
        }
        visited[k] = 1;
        min += tmp;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dis[j] > maps[k][j])
                dis[j] = maps[k][j];
        }
    }
    return min;
}
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                maps[i][j] = 0;
            else
                maps[i][j] = INT_MAX;
        }
    }
}
int cal(int a, int b)
{
    int c = 0;
    for (int i = 0; i < 7; i++)
    {
        if (code[a][i] != code[b][i])
            c++;
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    char c, v;
    while ((cin >> n) && n != 0)
    {
        init(n);
        for (int i = 1; i <= n; i++)
        {
            cin >> code[i];
        }
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                maps[i][j] = maps[j][i] = cal(i, j);
            }
        }
        int ans = prim(n);
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}