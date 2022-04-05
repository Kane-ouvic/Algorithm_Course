#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> table;
    int n;
    int num;
    cin >> n;
    // int size;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        table.push_back(num);
    }
    sort(table.begin(), table.end());

    int counter = 1;
    int max_size = 0;
    int size = table.size();
    for (int i = 0; i < table.size() - 1; i++)
    {
        if (table.at(i) == table.at(i + 1))
        {
            counter++;
        }
        else
        {
            counter = 1;
        }
        max_size = max(max_size, counter);
    }
    // cout << max_size << endl;
    int pre = 0;
    for (int i = 0; i < max_size; i++)
    {
        pre = 0;
        for (int j = 0; j <= (size / max_size); j++)
        {
            int index = 0;
            while (index < size && (table.at(index) == -1 || pre == table.at(index)))
            {
                index++;
            }
            if (index < size)
            {
                cout << table.at(index) << " ";
                pre = table.at(index);
                table.at(index) = -1;
                //cout << index << endl;
            }
            //cout << endl;
            //index++;
        }
        cout << endl;
    }
    // for (int i = 0; i < size; i++)
    // {
    //     if (table.at(i) != -1)
    //         cout << table.at(i) << " ";
    // }
}