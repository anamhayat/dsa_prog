/*
Analysis:
Time: o(n)
Space: o(1)
The pow method is costly, uses nearly the same space but as time for each pow is o(n),
therefore the time is o(sigma(n))
*/

#include <iostream>
using namespace std;

int binary_to_decimal(int *ar, int n)
{
    int exp = 1, dec_value = 0; // i.e it is 1 at the start, haha
    for (int i = 0; i < n; i++)
    {
        dec_value = dec_value + exp * ar[i];
        exp = exp * 2;
    }
    return dec_value;
}

int main()
{
    cout << "How many elements: ";
    int n;
    cin >> n;
    int *ar = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    cout << "Binary Value is: " << binary_to_decimal(ar, n) << "\n";
    return 0;
}
