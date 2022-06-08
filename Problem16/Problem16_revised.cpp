#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, m, n, s = 0;
    cin >> n >> m >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> r(a, a + m);
    auto it = r.begin();
    advance(it, k - 1);
    for (int i = 0; i < n - m + 1; i++)
    {
        cout << *it << " ";
        r.insert(a[s + m]);
        if (*it > a[s + m])
            it--;
        if (*it >= a[s])
            it++;
        r.erase(r.find(a[s]));
        ++s;
    }
}