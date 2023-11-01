#include <iostream>

using namespace std;

/*
每關掉一個區域，所有區域的順位就往前m，再關掉第一順位的(index 0)，重複此步驟直到全部被關掉
反過來想，某個區域x要最後關掉的話，需要+m N次後能回到第x順位(index x-1)，代表他是最後被關掉的
實作上index以0為開始，再加上第一個一定是最先關掉的，直接從第二個關的開始找，因此編號13的index應為11(13-1-1)，總共N-1個區域
%i是依照當時的區域數量而有不同
 */
int main()
{
    int N;
    cin >> N;
    for (int m = 1; m < N - 1; m++)
    {
        int curr = 0;
        for (int i = 2; i <= N - 1; i++)
        {
            curr = (curr + m) % i;
        }
        if (curr == 11)
        {
            cout << m;
            break;
        }
    }
    return 0;
}