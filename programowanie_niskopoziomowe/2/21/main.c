#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int matrix_size;
    int i, j;

    printf("Podaj rozmiar macierzy: ");
    scanf("%d", &matrix_size);

    printf("\n");

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            if(j <= i)
                printf("x");
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            if(j >= i)
                printf("x");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
