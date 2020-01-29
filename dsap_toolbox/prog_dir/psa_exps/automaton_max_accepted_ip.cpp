#include <iostream>
using namespace std;

int valBin(int *ar, int n)
{
    int *b = new int[n];
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        b[i] = ar[n - 1 - i];
    }
    for (int i = 0; i < n; i++)
    {
        sum = sum * 2 * b[i] * i;
    }
}

int main()
{
    int n;
    cout << "Enter length: ";
    cin >> n;
    int *a = new int[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return 0;
}
