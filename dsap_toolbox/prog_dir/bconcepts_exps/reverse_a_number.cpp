// 1:43 AM, August 3, Saturday G2019
//Very very important, usefulness and insights are too necessary to be wasted.
// Learnt from a simple(just skipped) problem from Deep Dive in C++ by Abd ul Bari Sir
// www.udemy.com

// Math, % is used to get the LSB, / by 10 is used to get the MSB.
// So Print LSB until the number becomes 0.
// Applications: Print a number digitwise in reverse, calculate sum of digits
#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Enter number: ";
    cin >> x;
    cout << "After number: ";

    // Apart form printing the reverse let us store the reverse in y.
    // Need a 'single' variable to store result, key point, init value 0
    int y = 0;
    while (x > 0)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }
    int x = INT32_MAX;
    // END of reverse, x value is lost now, y is the reverse.
    cout << y;
    return 0;
    // NOTE about notation, x/=10 means that x = x /10 was being performed and x!=10 was being
    // checked at the same time.
}
