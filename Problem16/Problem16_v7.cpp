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

int getMax(node array[], int n)
{
    int max = array[0].value;
    for (int i = 1; i < n; i++)
        if (array[i].value > max)
            max = array[i].value;
    return max;
}
void countSort(node array[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(array[i].value / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i].value / exp) % 10] - 1] = array[i].value;
        count[(array[i].value / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        array[i].value = output[i];
}
void radixSort(node array[], int n)
{
    int m = getMax(array, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(array, n, exp);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // unordered_map<int, info> table;
    // vector<node> arr;
    int k, m, n;
    int input;
    node *arr = new node[500000];
    info *table = new info[500000];
    cin >> n >> m >> k;

    // int records[m];
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
    radixSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        int t_index = arr[i].index;
        int j = t_index - m + 1;
        while (j < 0)
            j++;

        for (; j <= t_index; j++)
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