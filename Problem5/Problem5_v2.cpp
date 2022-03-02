#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high, int &c)
{
    int i = low;
    int j = mid + 1;

    vector<int> temp(high - low + 1);
    while (i <= mid && j <= high)
    {
        if (nums[i] > nums[j])
        {
            c += mid - i + 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    i = low;
    j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (nums[i] < nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    while (j <= high)
    {
        temp[k++] = nums[j++];
    }
    for (i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low, int high, int &c)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, c);
        mergeSort(nums, mid + 1, high, c);
        merge(nums, low, mid, high, c);
    }
}

int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    int c = 0;
    mergeSort(nums, 0, n - 1, c);
    return c;
}

int main()
{
    vector<int> nums;
    int amount;
    int result = 0;
    cin >> amount;

    for (int i = 0; i < amount; i++)
    {
        int element;
        cin >> element;
        nums.push_back(element);
    }

    result = reversePairs(nums);
    cout << result%524287 << endl;

    return 0;
}