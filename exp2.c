#include <stdio.h>

int main()
{
    int m[7], k[7], c[7];
    int i;

    // Input polynomial m(x)
    printf("Enter coefficients of m(x):\n");

    for (i = 0; i <= 6; i++)
    {
        do
        {
            printf("Coefficient of x^%d: ", i);
            scanf("%d", &m[i]);

            if (m[i] < 0 || m[i] > 2)
                printf("Invalid! Enter only 0, 1 or 2.\n");

        } while (m[i] < 0 || m[i] > 2);
    }

    // Input polynomial k(x)
    printf("\nEnter coefficients of k(x):\n");

    for (i = 0; i <= 6; i++)
    {
        do
        {
            printf("Coefficient of x^%d: ", i);
            scanf("%d", &k[i]);

            if (k[i] < 0 || k[i] > 2)
                printf("Invalid! Enter only 0, 1 or 2.\n");

        } while (k[i] < 0 || k[i] > 2);
    }

    // Add the polynomials modulo 3
    for (i = 0; i <= 6; i++)
    {
        c[i] = (m[i] + k[i]) % 3;
    }

    // Display result
    printf("\nc(x) = ");

    int first = 1;

    for (i = 6; i >= 0; i--)
    {
        if (c[i] != 0)
        {
            if (!first)
                printf(" + ");

            if (i == 0)
                printf("%d", c[i]);
            else if (i == 1)
            {
                if (c[i] == 1)
                    printf("x");
                else
                    printf("%dx", c[i]);
            }
            else
            {
                if (c[i] == 1)
                    printf("x^%d", i);
                else
                    printf("%dx^%d", c[i], i);
            }

            first = 0;
        }
    }

    if (first)
        printf("0");
    printf("\n");
    return 0;
}
