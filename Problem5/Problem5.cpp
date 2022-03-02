#include <iostream>
#include <vector>
using namespace std;

int mergeSort(vector<int> *nums, vector<int> *tmp, int l, int r, int *result)
{
    if (l >= r)
        return 0;

    int mid = (l + r) / 2;
    int inv_count = mergeSort(nums, tmp, l, mid, result) + mergeSort(nums, tmp, mid + 1, r, result);
    int i = l, j = mid + 1, pos = l;
    while (i <= mid && j <= r)
    {
        if (nums[i] < nums[j])
        {
            tmp[pos++] = nums->at(i);
            i++;
            inv_count += j - (mid + 1);
            *result += inv_count;
            cout << "test: " << inv_count << endl;
        }
        else
        {
            tmp[pos++] = nums[j];
            j++;
        }
    }
    for (int k = i; k <= mid; k++)
    {
        tmp[pos++] = nums[k];
        inv_count += j - (mid + 1);
        *result += inv_count;
        cout << "test: " << inv_count << endl;
    }
    for (int k = j; k <= r; k++)
    {
        tmp[pos++] = nums[k];
    }
    copy(tmp->begin() + 1, tmp->begin() + r + 1, nums->begin() + l);
    return inv_count;
}

int reverse(vector<int> *nums, int *result)
{
    int n = nums->size();
    vector<int> tmp(n);
    return mergeSort(nums, &tmp, 0, n - 1, result);
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

    reverse(&nums, &result);
    cout << result << endl;

    return 0;
}