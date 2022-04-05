#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> table;
    unordered_map<string, int> counter;
    int m, n;
    cin >> m >> n;
    string s;
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        if(counter[s] == 0)
            table.push_back(s);
        ++counter[s];
    }
    sort(table.begin(), table.end(), [&counter](string a, string b) { return counter[a] > counter[b] || (counter[a] == counter[b] && a < b); });
    cout << table.at(n-1) << endl;
    return 0;
}
