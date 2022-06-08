#include <bits/stdc++.h>
using namespace std;
int counter = 0;
class Graph
{
public:
    bool visited[200001];
    bool select[200001];
    int dis[200001];
    vector<list<int>> adj;
    void addEdge(int v, int w);
    void delEdge(int v, int w);
    bool DFS(int v);
    void DFS2(int v, int d);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::delEdge(int v, int w)
{
    adj[v].remove(w);
    adj[w].remove(v);
}
bool Graph::DFS(int v)
{
    visited[v] = true;
    list<int>::iterator i = adj[v].begin();
    while (i != adj[v].end())
    {
        if (!visited[*i])
        {
            bool isLast;
            isLast = DFS(*i);
            if (isLast)
            {
                list<int>::iterator temp = i;
                ++i;
                delEdge(v, *temp);
                counter++;
            }
        }
        else
            ++i;
    }
    if (adj[v].size() == 1 && select[v] == false)
        return true;
    else
        return false;
}
void Graph::DFS2(int v, int d)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            dis[*i] = d + 1;
            DFS2(*i, d + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    vector<int> table;
    int n;
    unsigned long int m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i <= n; i++)
    {
        list<int> temp;
        g.adj.push_back(temp);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c;
        g.select[c] = true;
        table.push_back(c);
    }
    sort(table.begin(), table.end());
    g.DFS(table.at(0));
    memset(g.dis, 0, sizeof(g.dis));
    memset(g.visited, false, sizeof(g.visited));
    g.DFS2(table.at(0), 1);
    int max = -1;
    int node = 0;
    int node2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (g.dis[i] > max)
        {
            max = g.dis[i];
            node = i;
        }
    }
    memset(g.dis, 0, sizeof(g.dis));
    memset(g.visited, false, sizeof(g.visited));
    g.dis[node] = 1;
    g.DFS2(node, 1);
    max = -1;
    for (int i = 0; i < n; i++)
    {
        if (g.dis[i] > max)
        {
            max = g.dis[i];
            node2 = i;
        }
    }
    if (table.size() == 1)
    {
        node = table.at(0);
        node2 = table.at(0);
    }
    cout << min(node, node2) << endl;
    unsigned long int ans = (2 * n - 2 - (max - 1) - 2 * counter) * 1000 + 870000 * m;
    cout << ans << endl;
    return 0;
}