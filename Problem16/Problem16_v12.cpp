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
    // multiset<int>::iterator dele;
    itr = records.begin();
    advance(itr, k - 1);
    for (int i = 0; i < n - m + 1; i++)
    {
        counter = *itr;
        cout << *itr << " ";
        records.insert(arr[start + m]);
        if (counter > arr[start + m])
        {
            advance(itr, -1);
        }
        // dele = records.find(arr[start]);
        counter = *itr;
        if (counter >= arr[start])
        {
            advance(itr, 1);
        }
        records.erase(records.find(arr[start]));
        // for (auto test = records.begin(); test != records.end(); test++)
        // {
        //     cout << *test << " ";
        // }
        // cout << endl;
        ++start;
    }
    return 0;
}