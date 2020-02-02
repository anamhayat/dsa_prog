#include <stdio.h>

int main()
{

    // long double v = 12.2l;
    int val = 0; // value to be printed
    int n = 0;
    scanf("%i", &n);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            // upper part of the matrix
            if (i < j)
            {
                if (i + j <= 2 * n)
                    val = n - i + 1;
                else
                    val++;
            }
            // diagonal
            else if (i == j)
            {
                if (i <= n)
                    val = n - i + 1;
                else
                    val = i - n + 1;
            }
            // lower part of the matrix
            else if (i > j)
            {
                if (i + j <= 2 * n)
                    val = n - j + 1;
                // carry on with the value till diagonal where i+j == 14
                // val remains same, which should be saved
            }
            printf("%i ", val);
        }
        printf("\n");
    }
}

/*
for n = 5
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
9 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 9
9 8 7 7 7 7 7 7 7 7 7 7 7 7 7 8 9
9 8 7 6 6 6 6 6 6 6 6 6 6 6 7 8 9
9 8 7 6 5 5 5 5 5 5 5 5 5 6 7 8 9
9 8 7 6 5 4 4 4 4 4 4 4 5 6 7 8 9
9 8 7 6 5 4 3 3 3 3 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 2 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 2 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 3 3 3 3 4 5 6 7 8 9
9 8 7 6 5 4 4 4 4 4 4 4 5 6 7 8 9
9 8 7 6 5 5 5 5 5 5 5 5 5 6 7 8 9
9 8 7 6 6 6 6 6 6 6 6 6 6 6 7 8 9
9 8 7 7 7 7 7 7 7 7 7 7 7 7 7 8 9
9 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 9
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
*/
