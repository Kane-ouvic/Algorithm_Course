#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stone
{
    char type;
    int location;
    int simped;
};
stone createStone(char type, int location)
{
    stone temp;
    temp.type = type;
    temp.location = location;
    switch (type)
    {
    case 'b':
        temp.simped = -1;
        break;
    case 's':
        temp.simped = 1;
        break;
    }
    return temp;
}
void solve(vector<stone> &river)
{
    int now = 0;
    int next = 1;
    int result = 0;
    int length = 0;
    bool pre = false;
    int size = river.size();
    while (now < size && next < size)
    {
        if (river.at(next).type == 'b')
        {
            length = river.at(next).location - river.at(now).location;
            now = next;
            pre = false;
        }
        else if (river.at(next).type == 's')
        {
            if (pre)
            {
                length = river.at(next).location - river.at(now).location;
                now = next;
                river.at(now).simped--;
            }
            pre = !pre;
            
        }
        next++;
        result = max(result, length);
    }
    now = size - 1;
    next = now - 1;
    while (now >= 0 && next >= 0)
    {
        if (river.at(next).type == 'b')
        {
            length = river.at(next).location - river.at(now).location;
            now = next;
        }
        else if (river.at(next).type == 's')
        {
            if (river.at(next).simped)
            {
                length = river.at(now).location - river.at(next).location;
                now = next;
            }
        }
        next--;
        result = max(result, length);
    }
    cout << result << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<stone> river;
    int t;
    int n, w;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        char type;
        int location;
        cin >> n >> w;
        river.push_back(createStone('b', 0));
        for (int j = 0; j < n; j++)
        {
            cin >> type >> location;
            river.push_back(createStone(type, location));
        }
        river.push_back(createStone('b', w));
        solve(river);
        river.clear();
    }
    return 0;
}