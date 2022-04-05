#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bSearch(list<int> &arr, int search, int l, int r)
{
    list<int>::iterator it = table.begin();
    int low = l;
    int high = r;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == search)
        {
            // cout << "return index: " << mid << endl;
            return mid;
        }
        else if (arr[mid] > search)
        {
            high = mid - 1;
        }
        else if (arr[mid] < search)
        {
            low = mid + 1;
        }
    }
    if (arr[low] <= search)
    {
        return low + 1;
    }
    return low - 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // unordered_map<int, info> table;
    // vector<node> arr;
    int k, m, n;
    int input;

    cin >> n >> m >> k;
    int *arr = new int[n];

    // int records[m];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr[i] = input;
    }
    list<int> table(arr, arr + m);
    int top_index;
    int top = arr[0];

    table.sort();
    //
    list<int>::iterator it = table.begin();
    advance(it, k - 1);
    cout << *it << endl;
    

    return 0;
}