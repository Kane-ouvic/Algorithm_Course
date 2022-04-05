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
    multiset<int>::iterator de;

    itr = records.begin();
    advance(itr, k - 1);
    for (int i = 0; i < n - m + 1; i++)
    {
        counter = *itr;
        cout << *itr << " ";

        // for (de = records.begin(); de != records.end(); de++)
        // {
        //       cout << *de << " ";
        // }

        if (arr[start] <= counter)
        {
            if (itr != records.end())
                advance(itr, 1);
        }
        if (itr == records.find(arr[start]))
        {
            advance(itr, 1);
        }
        records.erase(records.find(arr[start]));
        records.insert(arr[start + m]);

        if (arr[start + m] <= counter)
        {
            if (itr != records.begin())
                advance(itr, -1);
        }
        // advance(itr, -1);

        // cout << endl;
        ++start;
    }
    return 0;
}