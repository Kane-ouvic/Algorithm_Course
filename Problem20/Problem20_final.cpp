#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(vector<int> v, int k);
int find_MoM(vector<int> v)
{
    if (v.size() == 1)
        return v[0];
    vector<int> medians;
    int index = 0;
    for (int i = 0; i < v.size() / 5; i++)
    {
        vector<int> temp1;
        for (int j = 0; j < 5; j++)
        {
            temp1.push_back(v[index]);
            index++;
        }
        sort(temp1.begin(), temp1.end());
        medians.push_back(temp1[2]);
    }
    vector<int> temp;
    while (index < v.size())
    {
        temp.push_back(v[index]);
        index++;
    }
    sort(temp.begin(), temp.end());
    if (temp.size() != 0)
    {
        if (temp.size() % 2)
        {
            medians.push_back(temp[temp.size() / 2]);
        }
        else
        {
            medians.push_back(temp[temp.size() / 2 - 1]);
        }
    }
    if (medians.size() % 2)
        return partition(medians, medians.size() / 2 + 1);
    else
        return partition(medians, medians.size() / 2);
}
int partition(vector<int> v, int k)
{
    if (v.size() == 1)
         return v[0];
    int pivot = find_MoM(v);
    cout << "pivot: " << pivot << endl;
    vector<int> small;
    vector<int> big;
    for (int i = 0; i < v.size(); i++)
    {
        if (pivot > v[i])
            small.push_back(v[i]);
        if (pivot < v[i])
            big.push_back(v[i]);
    }
    if (k == small.size() + 1)
        return pivot;
    else if (k < small.size() + 1)
        return partition(small, k);
    else
        return partition(big, k - (small.size() + 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> table;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        table.push_back(a);
    }
    int answer;
    if (n % 2)
        answer = partition(table, n / 2 + 1);
    else
        answer = partition(table, n / 2);
    cout << "answer: " << answer;
}