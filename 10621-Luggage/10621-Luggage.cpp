#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n)
    {
        n--;
        string s;
        int num = 0, sum = 0;
        vector<int> weight;
        getline(cin, s);
        s += "\n";
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                num = num * 10 + s[i] - '0';
            else
            {
                weight.push_back(num);
                sum += num;
                num = 0;
            }
        }
        if (sum % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }

        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = sum; j >= weight[i]; j--)
            {
                if (dp[j - weight[i]])
                    dp[j] = true;
            }
        }
        if (dp[sum / 2])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}