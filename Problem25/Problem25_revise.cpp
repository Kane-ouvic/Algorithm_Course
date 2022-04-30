#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct data
{
    int s;
    int d;
    int t;
    bool operator<(const data &compare) const
    {
        return this->d < compare.d;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<data> table;
    data input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input.s >> input.d  >> input.t;
        table.push_back(input);
    }
    sort(table.begin(), table.end());
    int d_size = table[n - 1].d;
    int B[2][d_size + 1];
    memset(B[0], 0, sizeof(B[0]));
    int t_;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        c = i % 2;
        for (int j = 0; j <= d_size; j++)
        {
            t_ = min(j, table[i-1].d) - table[i-1].t;
            if(t_ < 0)
                B[c][j] = B[!c][j];
            else
                B[c][j] = max(B[!c][j], table[i-1].s + B[!c][t_]);
        }
    }
    cout << B[c][d_size] << endl;
    return 0;
}