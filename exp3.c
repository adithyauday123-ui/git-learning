#include <stdio.h>

#define MAX 100

// Function to input a sparse matrix
void inputSparse(int sparse[MAX][3])
{
    int rows, cols;
    int i, j, value;
    int count = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter the matrix:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &value);

            if (value != 0)
            {
                count++;

                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = value;
            }
        }
    }

    // First row stores rows, columns and number of non-zero elements
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = count;
}

// Function to display triplet matrix
void displaySparse(int sparse[MAX][3])
{
    int i;

    printf("\nRow\tColumn\tValue\n");

    for (i = 0; i <= sparse[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }
}

// Add two sparse matrices
void addSparse(int a[MAX][3], int b[MAX][3], int result[MAX][3])
{
    int i = 1, j = 1, k = 1;

    result[0][0] = a[0][0];
    result[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2])
    {
        // Same row and column
        if (a[i][0] == b[j][0] &&
            a[i][1] == b[j][1])
        {
            int sum = a[i][2] + b[j][2];

            if (sum != 0)
            {
                result[k][0] = a[i][0];
                result[k][1] = a[i][1];
                result[k][2] = sum;
                k++;
            }

            i++;
            j++;
        }

        // Element of A comes first
        else if (a[i][0] < b[j][0] ||
                (a[i][0] == b[j][0] &&
                 a[i][1] < b[j][1]))
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];

            i++;
            k++;
        }

        // Element of B comes first
        else
        {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];

            j++;
            k++;
        }
    }

    // Copy remaining elements of A
    while (i <= a[0][2])
    {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];

        i++;
        k++;
    }

    // Copy remaining elements of B
    while (j <= b[0][2])
    {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];

        j++;
        k++;
    }

    result[0][2] = k - 1;
}

// Transpose sparse matrix
void transpose(int a[MAX][3], int t[MAX][3])
{
    int i, j, k = 1;

    t[0][0] = a[0][1];
    t[0][1] = a[0][0];
    t[0][2] = a[0][2];

    for (j = 0; j < a[0][1]; j++)
    {
        for (i = 1; i <= a[0][2]; i++)
        {
            if (a[i][1] == j)
            {
                t[k][0] = a[i][1];
                t[k][1] = a[i][0];
                t[k][2] = a[i][2];

                k++;
            }
        }
    }
}

int main()
{
    int layer1[MAX][3];
    int layer2[MAX][3];
    int layer3[MAX][3];

    int temp[MAX][3];
    int final[MAX][3];
    int transposed[MAX][3];

    printf("ENTER LAYER 1\n");
    inputSparse(layer1);

    printf("\nENTER LAYER 2\n");
    inputSparse(layer2);

    printf("\nENTER LAYER 3\n");
    inputSparse(layer3);

    // Add Layer 1 and Layer 2
    addSparse(layer1, layer2, temp);

    // Add the result with Layer 3
    addSparse(temp, layer3, final);

    printf("\nFINAL SPARSE MATRIX:\n");
    displaySparse(final);

    // Transpose final matrix
    transpose(final, transposed);

    printf("\nTRANSPOSED MATRIX:\n");
    displaySparse(transposed);

    return 0;
}
