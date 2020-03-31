#include <iostream>
using namespace std;

void func(int *ar1, int n1, int *ar2, int n2);

int main()
{
    int cases = 0;
    cin >> cases;
    int **ip = new int *[2 * cases];
    int *num_args = new int[2 * cases];
    for (int i = 0; i < cases; i++)
    {
        cin >> num_args[i] >> num_args[i + 1];
        ip[i] = new int[num_args[i]];
        ip[i + 1] = new int[num_args[i + 1]];
        for (int j = 0; j < num_args[i]; j++)
            cin >> ip[i][j];
        for (int j = 0; j < num_args[i + 1]; j++)
            cin >> ip[i + 1][j];
    }
    // io done

    // output
    for (int i = 0; i < 2 * cases; i += 2)
        func(ip[i], num_args[i], ip[i + 1], num_args[i + 1]);
    return 0;
    // int ar1[] = {1, 3, 5, 7};
    // int ar2[] = {0, 2, 6, 8, 9};
    // int n1 = sizeof(ar1) / sizeof(int);
    // int n2 = sizeof(ar2) / sizeof(int);
    // func(ar1, n1, ar2, n2);
}

void func(int *ar1, int n1, int *ar2, int n2)
{
    if (n1 == 0 || n2 == 0) // edge case
        return;

    // order does not matter
    for (int i = 0; i < n1; i++)
    {
        if (ar1[i] > ar2[0])
        {
            int k = ar1[i];
            ar1[i] = ar2[0];
            ar2[0] = k;
        }
    }
    // done, next put ar2[0] at it's appropriate position
    int k = ar2[0];
    int j = 1;

    while (ar2[0] > ar2[j] && j < n2)
        j++;

    // all the elements before this need to be shifted by one place to the left
    int i = 0;
    while (i < j - 1)
        ar2[i] = ar2[i + 1], i++;
    // shifter by 1 to the right
    ar2[j - 1] = k;
    // done it

    // print
    for (int i = 0; i < n1; i++)
        cout << ar1[i] << " ";
    cout << "\n";

    for (int i = 0; i < n2; i++)
        cout << ar2[i] << " ";
    cout << "\n";
}
