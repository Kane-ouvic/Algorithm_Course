#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct data
{
    int sc;
    int de;
    int ti;
    bool operator<(const data &compare) const
    {
        return this->de < compare.de;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, d, t;
    vector<data> table;
    data input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> d >> t;
        input.sc = s;
        input.de = d;
        input.ti = t;
        table.push_back(input);
    }
    sort(table.begin(), table.end());
    int d_size = table[n - 1].de;
    int B[2][d_size + 1];
    memset(B[0], 0, sizeof(B[0]));
    int t_;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        c = i % 2;
        for (int j = 0; j <= d_size; j++)
        {
            t_ = min(j, table[i-1].de) - table[i-1].ti;
            if(t_ < 0)
                B[c][j] = B[!c][j];
            else
                B[c][j] = max(B[!c][j], table[i-1].sc + B[!c][t_]);
        }
    }
    cout << B[c][d_size] << endl;
    return 0;
}