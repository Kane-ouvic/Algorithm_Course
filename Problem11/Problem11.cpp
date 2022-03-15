#include <iostream>
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
    for (i = n - 1; i >= 0; i--) {
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    cin >> n;
    int table[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        table[i] = num;
    }
    radixSort(table, n);
    int maximum = 0;
    for (int i = 0; i < n - 1; ++i)
        maximum = max(maximum, table[i + 1] - table[i]);
    cout << maximum;
    return 0;
}