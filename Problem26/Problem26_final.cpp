#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int max_sum = INT_MIN;
    int t = 1;
    int e = 1;
    int s = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum < 0)
        {
            sum = 0;
            t = i + 1;
        }
        sum += nums[i];
        if (max_sum < sum)
        {
            max_sum = sum;
            s = t;
            e = i + 1;
        }
    }
    cout << max_sum << " " << s << " " << e << endl;
    return max_sum;
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
    maxSubArray(nums);
    return 0;
}