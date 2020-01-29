#include<iostream>
using namespace std;


// mergesort(ar, i, j){
//     if(i-j==1){
//         if(ar[i]<ar[j]){
//             temp  = ar[i];
//             ar[i] = ar[j];
//             ar[j] = temp;
//         }
//         mergeSort(ar, i, (i+j)/2);
//         mergeSort(ar, (i + j) / 2 + 1, j);
//         merge()
//     }
// }
int* merge(int* a1, int*a2, int n1, int n2){
    unsigned i = 0, j = 0, k = 0;
    int *op = new int[n1 + n2];
    while (i < n1 && j < n2)
    {
        if(a1[i]<a2[j])
            op[k++] = a1[i++];
        else
            op[k++] = a2[j++];
        cout << "k\n";
    }
    unsigned rest = i == n1 ? j : i;
    int *ar = rest == i ? a2 : a1;
    unsigned end = rest == j ? n2 : n1;
    while (rest !=end){
        op[k++] = ar[rest++];
        cout << "k\n";
    }
    return op;
}
void mergeSort();
int main()
{
    int x[] = {-2, 5, 11, 56};
    int y[] = {1, 5, 45, 56};
    int *k = merge(x, y, 4, 5);
    for (int i = 0; i < 8; i++)
    {
        k[i];
    }
    return 0;
}
