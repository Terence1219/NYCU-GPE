#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double pi = acos(-1.0);

// a*a - (a*a*pi/4.0) = y + 2*z
// ((a*a*pi/6.0) - (sqrt(3)*a*a/4.0)) = w
// ((a*a*pi/4.0) - (a*a*pi/6.0)) = w + y + z

double Z(double a)
{
    return a * a - (a * a * pi / 4.0) + ((a * a * pi / 6.0) - (sqrt(3) * a * a / 4.0)) - ((a * a * pi / 4.0) - (a * a * pi / 6.0));
};

double Y(double a, double z)
{
    return a * a - (a * a * pi / 4.0) - 2 * z;
};

double X(double a, double z, double y)
{
    return a * a - 4 * y - 4 * z;
};

int main()
{
    double a;
    while (cin >> a && a != EOF)
    {
        double z = Z(a);
        double y = Y(a, z);
        double x = X(a, z, y);

        cout << fixed << setprecision(3) << x << " " << 4 * y << " " << 4 * z;
    }
    return 0;
}