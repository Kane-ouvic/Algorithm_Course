#include <iostream>
#include <unordered_map>
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
        // cout << "-------------1\n";
        qu->erase(time_iter);
        qu->insert(pair<int, int>(*time, a));
        //timers[a - 1] = *time;
        //cout << "test message2 :" << time_iter->first << " "<< time_iter->second << endl;
        
        //cout << "-------------3\n";
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
        // cout << "-------------1\n";
        qu->erase(time_iter);
        qu->insert(pair<int, int>(*time, a));
        //timers[a - 1] = *time;
        //cout << "test message2 :" << time_iter->first << " "<< time_iter->second << endl;
        
        //cout << "-------------3\n";
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
            //timers[a - 1] = *time;
            table->insert(pair<int, node>(a, *tmp));
            (*time)++;
            (*counter)++;
        }
        else
        {
            iter = table->find(qu->begin()->second);
            //cout << "test message 0" << endl;
            //cout << "test message3 :" << iter->second.value << " "<< iter->second.time << endl;
            table->erase(iter);
            //cout << "test message 1" << endl;
            qu->insert(pair<int, int>(*time, a));
            //cout << "test message 2" << endl;
            map<int, int>::iterator qu_iter = qu->begin();
            //cout << "test message1 :" << qu_iter->first << " "<< qu_iter->second << endl;
            qu->erase(qu_iter);
            //cout << "test message 3" << endl;
            node *tmp = createNode(b, *time);

            table->insert(pair<int, node>(a, *tmp));
            (*time)++;
            //cout << "test message 4" << endl;
        }
    }
    // cout << "list size: " << *counter << "/" << n << endl;
    // cout << "map size: " << table->size() << "/" << n << endl;
}
int main()
{
    map<int, node> table;
    // unordered_map<int, int>::iterator iter;
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