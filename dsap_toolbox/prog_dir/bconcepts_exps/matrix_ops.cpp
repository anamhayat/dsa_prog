#include <iostream>
#include <cstdlib>
using namespace std;

class matrix_c
{
    int *mx;
    int odr; // order
    int trace;

public:
    matrix_c(int *t = 0, int x = 0)
    {
        odr = x;
        if (!t)
        {

            cout << "Enter order of the matrix: ";
            cin >> odr;
            cout << "Enter Elements row-wise...\n";
            mx = new int[odr * odr];
            for (int i = 0; i < odr; i++)
            {
                cout << "Row " << i + 1 << ": ";
                for (int j = 0; j < odr; j++)
                {
                    cin >> mx[i * odr + j]; // row major representation
                }
            }
        }
        else
        {
            mx = new int[odr * odr];
            for (int i = 0; i < odr * odr; i++)
                mx[i] = t[i];
        }
        cout << "Matrix accepted successfully";
    }
    ~matrix_c()
    {
        // delete mx;
    }

    void disp()
    {
        cout << "\nMatrix\n";
        for (int i = 0; i < odr; i++)
        {
            for (int j = 0; j < odr; j++)
            {
                cout << mx[i * odr + j] << " ";
            }
            cout << "\n";
        }
    }

    int *ret_mx()
    {
        return mx;
    }
    int ret_odr()
    {
        return odr;
    }
};

int *mx_add(matrix_c x, matrix_c y)
{
    int odr = x.ret_odr() == y.ret_odr() ? x.ret_odr() : 0;
    if (!odr)
    {
        cout << "Addition is not possible";
        return nullptr;
    }
    //risky behavior
    int *m1 = x.ret_mx();
    int *m2 = y.ret_mx();

    int *p = new int[odr * odr];

    for (int i = 0; i < odr * odr; i++)
    {
        p[i] = m1[i] + m2[i];
    }

    return p;
}
int main()
{
    int x1[] = {1, 1, 1, 1};
    matrix_c x, y;
    matrix_c z;
    z.disp();
    return 0;
}
