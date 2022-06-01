#include <bits/stdc++.h>
using namespace std;
bool exsit[1000][1000];
class Graph
{
    int V;
    list<int> *adj;
    void DFS(int v, bool visited[]);

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void addEdge(int u, int v);
    bool isSCC();
    Graph getR();
};
void Graph::DFS(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}
Graph Graph::getR()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
            g.adj[*i].push_back(v);
    }
    return g;
}
void Graph::addEdge(int u, int v)
{
    if (!exsit[u - 1][v - 1])
    {
        adj[u - 1].push_back(v - 1);
        exsit[u - 1][v - 1] = true;
    }
    
}
bool Graph::isSCC()
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
    DFS(0, visited);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            return false;
    }
    Graph gr = getR();
    memset(visited, false, sizeof(visited));
    gr.DFS(0, visited);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
}
int main()
{
    int M, N;
    int u, v, d;
    vector<int> out;
    while (1)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        Graph g(N);
        memset(exsit, false, sizeof(exsit));
        for (int i = 0; i < M; i++)
        {
            cin >> u >> v >> d;
            if (d - 1)
            {
                g.addEdge(u, v);
                g.addEdge(v, u);
            }
            else
            {
                g.addEdge(u, v);
            }
        }
        g.isSCC() ? cout << "1\n" : cout << "0\n";
    }
    return 0;
}