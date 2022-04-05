#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int LCS(char* X, char* Y, int m, int n,
        vector<vector<int> >& dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + LCS(X, Y, m - 1, n - 1, dp);
 
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(LCS(X, Y, m, n - 1, dp), LCS(X, Y, m - 1, n, dp));
}
int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        
        int times = 0;
        int t_left = 0;
        int t_right = 0;
        int t_length = 0;
        int compare = 0;
        char[] s;
        char[] t;
        cin >> s >> t;

        int m = strlen(s);
        int n = strlen(t);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        while (t_left <= t.length() && t_right <= t.length())
        {
            t_length = t_right - t_left + 1;
            compare = LCS(s, t.substr(t_left, t_right + 1), m, n, dp);
            //cout << t.substr(t_left, t_right) << endl;

            if (compare == 0)
            {
                times = -1;
                break;
            }
            if (t_length == compare)
            {
                ++t_right;
            }
            else
            {
                ++times;
                t_left = t_right;
                ++t_right;
                
            }
        }
        cout << times << endl;
    }
    return 0;
}