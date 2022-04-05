#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int LCS(string str1, string str2)
{
    if (str1.length() == 0 || str2.length() == 0)
    {
        return 0;
    }
    else
    {
        if (str1[str1.length() - 1] == str2[str2.length() - 1])
        {
            return (1 + LCS(str1.substr(0, str1.length() - 1), str2.substr(0, str2.length() - 1)));
        }
        else
        {
            return max(LCS(str1.substr(0, str1.length() - 1), str2), LCS(str2, str1.substr(0, str2.length() - 1)));
        }
    }
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