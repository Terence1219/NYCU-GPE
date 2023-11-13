#include <iostream>
#include <cmath>
using namespace std;

int Digit_Sum(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
};
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int inputnum, curr;
        cin >> inputnum;

        if (inputnum < 4) // 小於4的都是質數。所以從4開始
            inputnum = 4;
        else
            inputnum++;

        while (true)
        {
            curr = inputnum;
            int maxprime = sqrt(curr);
            int factorsum = 0, digitsum = Digit_Sum(inputnum);
            while (curr % 2 == 0) // 質因數2
            {
                curr /= 2;
                factorsum += 2;
            }
            for (int i = 3; i <= maxprime && curr > 1; i = i + 2) // 跳過2的倍數
            {
                while (curr % i == 0)
                {
                    curr /= i;
                    factorsum += Digit_Sum(i); // 算factorsum
                }
            }

            if (curr > 1 && curr != inputnum)
                factorsum += Digit_Sum(curr); // 加入剩下的質因數，若本身為質數則跳過
            if (factorsum == digitsum)
            {
                cout << inputnum << endl;
                break;
            }

            inputnum++;
        }
        n--;
    }
    return 0;
}