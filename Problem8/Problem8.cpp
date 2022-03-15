#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> table;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int number;
        cin >> number;
        table.push_back(number);
    }
    sort(table.begin(), table.end());
    for (int i = 0; i < a; i++)
        cout << table.at(i) << " ";
    return 0;
}