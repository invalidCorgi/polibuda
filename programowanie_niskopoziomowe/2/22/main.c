#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int matrix_size, i, j;
    int max = 1;

    printf("Podaj rozmiar macierzy: ");
    scanf("%d", &matrix_size);

    int matrix[matrix_size][matrix_size];
    for(i = 0; i < matrix_size; i++)
        for(j = 0; j < matrix_size; j++)
            matrix[i][j] = rand() % (max+1);

    int is_symmetric = 1;
    for(i = 0; i < matrix_size; i++)
        for(j = 0; j < matrix_size; j++)
            if(matrix[i][j] != matrix[j][i])
            {
                is_symmetric = 0;
                break;
            }

    if(is_symmetric == 0)
        printf("Macierz nie jest symetryczna.\n");
    else
        printf("Macierz jest symetrycna.\n");

    int contains_empty_columns;
    for(j = 0; j < matrix_size; j++)
    {
        contains_empty_columns = 1;
        for(i = 0; i < matrix_size; i++)
        {
            if(matrix[i][j] != 0)
            {
                contains_empty_columns = 0;
                break;
            }
        }
        if(contains_empty_columns == 1)
            break;
    }

    if(contains_empty_columns == 0)
        printf("Nie zawiera pustych kolumn.\n");
    else
        printf("Zawiera puste kolumny.\n");

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
