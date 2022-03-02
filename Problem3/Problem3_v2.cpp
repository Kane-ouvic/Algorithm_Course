#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

void printSet(stack<set<string>> *mainStack)
{
    set<string> tmp_set = mainStack->top();
    cout << tmp_set.size() << endl;
    //cout << "stack size: " << mainStack->size() << endl;
}

void PUSH(stack<set<string>> *mainStack)
{
    set<string> tmp_set = {};
    mainStack->push(tmp_set);
}

void DUP(stack<set<string>> *mainStack)
{
    set<string> tmp_set = mainStack->top();
    //mainStack->pop();
    mainStack->push(tmp_set);
    //cout << "size: " << mainStack->size() << endl;
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
    cout << set1_str << endl;
    //cout << "size: " << mainStack->size() << endl;
}

int main()
{

    int times;
    string operand;
    cin >> times;

    std::stack<set<string>> mainStack;

    for (int i = 0; i < times; i++)
    {

        cin >> operand;
        if (operand == "PUSH")
        {
            //cout << "PUSH" << endl;
            PUSH(&mainStack);
        }
        else if (operand == "DUP")
        {
            //cout << "DUP" << endl;
            DUP(&mainStack);
        }
        else if (operand == "UNION")
        {
            //cout << "UNION" << endl;
            UNION(&mainStack);
        }
        else if (operand == "INTERSECT")
        {
            //cout << "INTERSECT" << endl;
            INTERSECT(&mainStack);
        }
        else if (operand == "ADD")
        {
            //cout << "ADD" << endl;
            ADD(&mainStack);
        }
        printSet(&mainStack);
    }

    return 0;
}