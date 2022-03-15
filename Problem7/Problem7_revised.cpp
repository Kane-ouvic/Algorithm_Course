#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct point
{
    int x, y, index;

    //排序判斷式
    bool operator<(const point &compare) const
    {
        if (this->x != compare.x)
            return this->x < compare.x;
        return this->y < compare.y;
    }
};
void solve(int left, int right, point points[], point save[], int result[])
{
    //切到1個點的時候直接return
    if (right - left <= 1)
        return;
    int middle = left + (right - left) / 2;
    int counter = 0;
    int i = left;
    int j = middle;
    int k = left;

    //Divide
    solve(left, middle, points, save, result);
    solve(middle, right, points, save, result);

    //Conquer
    while (i < middle || j < right)
    {
        if (i == middle)
        {
            save[k] = points[j];
            result[save[k].index] += counter;
            j++;
        }
        else if (j == right)
        {
            save[k] = points[i];
            i++;
        }
        else if (points[i].y <= points[j].y) //支配點
        {
            save[k] = points[i];
            counter++;
            i++;
        }
        else // points[i].y > points[j].y
        {
            save[k] = points[j];
            result[save[k].index] += counter;
            j++;
        }
        k++;
    }
    //Merge
    for (i = left; i < right; i++)
    {
        points[i] = save[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int amount;
    cin >> amount;
    point points[amount], save[amount];
    int result[amount];
    memset(result, 0, sizeof(result));
    for (int i = 0; i < amount; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].index = i;
    }
    sort(points, points + amount);
    solve(0, amount, points, save, result);
    for (int i = 0; i < amount; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}