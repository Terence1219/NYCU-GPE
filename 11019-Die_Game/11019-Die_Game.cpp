#include <iostream>
#include <string>
using namespace std;

void n(int &top, int &bottom, int &north, int &south, int &east, int &west)
{
    int temp = top;
    top = south;
    south = bottom;
    bottom = north;
    north = temp;
};

void s(int &top, int &bottom, int &north, int &south, int &east, int &west)
{
    int temp = top;
    top = north;
    north = bottom;
    bottom = south;
    south = temp;
};

void e(int &top, int &bottom, int &north, int &south, int &east, int &west)
{
    int temp = top;
    top = west;
    west = bottom;
    bottom = east;
    east = temp;
};

void w(int &top, int &bottom, int &north, int &south, int &east, int &west)
{
    int temp = top;
    top = east;
    east = bottom;
    bottom = west;
    west = temp;
};

int main()
{
    int i;
    while (cin >> i && i != 0)
    {
        int top = 1, north = 2, west = 3;
        int bottom = 7 - top, south = 7 - north, east = 7 - west;
        while (i)
        {
            string cmd;
            cin >> cmd;
            if (cmd == "north")
                n(top, bottom, north, south, east, west);
            else if (cmd == "south")
                s(top, bottom, north, south, east, west);
            else if (cmd == "east")
                e(top, bottom, north, south, east, west);
            else if (cmd == "west")
                w(top, bottom, north, south, east, west);
            i--;
        }
        cout << top << endl;
    }

    return 0;
}