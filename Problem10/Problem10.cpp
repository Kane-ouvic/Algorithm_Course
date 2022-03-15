#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{

    int value;
    int table;
    bool operator<(const node &compare) const
    {
        return this->value < compare.value;
    }
};

bool isSubArray(int counters[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (counters[i] <= 0)
            return false;
    }
    return true;
}

void solve(vector<node> &all_data, int counters[], int table_size)
{
    int start = 0;
    int end = 0;
    int min = 0;
    int max = all_data.size()-1;

    while (end < all_data.size())
    {
        if (isSubArray(counters, table_size))
        {
            if (all_data.at(max).value - all_data.at(min).value > all_data.at(end-1).value - all_data.at(start).value)
            {
                max = end-1;
                min = start;
            }
            counters[all_data.at(start).table]--;
            start++;
        }
        else
        {
            counters[all_data.at(end).table]++;
            end++;
        }
    }
    cout << all_data.at(min).value << " " << all_data.at(max).value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<node> all_data;
    int times, amount;
    int data_value;
    cin >> times;
    int counters[times];
    for (int i = 0; i < times; i++)
    {
        cin >> amount;
        counters[i] = 0;
        for (int j = 0; j < amount; j++)
        {
            cin >> data_value;
            node new_data;
            new_data.value = data_value;
            new_data.table = i;
            all_data.push_back(new_data);
        }
    }
    sort(all_data.begin(), all_data.end());
    solve(all_data, counters, times);

    return 0;
}