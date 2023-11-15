#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

long long dp[30005] = {1};
int money[] = {10000, 5000, 2000, 1000, 500,
               200, 100, 50, 20, 10, 5};

int main()
{
    for (int i = 10; i >= 0; i--)
    {
        for (int j = money[i]; j <= 30000; j++)
        {
            dp[j] += dp[j - money[i]];
        }
    }
    int x, y;
    char z;
    while (cin >> x >> z >> y)
    {
        if (x == 0 && y == 0)
            break;
        if (y == 0)
            cout << x << "." << y << "0" << right << setw(17) << dp[100 * x + y] << endl;
        else if (y < 10)
            cout << x << ".0" << y << right << setw(17) << dp[100 * x + y] << endl;
        else
            cout << x << "." << y << right << setw(17) << dp[100 * x + y] << endl;
    }

    return 0;
}