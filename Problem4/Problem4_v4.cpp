#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct node
{
    int value;
    int time;
};

map<int, node> table;
map<int, int> qu;
int counter = 0;
int time = 0;

node *createNode(int value, int time)
{
    node *tmp = new node;
    tmp->value = value;
    tmp->time = time;
    return tmp;
}

int main()
{

    // unordered_map<int, int>::iterator iter;

    int n, m;
    cin >> n >> m;
    string operand;

    for (int i = 0; i < m; i++)
    {
        cin >> operand;
        if (operand == "get")
        {
            int a;
            cin >> a;
            map<int, node>::iterator iter;
            //
            iter = table.find(a);
            if (iter != table.end())
            {
                cout << iter->second.value << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            //
        }
        else if (operand == "set")
        {
            int a, b;
            cin >> a >> b;
            map<int, node>::iterator iter = table.find(a);

            if (iter != table.end())
            {
                map<int, int>::iterator time_iter = qu.find(iter->second.time);
                // cout << "-------------1\n";
                qu.insert(pair<int, int>(time, a));
                // timers[a - 1] = *time;
                qu.erase(time_iter);
                // out << "-------------3\n";
                iter->second.value = b;
                iter->second.time = time;
                (time)++;
            }
            else
            {
                if ((counter) < n)
                {
                    qu.insert(pair<int, int>(time, a));
                    node *tmp = createNode(b, time);
                    // timers[a - 1] = *time;
                    table.insert(pair<int, node>(a, *tmp));
                    (time)++;
                    (counter)++;
                }
                else
                {
                    iter = table.find(qu.begin()->second);
                    iter->second.value = -1;
                    qu.insert(pair<int, int>(time, a));
                    qu.erase(qu.begin());
                    node *tmp = createNode(b, time);

                    table.insert(pair<int, node>(a, *tmp));
                    (time)++;
                }
            }
        }
    }
    return 0;
}