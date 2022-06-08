#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef list<pair<int, int>> g;
void add(g *l, int u, int v, int w)
{
    l[u].push_back(make_pair(v, w));
}
void dij(g *l, int s, int N)
{
    priority_queue<pi, vii, greater<pi>> Q;
    int dst[2 * N];
    for (int i = 0; i < 2 * N; i++)
        dst[i] = 1e5;
    dst[s] = 0;
    Q.push({0, s});
    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        for (auto x : l[u])
        {
            int v = x.first, w = x.second;
            if (dst[u] + w < dst[v])
                dst[v] = dst[u] + w, Q.push(make_pair(dst[v], v));
        }
    }
    if (dst[N - 1] == 1e5)
        cout << "-1";
    else
        cout << dst[N - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, C, u, v, w, f;
    cin >> N >> M >> C;
    g l[2 * N];
    for (int i = 0; i < N; i++)
    {
        cin >> f;
        add(l, N - 1 + f, i, 0);
        if (f == 1)
            add(l, i, N + f, C);
        else if (f == N)
            add(l, i, N - 2 + f, C);
        else
        {
            add(l, i, N + f, C);
            add(l, i, N - 2 + f, C);
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        add(l, u, v, w);
        add(l, v, u, w);
    }
    dij(l, 0, N);
}