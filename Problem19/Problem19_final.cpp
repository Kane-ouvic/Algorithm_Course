#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int result = 1;
        int position = -1;
        int number[26] = {0};
        vector<int> table[26];
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < s.length(); i++)
        {
            ++number[s[i] - 97];
            table[s[i] - 97].push_back(i);
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (!number[t[i] - 97])
            {
                result = -1;
                break;
            }
            else if (position >= table[t[i] - 97][number[t[i] - 97] - 1])
            {
                position = table[t[i] - 97][0];
                ++result;
            }
            else
            {
                position = table[t[i] - 97][upper_bound(table[t[i] - 97].begin(), table[t[i] - 97].end(), position) - table[t[i] - 97].begin()];
            }
        }
        cout << result << endl;
    }
    return 0;
}