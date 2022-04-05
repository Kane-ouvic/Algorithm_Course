// CPP program to demonstrate the 
// multiset::find() function 
#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
  
    // Initialize multiset 
    multiset<int> s; 
  
    s.insert(2); 
    s.insert(4); 
    s.insert(3); 
    s.insert(5); 
    s.insert(8); 
    s.insert(1); 
    s.insert(2); 
    s.insert(1); 
  
    cout << "The set elements are: "; 
    for (auto it = s.begin(); it != s.end(); it++) 
        cout << *it << " "; 
  
    // iterator pointing to 
    // position where 2 is 
    auto pos = s.find(2); 
  
    // prints the set elements 
    cout << "\nThe set elements after b are: "; 
    for (auto it = pos; it != s.end(); it++) 
        cout << *it << " "; 
  
    return 0; 
}