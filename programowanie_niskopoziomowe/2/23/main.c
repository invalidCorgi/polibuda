#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int matrix_size, i, j;
    int max = 10;
    double proportion;
    char row_or_col;
    int sel1, sel2, sum1=0, sum2=0;

    printf("Podaj rozmiar macierzy: ");
    scanf("%d", &matrix_size);
    int matrix[matrix_size][matrix_size];

    for(i = 0; i < matrix_size; i++)
        for(j = 0; j < matrix_size; j++)
            matrix[i][j] = rand() % (max+1);

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }



    printf("Wpisz w jesli chcesz obliczac wiersze a k jesli kolumny, oraz ich numery.\n");
    scanf(" %c", &row_or_col);
    scanf("%d", &sel1);
    scanf("%d", &sel2);

    printf("\n");

    sum1 = sum2 = 0;

    if(row_or_col == 'w')
    {
        for(i = 0; i < matrix_size; i++)
            sum1 += matrix[sel1][i];
        for(i = 0; i < matrix_size; i++)
            sum2 += matrix[sel2][i];
    }
    if(row_or_col == 'k')
    {
        for(i = 0; i < matrix_size; i++)
            sum1 += matrix[i][sel1];
        for(i = 0; i < matrix_size; i++)
            sum2 += matrix[i][sel2];
    }
    proportion = (double) sum1 / sum2;
    printf("sum1: %d, sum2: %d, prop: %lf\n", sum1, sum2, proportion);
    return 0;
}
