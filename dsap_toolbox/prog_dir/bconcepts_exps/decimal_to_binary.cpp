// T.C o(log(n)), S.C o(1),
// Uses only int, long used only if i/p > log(INT32_MAX).
// Insights gained, stick to basics, simplicity is the key, build on that
#include <iostream>
using namespace std;
int main()
{
    cout << "Enter number: ";
    int n;
    cin >> n;
    long b = 1; // ads a 1 to the MSB, not '0' because n%2 cases also need to be stored
    while (n > 0)
    {
        b = b * 10 + (n % 2);
        n = n / 2; //ceil
        // base *= 10;
    }
    // now reverse the number
    long b1 = 0;
    while (b > 0)
    {
        b1 = b1 * 10 + b % 10;
        b /= 10;
    }
    cout << "Binary : " << b1 / 10 << "\n"; // the MSB which was 1 for storing is now the LSB
    return 0;
}
