#include <iostream>
#include <vector>
using namespace std;

int main()
{
    while (1)
    {
        int n, m;
        cin >> n >> m;
        vector<int> status, k;

        for (int i = 0; i < m; i++)
        {
            int value;
            cin >> value;
            k.push_back(value);
        }

        for (int i = 0; i <= n; i++)
            status.push_back(0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i - k[j] >= 0 && status[i - k[j]] == 0) // 使Ollie輸
                    status[i] = 1;
            }
        }
        if (status[n])
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }

    return 0;
}