#include <bits/stdc++.h>
using namespace std;
void comb(vector<vector<int>> &result, vector<int> &tmp, int n, int left, int k)
{
    if (k == 0)
    {
        result.push_back(tmp);
        return;
    }
    for (int i = left; i <= n; i++)
    {
        tmp.push_back(i);
        comb(result, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}
void printResult(int a[], vector<vector<int>> &result)
{
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << a[result.at(i).at(j) - 1] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    vector<vector<int>> result;
    vector<int> tmp;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[i] = num;
    }
    comb(result, tmp, n, 1, 6);
    printResult(a, result);
    return 0;
}