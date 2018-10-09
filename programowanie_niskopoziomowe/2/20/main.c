#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int matrix_size;
    int i, j, k;
    int max = 10;
    int suma=0;

    printf("Podaj rozmiar macierzy: ");
    scanf("%d", &matrix_size);

    int matrix1[matrix_size][matrix_size];
    int matrix2[matrix_size][matrix_size];
    int multiplied_matrix[matrix_size][matrix_size];

    for(i = 0; i < matrix_size; i++)
        for(j = 0; j < matrix_size; j++)
        {
            matrix1[i][j] = rand() % (max+1);
            matrix2[i][j] = rand() % (max+1);
        }

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            for(k = 0; k < matrix_size; k++)
                suma += matrix1[i][k] * matrix2[k][j];

            multiplied_matrix[i][j] = suma;
            suma = 0;
        }
    }

    printf("\n");

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<matrix_size/2;i++)
        printf("\t");
    printf("*\n\n");

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<matrix_size/2;i++)
        printf("\t");
    printf("=\n\n");

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            printf("%d\t", multiplied_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
