#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int index;
    int value;
    bool operator<(const node &compare) const
    {
        return this->value < compare.value;
    }
};

struct info
{
    int times;
    int value;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, m, n;
    int input;
    node *arr = new node[500000];
    info *table = new info[500000];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        node temp;
        temp.index = i;
        temp.value = input;
        arr[i] = temp;
        if (i < n - m + 1)
        {
            table[i].times = 0;
            table[i].value = 0;
        }
    }
    sort(arr, arr + n);
    int j;
    for (int i = 0; i < n; i++)
    {
        j = arr[i].index - m + 1;
        while (j < 0)
            j++;

        for (; j <= arr[i].index; j++)
        {
            if (table[j].times <= k)
                table[j].times++;
            if (table[j].times == k)
                table[j].value = arr[i].value;
        }
    }

    for (int i = 0; i < n - m + 1; i++)
    {
        cout << table[i].value << " ";
    }
    return 0;
}