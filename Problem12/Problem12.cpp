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
    sort(s.begin(), s.end(), [&table](char a, char b)
         { 
             if(table[a] > table[b]){
                 return true;
             } else if(table[a] == table[b]){
                 int c1 = a;
                 int c2 = b;
                 if(c1 >= 97)
                     c1 -= 32;
                 else if(c1 <= 57)
                     c1 += 100;
                 if(c2 >= 97)
                     c2 -= 32;
                 else if(c2 <= 57)
                     c2 += 100;
                 if(c1 < c2){
                     return true;
                 } else if(c1 == c2){
                     return a < b;
                 } else {
                     return false;
                 }
             } else {
                 return false;
             }});
    cout << s << endl;
    return 0;
}