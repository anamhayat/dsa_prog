#include <iostream>
using namespace std;

int main()
{
    cout << "\n-------------------------------------------------------------\n";
    string x = "";
    cout << "Enter integer: ";
    int n;
    cin >> n;
    int n1 = n;
    int l = 0;

    while (n > 0)
    {
        l++;
        n /= 10;
    } // calculated length, o(n)

    cout << "l:" << l << "\n";
    char *ar = new char[l + 1];

    for (int i = l - 1; i >= 0; i--)
    {
        ar[i] = (n1 % 10) + '0';
        n1 /= 10;
    }

    for (int i = 0; i < l; i++)
        cout << ar[i];
    cout << "\n-------------------------------------------------------------\n";

    return 0;
}
