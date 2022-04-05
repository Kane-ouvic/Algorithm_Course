#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int l, int r)
{
    int key;
    for (int i = l + 1; i < r + 1; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int bSearch(vector<int> &arr, int search, int l, int r)
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
    vector<int> arr;
    int records[m];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    for (int i = 0; i < m; i++)
    {
        records[i] = arr[i];
    }

    int start = 0;
    int end = m - 1;
    int counter = 0;
    for (int i = 0; i < n - m + 1; i++)
    {
        insertionSort(arr, start, end);

        cout << arr[k + start - 1] << " ";
        // cout << endl;
        // for (int i = 0; i < n; i++)
        //      cout << arr[i] << " ";
        // cout << endl;
        // //
        // for (int i = 0; i < m; i++)
        //     cout << records[i] << " ";
        // cout << endl;
        int index = bSearch(arr, records[counter], start, end);
        swap(arr[start], arr[index]);
        ++start;
        ++end;
        records[counter] = arr[end];
        ++counter;
        counter = counter % m;
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    return 0;
}