#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int LCS(string s, string t) {
        
        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int times = 0;
        int t_left = 0;
        int t_right = 0;
        int t_length = 0;
        int compare = 0;
        string s, t;
        cin >> s >> t;
        while (t_left <= t.length() && t_right <= t.length())
        {
            t_length = t_right - t_left + 1;
            compare = LCS(s, t.substr(t_left, t_right + 1));
            // cout << t.substr(t_left, t_right) << endl;
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