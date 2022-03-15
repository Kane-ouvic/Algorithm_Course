#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int array[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] < array[smallest])
        smallest = left;
    if (right < n && array[right] < array[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&array[i], &array[smallest]);
        heapify(array, n, smallest);
    }
}
void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int amount;
    cin >> amount;
    int array[amount];
    for (int i = 0; i < amount; i++)
    {
        int number;
        cin >> number;
        array[i] = number;
    }
    for(int i = amount/2-1; i >= 0; i--){
        heapify(array, amount, i);
    }	
    printArray(array, amount);

    return 0;
}