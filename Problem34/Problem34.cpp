#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct point
{
    int x;
    int y;
    point *last;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row, col;
    int in;
    int result = 0;
    cin >> row >> col;
    int a[row + 2][col + 1];
    queue<point *> q;
    point *start = new point;
    cin >> start->x >> start->y;
    start->last = start;
    q.push(start);
    a[start->x][start->y] = 2;

    point end;
    cin >> end.x >> end.y;
    for (int i = 1; i < row + 1; i++)
    {
        for (int j = 1; j < col + 1; j++)
        {
            cin >> in;
            a[i][j] = !(in);
        }
    }
    for (int i = 0; i < col + 2; i++)
    {
        a[0][i] = 1;
        a[row + 1][i] = 1;
    }
    for (int i = 1; i < row + 1; i++)
    {
        a[i][0] = 1;
        a[i][col + 1] = 1;
    }
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool flag = 0;
    while (!q.empty())
    {
        point *front = q.front();
        q.pop();
        if (front->x == end.x && front->y == end.y)
        {
            flag = 1;
            a[front->x][front->y] = -1;
            point *lastPoint = front;
            front = front->last;
            while (front->x != start->x || front->y != start->y)
            {
                if (lastPoint->x - front->x == 1)
                    a[front->x][front->y] = -1;
                else if (lastPoint->x - front->x == -1)
                    a[front->x][front->y] = -1;
                else if (lastPoint->y - front->y == 1)
                    a[front->x][front->y] = -1;
                else
                    a[front->x][front->y] = -1;

                lastPoint = front;
                front = front->last;
            }
            a[start->x][start->y] = -1;
            break;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                point *temp = new point;
                temp->x = front->x + dir[i][0];
                temp->y = front->y + dir[i][1];
                if (a[temp->x][temp->y] == 0)
                {
                    temp->last = front;
                    q.push(temp);
                    a[temp->x][temp->y] = a[front->x][front->y] + 1;
                }
            }
        }
    }
    if (flag)
    {
        for (int i = 1; i <= row; i++)
            for (int j = 1; j <= col; j++)
                if (a[i][j] < 0)
                    result++;
    }
    cout << result - 1 << endl;
    return 0;
}