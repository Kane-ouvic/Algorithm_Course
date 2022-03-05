#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums, int low, int mid, int high, long int &c)
{
    int i = low;
    int j = mid + 1;
    vector<int> temp(high - low + 1);
    i = low;
    j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
            c += mid - i + 1;
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
void mergeSort(vector<int> &nums, int low, int high, long int &c)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid, c);
        mergeSort(nums, mid + 1, high, c);
        merge(nums, low, mid, high, c);
    }
}
long int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    long int c = 0;
    mergeSort(nums, 0, n - 1, c);
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int amount;
    vector<int> nums;
    cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        int element;
        cin >> element;
        nums.push_back(element);
    }
    cout << reversePairs(nums) % 524287;
    return 0;
}