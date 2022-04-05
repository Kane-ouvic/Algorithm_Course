#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, result = 0;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        vector<int> table;
        int n, w;
        char c;
        int location;
        cin >> n >> w;
        result = 0;
        map<int, int>counter;

        table.push_back(0);
        for (int j = 0; j < n; j++)
        {
            cin >> c >> location;
            if (c == 'b')
            {
                table.push_back(location);
                // cout << "in" << endl;
            }
            else if (c == 's')
            {
                counter[location]++;
                if(counter[location] >= 2)
                    table.push_back(location);
            }
        }
        table.push_back(w);
        for (int j = 0; j + 1 < table.size(); j++)
        {
            result = max(result, table.at(j + 1) - table.at(j));
            // cout << table.at(j + 1) - table.at(j) << endl;
        }
        cout << result << endl;
        //table.clear();
    }
    return 0;
}