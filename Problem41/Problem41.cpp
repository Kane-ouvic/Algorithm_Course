#include <bits/stdc++.h>
using namespace std;
vector<int> parent, size;
int find(int x)
{
    if (x == parent[x])
        return x;
    return find(parent[x]);
}
int unions(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return 1;
    }
    return 0;
}
void MST(int points[][2], int n)
{
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int p = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            v.push_back({p, {i, j}});
        }
    }
    parent.resize(n);
    size.resize(n);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    int result = 0;
    for (auto i : v)
    {
        if (unions(i.second.first, i.second.second))
            result += i.first;
    }
    cout << result;
}
int main()
{
    int n;
    cin >> n;
    int points[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
    MST(points, n);
    return 0;
}