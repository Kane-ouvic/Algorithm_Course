#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
int sol(vector<int> const &S)
{
    int sum = accumulate(S.begin(), S.end(), 0);
    bool T[S.size() + 1][sum + 1];
    fill(*T, *T + (S.size() + 1) * (sum + 1), false);
    for (int i = 0; i <= S.size(); i++)
    {
        T[i][0] = true;
        for (int j = 1; i > 0 && j <= sum; j++)
        {
            T[i][j] = T[i - 1][j];
            if (S[i - 1] <= j)
            {
                T[i][j] |= T[i - 1][j - S[i - 1]];
            }
        }
    }
    int j = sum / 2;
    while (j >= 0 && !T[S.size()][j])
    {
        j--;
    }
    return sum - 2 * j;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    vector<int> table;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        table.push_back(a);
    }
    cout << sol(table);
    return 0;
}