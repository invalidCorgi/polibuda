#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int matrix_size;
    int i, j;
    int max = 10;
    int suma_nad=0, suma_pod=0;;

    printf("Podaj rozmiar macierzy: ");
    scanf("%d", &matrix_size);

    int matrix[matrix_size][matrix_size];
    for(i = 0; i < matrix_size; i++)
        for(j = 0; j < matrix_size; j++)
        {
            matrix[i][j] = rand() % (max+1);
            if(i > j)
                suma_nad += matrix[i][j];
            else if(j > i)
                suma_pod += matrix[i][j];
        }

    printf("Utworzona macierz:\n");
    for(i = 0; i < matrix_size; i++)
    {
        for(j = 0; j < matrix_size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n\n");
    }
    printf("Suma pod przekatna: %d\n", suma_pod);
    printf("Suma nad przekatna: %d\n", suma_nad);
    printf("Stosunek sumy wartosci liczb nad glowna przekatna do sumy wartosci liczb pod glowna przekatna: %f\n", (float)suma_nad/suma_pod);
    return 0;
}
