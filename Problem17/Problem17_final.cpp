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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> table;
    int n;
    int num;
    cin >> n;
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
    int result[max_size][size / max_size + 1];
    int index = 0;
    for (int i = 0; i < max_size; i++)
    {
        for (int j = 0; j < size / max_size + 1; j++)
        {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < size / max_size + 1; i++)
    {
        for (int j = 0; j < max_size; j++)
        {
            if (index >= size)
                break;
            result[j][i] = table.at(index);
            ++index;
        }
    }
    for (int i = 0; i < max_size; i++)
    {
        for (int j = 0; j < size / max_size + 1; j++)
        {
            if (result[i][j] != 0)
                cout << result[i][j] << " ";
        }
        cout << endl;
    }
}