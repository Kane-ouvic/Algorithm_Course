#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

struct node
{
    set<int> tmpSet;
};

void test_fun1(set<string> *testset)
{
    testset->insert("sdad");
    testset->insert("sdfsadsa");
}

void test_fun2(set<string> *testset)
{
    testset->insert("sdad");
    testset->insert("sdfsadsasdadsa");
}

int main()
{

    std::stack<set<int>> myStack;

    std::set<string> *myset1 = new set<string>;
    std::set<string> *myset2 = new set<string>;

    set<string> myset;
    node test_node1;
    string tstr = "()";

    test_fun1(myset1);
    test_fun2(myset2);
    set_union(myset1->begin(), myset1->end(), myset2->begin(), myset2->end(), inserter(myset, myset.begin()));

    // myset.insert(test_node1);
    // myset.insert(test_node1);
    // myset.insert(test_node1);
    // myset.insert(test_node1);

    cout << myset.size() << endl;


    return 0;
}