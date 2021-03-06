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
point points[300000], save[300000];
int result[300000];
void solve(int left, int right)
{
    //切到1個點的時候直接結束
    if (right - left <= 1)
        return;
    int middle = left + (right - left) / 2;
    int counter = 0;
    int i = left;
    int j = middle;
    int k = left;

    //Divide
    solve(left, middle);
    solve(middle, right);

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
        else if (points[i].y <= points[j].y)
        {
            save[k] = points[i];
            counter++;
            i++;
        }
        else
        {
            save[k] = points[j];
            result[save[k].index] += counter;
            j++;
        }
        k++;
    }
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
    memset(result, 0, sizeof(result));
    for (int i = 0; i < amount; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].index = i;
    }
    sort(points, points + amount);
    solve(0, amount);
    for (int i = 0; i < amount; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}