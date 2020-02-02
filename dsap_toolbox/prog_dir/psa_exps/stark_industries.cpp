#include <iostream>
using namespace std;

long max_fruits(int x, int y, int z)
{
    if (x <= z || y <= z)
        return 0;
    if (y >= x)
        return x - z;
    long r = 0;
    while (x >= y)
    {
        r += y - z;
        x = x - y;
    }
    return r;
}
int main()
{
    long x = 0, y = 0, z = 0;
    cout << "Enter Fruits, Capacity and Distance, respectively: ";
    cin >> x >> y >> z;
    cout << "Maximum fruits that can be tranported are: " << max_fruits(x, y, z) << "\n";
    return 0;
}
