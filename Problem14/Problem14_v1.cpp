#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cocktail
{
    string name;
    double number;
    bool operator<(const cocktail &compare) const
    {
        return this->number > compare.number;
    }
};

int main(void)
{
    int m, n;
    double a, b, c;
    string s;
    cin >> m >> n;
    vector<cocktail> all_data;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> s;
        cocktail new_data;
        new_data.name = s;
        new_data.number = (c) / (a + b + c);
        all_data.push_back(new_data);
    }
    sort(all_data.begin(), all_data.end());
    cout << all_data.at(n - 1).name;
    return 0;
}