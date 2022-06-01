#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
void tSort()
{
    int V = a.size();
    vector<int> in(V, 0);
    for (int u = 0; u < V; u++)
        for (auto x : a[u])
            in[x]++;
    multiset<int> s;
    for (int i = 0; i < V; i++)
        if (in[i] == 0)
            s.insert(i);
    vector<int> top;
    while (!s.empty())
    {
        int u = *s.begin();
        s.erase(s.begin());
        top.push_back(u);
        for (auto x : a[u])
            if (--in[x] == 0)
                s.insert(x);
    }
    for (int i = 0; i < top.size(); i++)
        cout << top[i] + 1 << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, u, v;
    while (scanf("%d %d", &N, &M) != EOF)
    {
        a = vector<vector<int>>(N);
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d", &u, &v);
            a[u-1].push_back(v-1);
        }
        tSort();
        cout << endl;
    }
}