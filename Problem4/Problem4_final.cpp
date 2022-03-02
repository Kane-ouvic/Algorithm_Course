#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct node
{
    int value;
    int time;
};

node *createNode(int value, int time)
{
    node *tmp = new node;
    tmp->value = value;
    tmp->time = time;
    return tmp;
}

void GET(map<int, node> *table, map<int, int> *qu, int a, int *time)
{
    map<int, node>::iterator iter;
    iter = table->find(a);
    if (iter != table->end())
    {
        cout << iter->second.value << endl;
        map<int, int>::iterator time_iter = qu->find(iter->second.time);
        qu->erase(time_iter);
        qu->insert(pair<int, int>(*time, a));
        iter->second.time = *time;
        (*time)++;
    }

    else
    {
        cout << -1 << endl;
    }
}
void SET(map<int, node> *table, map<int, int> *qu, int a, int b, int n, int *counter, int *time)
{
    map<int, node>::iterator iter = table->find(a);

    if (iter != table->end())
    {
        map<int, int>::iterator time_iter = qu->find(iter->second.time);
        qu->erase(time_iter);
        qu->insert(pair<int, int>(*time, a));
        iter->second.value = b;
        iter->second.time = *time;
        (*time)++;
        
    }
    else
    {
        if ((*counter) < n)
        {
            qu->insert(pair<int, int>(*time, a));
            node *tmp = createNode(b, *time);
            table->insert(pair<int, node>(a, *tmp));
            (*time)++;
            (*counter)++;
        }
        else
        {
            iter = table->find(qu->begin()->second);
            table->erase(iter);
            qu->insert(pair<int, int>(*time, a));
            map<int, int>::iterator qu_iter = qu->begin();
            qu->erase(qu_iter);
            node *tmp = createNode(b, *time);
            table->insert(pair<int, node>(a, *tmp));
            (*time)++;
        }
    }
}
int main()
{
    map<int, node> table;
    map<int, int> qu;
    int counter = 0;
    int time = 0;
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
            GET(&table, &qu, a, &time);
        }
        else if (operand == "set")
        {
            int a, b;
            cin >> a >> b;
            SET(&table, &qu, a, b, n, &counter, &time);
        }
    }
    return 0;
}