#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchArr(int arr[], int number, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number)
            return 1;
    }
    return 0;
}

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
    if (n == 1)
    {
        cout << num;
        return 0;
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
    int pre[(size / max_size) + 1 + max_size];
    int pre_i = 0;

    for (int i = 0; i < max_size; i++)
    {
        for (int k = 0; k <= size / max_size + max_size; k++)
        {
            pre[k] = 0;
        }
        pre_i = 0;
        //
        for (int j = 0; j <= (size / max_size) + max_size; j++)
        {
            int index = 0;
            while (index < size && (table.at(index) == -1 || searchArr(pre, table.at(index), (size / max_size) + 1 + max_size)))
            {
                index++;
            }
            if (index < size)
            {
                cout << table.at(index) << " ";
                pre[pre_i++] = table.at(index);
                table.at(index) = -1;
                // cout << index << endl;
            }
            // cout << endl;
            // index++;
        }
        cout << endl;
    }
    // for (int i = 0; i < size; i++)
    // {
    //     if (table.at(i) != -1)
    //         cout << table.at(i) << " ";
    // }
}