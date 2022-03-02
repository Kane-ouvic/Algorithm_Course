#include <iostream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

void GET(map<int, int> *table, int a)
{
    map<int, int>::iterator iter;
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
void SET(map<int, int> *table, list<int> *qu, int a, int b, int n, int *counter)
{
    map<int, int>::iterator iter = table->find(a);

    if (iter != table->end())
    {
        qu->remove(a);
        qu->push_back(a);
        iter->second = b;
    }
    else
    {
        if ((*counter) < n)
        {
            qu->push_back(a);
            table->insert(pair<int, int>(a, b));
            (*counter)++;
        }
        else
        {
            iter = table->begin();
            iter->second = -1;
            qu->pop_front();
            qu->push_back(a);

            //iter = table->find(front);
            
            table->insert(pair<int, int>(a, b));
        }
    }
    //cout << "list size: " << *counter << "/" << n << endl;
    //cout << "map size: " << table->size() << "/" << n << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> table;
    map<int, int>::iterator iter;
    list<int> qu;
    int counter = 0;

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
            GET(&table, a);
        }
        else if (operand == "set")
        {
            int a, b;
            cin >> a >> b;
            SET(&table, &qu, a, b, n, &counter);
        }
    }
    return 0;
}