#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int l, int m, int r, int *c){

    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1];
    int R[n2];

    for(i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }
    for(j = 0; j < n2; j++){
        R[j] = arr[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            *c += m - i + 1;
            cout << *c << " " << m << endl;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int *arr, int l, int r, int *c){

    if(l < r){

        int m = (r+l)/2;
        mergeSort(arr, l, m, c);
        mergeSort(arr, m + 1, r, c);
        merge(arr, l, m, r, c);
    }
}


int main()
{
    vector<int> nums;
    int amount;
    int result = 0;
    int c = 0;
    cin >> amount;
    int array[amount];

    for (int i = 0; i < amount; i++)
    {
        int element;
        cin >> element;
        array[i] = element;
    }
    mergeSort(array, 0, amount - 1, &c);
    cout << c << endl;

    for (int i = 0; i < amount; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}