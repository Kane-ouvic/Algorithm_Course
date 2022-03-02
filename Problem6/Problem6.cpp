#include <iostream>
#include <algorithm>
using namespace std;

void comb(int n, int r, int m, int array[])
{

    // int i;
    if (n < r)
        return;

    if (r == 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        array[m] = n;
        comb(n - 1, r, m, array);
        comb(n - 1, r - 1, m + 1, array);
    }
}

int main()
{
    int times, input;
    cin >> times;
    int nums[times];
    for (int i = 0; i < times; i++)
    {
        cin >> input;
        nums[i] = input;
    }
    //sort(nums, nums + times);
    comb(times, 6, 6, nums);
}