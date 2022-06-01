#include <bits/stdc++.h>
using namespace std;
int minD(int dist[], bool set[], int N)
{
    int min = INT_MAX;
    int index;
    for (int v = 0; v < N; v++)
    {
        if (!set[v] && dist[v] <= min)
            min = dist[v], index = v;
    }
    return index;
}
void pr(int dist[], int N)
{
    int a = -1;
    for (int i = 0; i < N; i++)
        a = max(a, dist[i]);
    cout << a;
}
void di(vector<vector<int>> &g, int src, int N)
{
    int dist[N];
    bool set[N];
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX, set[i] = false;
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++)
    {
        int u = minD(dist, set, N);
        set[u] = true;
        for (int v = 0; v < N; v++)
            if (!set[v] && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }
    pr(dist, N);
}
int main()
{
    int N, a;
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N, 0));
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            cin >> a, g[i][j] = a, g[j][i] = a;
    di(g, 0, N);
    return 0;
}