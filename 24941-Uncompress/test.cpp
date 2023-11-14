#include <iostream>
#include <vector>
#include <string>

using namespace std;
string word = "";
int num = 0;
vector<string> strlist;

void printword(string &word)
{
    cout << word;
    // 往後移
    if (strlist.size() > 0)
    {
        strlist.push_back(strlist[strlist.size() - 1]);
        for (int i = strlist.size() - 2; i > 0; i--)
            strlist[i] = strlist[i - 1];
        strlist[0] = word;
    }
    else
        strlist.push_back(word);

    word = "";
};

void printnum(int &num)
{
    cout << strlist[num - 1];
    // 該單字拉到前面
    num = num - 1;
    string temp = strlist[num];
    for (int i = num; i > 0; i--)
        strlist[i] = strlist[i - 1];
    strlist[0] = temp;
    num = 0;
};

int main()
{
    string s;
    while (getline(cin, s) && s != "0")
    {
        s += "\n"; // 使列印正確
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                word += s[i];
            }
            else if (isdigit(s[i]))
            {
                num *= 10;
                num += s[i] - '0';
            }
            else
            {
                if (word != "")
                    printword(word);
                if (num != 0)
                    printnum(num);
                cout << s[i];
            }
        }
    }

    return 0;
}