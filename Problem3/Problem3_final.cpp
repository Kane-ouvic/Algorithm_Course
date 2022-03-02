#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
void printSet(stack<set<string>> *mainStack)
{
    set<string> tmp_set = mainStack->top();
    cout << tmp_set.size() << endl;
}
void PUSH(stack<set<string>> *mainStack)
{
    set<string> tmp_set = {};
    mainStack->push(tmp_set);
}
void DUP(stack<set<string>> *mainStack)
{
    set<string> tmp_set = mainStack->top();
    mainStack->push(tmp_set);
}
void UNION(stack<set<string>> *mainStack)
{
    set<string> set1 = mainStack->top();
    mainStack->pop();
    set<string> set2 = mainStack->top();
    mainStack->pop();
    set<string> union_set;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(union_set, union_set.begin()));
    mainStack->push(union_set);
}
void INTERSECT(stack<set<string>> *mainStack)
{
    set<string> set1 = mainStack->top();
    mainStack->pop();
    set<string> set2 = mainStack->top();
    mainStack->pop();
    set<string> intersect_set;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersect_set, intersect_set.begin()));
    mainStack->push(intersect_set);
}
void ADD(stack<set<string>> *mainStack)
{
    set<string> set1 = mainStack->top();
    mainStack->pop();
    set<string> set2 = mainStack->top();
    mainStack->pop();

    string set1_str = "";
    set1_str += "(";
    for (const auto &s : set1)
    {
        set1_str += s;
    }
    set1_str += ")";
    set2.insert(set1_str);
    mainStack->push(set2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int times;
    string operand;
    cin >> times;
    std::stack<set<string>> mainStack;
    for (int i = 0; i < times; i++)
    {
        cin >> operand;
        if (operand == "PUSH")
        {
            PUSH(&mainStack);
        }
        else if (operand == "DUP")
        {
            DUP(&mainStack);
        }
        else if (operand == "UNION")
        {
            UNION(&mainStack);
        }
        else if (operand == "INTERSECT")
        {
            INTERSECT(&mainStack);
        }
        else if (operand == "ADD")
        {
            ADD(&mainStack);
        }
        printSet(&mainStack);
    }
    return 0;
}