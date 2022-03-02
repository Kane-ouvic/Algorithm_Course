// C++ code
#include <iostream>
#include <vector>

const int Max = 1000;

void Merge(std::vector<int> &Array, int front, int mid, int end, int *result)
{

    // 利用 std::vector 的constructor,
    // 把array[front]~array[mid]放進 LeftSub[]
    // 把array[mid+1]~array[end]放進 RightSub[]
    std::vector<int> LeftSub(Array.begin() + front, Array.begin() + mid + 1),
        RightSub(Array.begin() + mid + 1, Array.begin() + end + 1);

    LeftSub.insert(LeftSub.end(), Max);   // 在LeftSub[]尾端加入值為 Max 的元素
    RightSub.insert(RightSub.end(), Max); // 在RightSub[]尾端加入值為 Max 的元素

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++)
    {

        if (LeftSub[idxLeft] <= RightSub[idxRight])
        {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
            *result += mid - i + 1;
        }
        else
        {
            Array[i] = RightSub[idxRight];
            idxRight++;
            
        }
    }
}

void MergeSort(std::vector<int> &array, int front, int end, int *result)
{
    // front與end為矩陣範圍
    if (front < end)
    {                                           // 表示目前的矩陣範圍是有效的
        int mid = (front + end) / 2;            // mid即是將矩陣對半分的index
        MergeSort(array, front, mid, result);   // 繼續divide矩陣的前半段subarray
        MergeSort(array, mid + 1, end, result); // 繼續divide矩陣的後半段subarray
        Merge(array, front, mid, end, result);  // 將兩個subarray做比較, 並合併出排序後的矩陣
    }
}

void PrintArray(std::vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> array(arr, arr + sizeof(arr) / sizeof(int));
    int result = 0;

    std::cout << "original:\n";
    PrintArray(array);

    MergeSort(array, 0, 7, &result);
    std::cout << "sorted:\n";
    PrintArray(array);
    std::cout << result;

    return 0;
}