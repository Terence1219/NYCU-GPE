#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int instnum;
        cin >> instnum;
        cin.ignore(); // 忽略換行符號
        int x = 0;
        vector<int> move;
        while (instnum)
        {
            string instr;
            getline(cin, instr);
            if (instr[0] == 'L')
            {
                x--;
                move.push_back(-1);
            }

            else if (instr[0] == 'R')
            {
                x++;
                move.push_back(1);
            }
            else
            {
                string stepstr = instr.substr(8, instr.length()); // 拿取指定step
                int step = stepstr[0] - '0';                      // step轉為int
                stepstr.substr(0, stepstr.length() - 1);
                while (stepstr[1])
                {
                    stepstr = stepstr.substr(1, stepstr.length());
                    step = step * 10 + stepstr[0] - '0';
                }
                x += move[step - 1];
                move.push_back(move[step - 1]);
            }
            instnum--;
        }
        cout << x << endl;
        n--;
    }
    return 0;
}