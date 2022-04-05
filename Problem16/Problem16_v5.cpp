#include <iostream>
using namespace std;

int partition(int arr[], int l, int r, int *top_index, int *top)
{
    int pivot = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; ++i)
    {
        //
        if (arr[i] < pivot)
        {
            swap(arr[++j], arr[i]);

            if (arr[j] == *top)
                *top_index = j;
            if (arr[i] == *top)
                *top_index = i;
        }
    }
    swap(arr[l], arr[j]);

    if (arr[l] == *top)
    {
        *top_index = l;
    }
    if (arr[j] == *top)
    {
        *top_index = j;
    }
    //
    //cout << "top: " << *top << endl;
    return j;
}

int quickSelect(int arr[], int l, int r, int k, int *top_index, int *top)
{
    int s = partition(arr, l, r, top_index, top);
    if (s == l + k - 1)
    {
        return arr[s];
    }
    else if (s > (l + k - 1))
    {
        return quickSelect(arr, l, s - 1, k, top_index, top);
    }
    else
    {
        return quickSelect(arr, s + 1, r, k - (s - l + 1), top_index, top);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, m, n;
    int input;
    cin >> n >> m >> k;
    int arr[n];
    int records[m];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr[i] = input;
    }
    for (int i = 0; i < m; i++)
    {
        records[i] = arr[i];
    }
    int counter = 0;
    int start = 0;
    int end = m - 1;

    // int temp[m];
    int top_index = 0;
    int top = 0;
    for (int i = 0; i < n - m + 1; i++)
    {
        top_index = start;
        cout << quickSelect(arr, start, end, k, &top_index, &records[counter % m]) << " ";
        swap(arr[start], arr[top_index]);
        //cout << start << " " << top_index << " " << end << endl;
        records[counter % m] = arr[end + 1];
        // for (int j = 0; j < m; j++)
        //     cout << records[j] << " ";
        // cout << endl;
        ++counter;
        ++start;
        ++end;
    }
    //dubug
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    return 0;
}