#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int partition_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
            //cout << "return index: " << mid << endl;
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
        if(i < m)
             records[i] = arr[i];
    }

    int start = 0;
    int end = m - 1;
    int counter = 0;
    for (int i = 0; i < n - m + 1; i++)
    {
        quickSort(arr, start, end);
        //sort(arr + start, arr + end + 1);

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
        counter = counter%m;
    }
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    return 0;
}