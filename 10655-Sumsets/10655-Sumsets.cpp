#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int find(vector<int> set) // 暴力法
{
    for (int d = set.size() - 1; d >= 0; d--) // 從最大的d開始找
    {
        for (int a = 0; a < set.size(); a++)
        {
            for (int b = a + 1; b < set.size(); b++)
            {
                for (int c = b + 1; c < set.size(); c++)
                {
                    if (set[a] + set[b] + set[c] == set[d])
                        return set[d];
                }
            }
        }
    }
    return INT_MAX;
};

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> set;
        while (n)
        {
            int element;
            cin >> element;
            set.push_back(element);
            n--;
        }
        sort(set.begin(), set.end());
        int rtn = find(set);
        if (rtn == INT_MAX)
            cout << "no solution";
        else
            cout << rtn;
    }

    return 0;
}