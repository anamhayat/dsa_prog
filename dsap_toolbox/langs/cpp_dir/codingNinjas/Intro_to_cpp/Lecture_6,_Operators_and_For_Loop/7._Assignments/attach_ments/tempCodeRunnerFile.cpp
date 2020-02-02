#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    //plan: Map the term at each iteration as a part of the update criteria
    int x = 1;    // x is the number of terms to be printed
    cin >> x;
    int term = 5; // 3(1)+2, all other terms will have an increment of 3
    for (int i = 1; i <= x;term += 3)
    {
        if(term%4==0)
            continue;
        cout << term << " ";
        i++;
    }
    cout << "\b";
}