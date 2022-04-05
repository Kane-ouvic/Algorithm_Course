#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, m, n;
    int input;
    int *arr = new int[500000];
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr[i] = input;
    }
    multiset<int> records(arr, arr + m);

    int start = 0;
    // int end = m - 1;
    int counter = 0;
    multiset<int>::iterator itr;
    for (int i = 0; i < n - m + 1; i++)
    {
        // int pre = arr[start];
        // int next = arr[end + 1];
        itr = records.begin();
        advance(itr, k - 1);
        cout << *itr << " ";
        // cout << *itr << " ";
        for (itr = records.begin(); itr != records.end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
        records.erase(records.find(arr[start]));
        records.insert(arr[start + m]);
        ++start;

        //++end;
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    for (itr = records.begin(); itr != records.end(); itr++)
    {
        cout << *itr << " " << endl;
    }
    return 0;
}