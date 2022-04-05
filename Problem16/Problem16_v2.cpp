#include <iostream>
#include <algorithm>
using namespace std;

int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
void countSort(int array[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(array[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        array[i] = output[i];
}
void radixSort(int array[], int n)
{
    int m = getMax(array, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(array, n, exp);
}

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
    int start = 0;
    int end = m - 1;
    int counter = 0;
    int temp[m];
    for (int i = 0; i < n - m + 1; i++)
    {

        int t = 0;
        // sort(arr + start, arr + end + 1);
        for (int j = start; j < end + 1; j++)
        {
            temp[t] = arr[j];
            t++;
        }
        radixSort(temp, m);
        t = 0;
        for (int j = start; j < end + 1; j++)
        {
            arr[j] = temp[t];
            t++;
        }
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