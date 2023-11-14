#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool notprime[10001] = {false};
    vector<int> prime;
    int n;

    for (int i = 2; i <= 10000; i++) // prime list
    {
        if (!notprime[i])
        {

            for (int j = i * i; j <= 10000; j += i)
                notprime[j] = true;
            prime.push_back(i);
        }
    }

    while (cin >> n && n)
    {
        int count = 0;
        for (int i = 0; prime[i] <= n; i++)
        {
            int sum = 0;
            for (int j = i; sum < n; j++)
            {
                sum += prime[j];
                if (sum == n)
                    count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}