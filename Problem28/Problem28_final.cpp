#include <iostream>
using namespace std;
int solve( int arr[], int n)
{
   int i, j;
   int lis[n];
   for (i = 0; i < n; i++)
      lis[i] = 1;
   for (i = 1; i < n; i++)
      for (j = 0; j < i; j++)
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
   int lds[n];
   for (i = 0; i < n; i++)
      lds[i] = 1;
   for (i = n-2; i >= 0; i--)
      for (j = n-1; j > i; j--)
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;
   int sum = lis[0] + lds[0] - 1;
   for (i = 1; i < n; i++)
       sum = max(sum, lis[i] + lds[i] - 1);
   return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << n - solve(arr, n) << endl;
    return 0;
}