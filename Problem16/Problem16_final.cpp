#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, m, n;
    cin >> n >> m >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    multiset<int> records(arr, arr + m);
    int start = 0;
    int counter = 0;
    multiset<int>::iterator itr;
    itr = records.begin();
    advance(itr, k - 1);
    for (int i = 0; i < n - m + 1; i++)
    {
        counter = *itr;
        cout << *itr << " ";
        records.insert(arr[start + m]);
        if (counter > arr[start + m])
            advance(itr, -1);
        counter = *itr;
        if (counter >= arr[start])
            advance(itr, 1);
        records.erase(records.find(arr[start]));
        ++start;
    }
    return 0;
}