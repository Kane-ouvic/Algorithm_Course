#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    unordered_map<char, int> table;
    for (char c : s)
        ++table[c];
    sort(s.begin(), s.end(), [&table](char a, char b) { return table[a] > table[b] || (table[a] == table[b] && a < b); });
    cout << s;
    return 0;
}