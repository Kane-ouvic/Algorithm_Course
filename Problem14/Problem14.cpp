#include <iostream>
using namespace std;
struct cocktail
{
    string name;
    double number;
};
int partition(cocktail cocktails[], int l, int r)
{
    double pivot = cocktails[r].number;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (cocktails[j].number >= pivot)
        {
            ++i;
            swap(cocktails[i], cocktails[j]);
        }
    }
    swap(cocktails[i + 1], cocktails[r]);
    return i + 1;
}
string kthBig(cocktail cocktails[], int l, int r, int k)
{
    int index = partition(cocktails, l, r);
    if (index + 1 == k)
    {
        return cocktails[index].name;
    }
    else if (index + 1 < k)
    {
        kthBig(cocktails, l, index - 1, k);
    } else {
        kthBig(cocktails, index + 1, r, k);
    }
    return "";
}

int main()
{
    int m, n;
    cin >> m >> n;
    double c1, c2, c3;
    string name;
    cocktail cocktails[m];
    for (int i = 0; i < 10; i++)
    {
        cin >> c1 >> c2 >> c3 >> name;
        cocktails[i].name = name;
        cocktails[i].number = (c3) / (c1 + c2 + c3);
    }
    cout << kthBig(cocktails, 0, m - 1, n);
    return 0;
}