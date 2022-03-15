#include <iostream>
#include <algorithm>
using namespace std;

struct cocktail
{
    int location;
    int con;

    bool operator<(const cocktail &compare) const
    {
        return this->location < compare.location;
    }
};

int getDiff(int a, int b)
{
    if (a - b > 0)
        return a - b;
    else
        return b - a;
}

int printResult(int location, int con, int index, cocktail all_cocktail[], int size)
{
    int left;
    int right;
    int result = -1;

    if (location == all_cocktail[index].location)
    {
        if (con <= all_cocktail[index].con)
        {
            result = all_cocktail[index].location;
            return result;
        }
        left = index - 1;
        right = index + 1;
        //
        // while (left >= 0 || right < size)
        // {
        //     if ((getDiff(location, all_cocktail[left].location) <= getDiff(location, all_cocktail[right].location)) && left >= 0)
        //     {
        //         if (con <= all_cocktail[left].con)
        //         {
        //             result = all_cocktail[left].con;
        //             return result;
        //         }
        //         --left;
        //     }
        //     else if ((getDiff(location, all_cocktail[left].location) > getDiff(location, all_cocktail[right].location)) && right < size)
        //     {
        //         if (con <= all_cocktail[right].con)
        //         {
        //             result = all_cocktail[right].con;
        //             return result;
        //         }
        //         ++right;
        //     }
        // }
        //
    }
    else if (location > all_cocktail[index].location)
    {
        left = index;
        right = index + 1;
    }
    else
    {
        left = index - 1;
        right = index;
    }
    //
    while (left >= 0 || right < size)
    {
        if ((getDiff(location, all_cocktail[left].location) <= getDiff(location, all_cocktail[right].location)) && left >= 0)
        {
            if (con <= all_cocktail[left].con)
            {
                result = all_cocktail[left].location;
                return result;
            }
            --left;
        }
        else if ((getDiff(location, all_cocktail[left].location) > getDiff(location, all_cocktail[right].location)) && right < size)
        {
            if (con <= all_cocktail[right].con)
            {
                result = all_cocktail[right].location;
                return result;
            }
            ++right;
        }
    }
    return result;
}

int search(int start, int end, int location, int con, cocktail all_cocktail[], int size)
{
    int mid = start + (end - start) / 2;
    if (start >= end)
    {
        // cout << "--------------1" << endl;
        return printResult(location, con, mid, all_cocktail, size);
        
    }

    if (location > all_cocktail[mid].location)
    {
        // cout << "--------------2" << endl;
        return search(mid + 1, end, location, con, all_cocktail, size);
    }
    else if (location < all_cocktail[mid].location)
    {
        // cout << "--------------3" << endl;
        return search(start, mid - 1, location, con, all_cocktail, size);
    }
    else
    {
        //cout << "--------------4" << endl;
        return printResult(location, con, mid, all_cocktail, size);
    }
}

int main()
{
    // cocktail all_cocktail[];
    int n, m;
    cin >> n >> m;
    cocktail all_cocktail[n];
    for (int i = 0; i < n; ++i)
        cin >> all_cocktail[i].location >> all_cocktail[i].con;
    sort(all_cocktail, all_cocktail + n);
    int location, con;
    for (int i = 0; i < m; ++i)
    {
        // cout << "--------------" << endl;
        cin >> location >> con;
        cout << search(0, n - 1, location, con, all_cocktail, n) << endl;
    }
    return 0;
}