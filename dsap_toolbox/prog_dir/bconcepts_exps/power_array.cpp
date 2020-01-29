#include <iostream>
#include <cstdlib>
using namespace std;

// template <class T>
class parray
{
    int *head;
    int size;
    int cap;

public:
    parray()
    {
        head = nullptr;
        size = 1;
        cap = 0;
    }

    parray(int n)
    {
        if (n < 0)
            return;
        size = 1;
        while (n > size)
            size *= 2;
        cap = 0;
    }

    parray(parray &x)
    {
        head = new int[x.cap];
        cap = x.cap;
        size = x.size;
        for (int i = 0; i < size; i++)
            head[i] = x.head[i];
    }

    void append(parray t)
    {
        if (t.cap + cap < size)
        {
            while (t.cap + cap < size)    // size - cap = empty space
                size *= 2;                // we have a sufficient size value, but this->size is unchanged
            int *temp = head;             // just saved this->array
            head = new int[size];         // set head to a new location wuth size new_size
            for (int i = 0; i < cap; i++) // copying old head first to new location
                head[i] = temp[i];
            delete[] temp;
        }
        for (int i = cap; i < t.cap + cap; i++)
            head[i] = t.head[i - cap]; // all copied
        cap += t.cap;
    }
    void load_from_array(int *k, int n)
    {
        parray x(n);
        x.cap = n;
        this->append(x);
    }
    void primary_ip()
    {
        cout << "How many elements: ";
        int x = 0;
        cin >> x;
        cap = x;

        while (x > size)
            size *= 2;
        head = new int[size];
        cout << "Enter the elements: ";
        for (int i = 0; i < cap; i++)
            cin >> head[i];
        cout << "Elements entered successfully\n";
    }
    // void ip()
    // {
    //     cout << "Enter the elements";
    // }
    void disp_info()
    {
        cout << "Head: " << head;
        cout << "\nSize: " << size;
        cout << "\nCapacity: " << cap << "\n";
    }
    void disp()
    {
        cout << "P_Array: ";
        for (int i = 0; i < cap; i++)
            cout << head[i] << " ";
        cout << "END\n";
    }
    ~parray()
    {
        delete[] head;
    }
};

int main()
{
    parray a1, a2;
    a1.primary_ip();
    int x[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    a1.load_from_array(x, sizeof(x) / sizeof(x[0]));
    // a2.primary_ip();
    // a1.append(a2);
    // a1.disp();
    // a1.disp_info();
    // a2.disp_info();
    // a2.disp();
    return 0;
}
