#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int bSearch(int arr[], int search, int l, int r)
{
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
    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, m, n;
    int input;
    cin >> n >> m >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr[i] = input;
    }
    multiset<int> records(arr, arr + m);

    int start = 0;
    int end = m - 1;
    int counter = 0;
    multiset<int>::iterator itr;
    for (int i = 0; i < n - m + 1; i++)
    {
        //int pre = arr[start];
        //int next = arr[end + 1];
        itr = records.begin();
        advance(itr, k - 1);
        cout << *itr << " ";
        records.erase(records.find(arr[start]));
        records.insert(arr[end + 1]);
        ++start;
        ++end;
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    return 0;
}