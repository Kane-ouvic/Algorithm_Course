#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int sol(int W, int wt[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = W; j >= wt[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }
    return dp[W];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, t, W;
    cin >> n >> W;
    int val[n];
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        val[i] = s;
        wt[i] = t;
    }
    cout << sol(W, wt, val, n);
    return 0;
}