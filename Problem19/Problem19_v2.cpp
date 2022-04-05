#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string str1, string str2)
{
  int length1 = str1.size();
  int lenght2 = str2.size();
  int dp[length1 + 1][lenght2 + 1];
  for (int i = 0; i <= length1; i++)
    {
    for (int j = 0; j <= lenght2; j++)
	{
	    if (i == 0 || j == 0)
	         {
	              dp[i][j] = 0;
		 }
	     else if (str1[length1 - i] == str2[lenght2 - j])
	           {
	                dp[i][j] = 1 + dp[i - 1][j - 1];
	               }
	      else
		 {
	      int a = dp[i - 1][j];
               int b = dp[i][j - 1];
               int c = dp[i - 1][j - 1];
               dp[i][j] = max(a, max(b, c));
			}
		}
	}
   return dp[length1][lenght2];
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