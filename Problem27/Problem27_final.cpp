#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int n = nums.size();
    int left[n];
    int right[n];
    left[0] = nums[0];
    int preMax = left[0];
    int max_sum = left[0];
    for (int i = 1; i < n; i++)
    {
        preMax = max(preMax + nums[i], nums[i]);
        max_sum = max(max_sum, preMax);
        left[i] = max_sum;
    }
    right[n - 1] = nums[n - 1];
    preMax = right[n - 1];
    max_sum = right[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        preMax = max(preMax + nums[i], nums[i]);
        max_sum = max(max_sum, preMax);
        right[i] = max_sum;
    }
    int result = INT_MIN;
    for (int i = 0; i < n - 1; i++)
        result = max(result, left[i] + right[i + 1]);
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }
    cout << maxSubArray(nums) << endl;
    return 0;
}