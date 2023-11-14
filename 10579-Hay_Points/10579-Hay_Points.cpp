#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, int> dict;
    while (n)
    {
        string word;
        int value;
        cin >> word >> value;
        dict[word] = value;
        n--;
    }
    while (m)
    {
        string input;
        int sum = 0;
        while (cin >> input && input != ".")
        {
            sum += dict[input];
        }
        m--;
        cout << sum << endl;
    }
    return 0;
}