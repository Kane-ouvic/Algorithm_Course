#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

void GET(unordered_map<int, int> *table, int a)
{
    unordered_map<int, int>::iterator iter;
    iter = table->find(a);
    if (iter != table->end())
    {
        cout << iter->second << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
void SET(unordered_map<int, int> *table, map<int, int> *qu, int a, int b, int n, int *counter, int *time, int timers[])
{
    unordered_map<int, int>::iterator iter = table->find(a);

    if (iter != table->end())
    {
        map<int, int>::iterator time_iter = qu->find(timers[a - 1]);
        //cout << "-------------1\n";
        qu->insert(pair<int, int>(*time, a));
        timers[a - 1] = *time;
        qu->erase(time_iter);
        //cout << "-------------3\n";
        (*time)++;
        iter->second = b;
    }
    else
    {
        if ((*counter) < n)
        {
            qu->insert(pair<int, int>(*time, a));
            timers[a - 1] = *time;
            table->insert(pair<int, int>(a, b));
            (*time)++;
            (*counter)++;
        }
        else
        {
            iter = table->find(qu->begin()->second);
            iter->second = -1;
            qu->insert(pair<int, int>(*time, a));
            timers[a - 1] = *time;
            qu->erase(qu->begin());
            (*time)++;
            // iter = table->find(front);

            table->insert(pair<int, int>(a, b));
        }
    }
    // cout << "list size: " << *counter << "/" << n << endl;
    // cout << "map size: " << table->size() << "/" << n << endl;
}
int main()
{
    unordered_map<int, int> table;
    //unordered_map<int, int>::iterator iter;
    map<int, int> qu;
    int counter = 0;
    int time = 0;

    int n, m;
    cin >> n >> m;
    string operand;

    int timers[n];
    for (int i = 0; i < m; i++)
    {
        cin >> operand;
        if (operand == "get")
        {
            int a;
            cin >> a;
            GET(&table, a);
        }
        else if (operand == "set")
        {
            int a, b;
            cin >> a >> b;
            SET(&table, &qu, a, b, n, &counter, &time, timers);
        }
    }
    return 0;
}