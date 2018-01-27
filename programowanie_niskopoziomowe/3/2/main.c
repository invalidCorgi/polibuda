#include <stdio.h>
#include <stdlib.h>

union Bag
{
    int i;
    char c;
    float f;
};

void wypisz(int n, union Bag bags[])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Bag nr: %d\n",i+1);
        printf("Warianty wartosci w srodku\nliczba calkowita: %d\nznak: %c\nliczba zmiennoprzecinkowa: %f\n\n",bags[i].i,bags[i].c,bags[i].f);
    }
    system("pause");
}

int main()
{
    srand(time(NULL));

    int n,i;
    printf("Ile losowac? ");
    scanf("%d",&n);
    union Bag bags[n];

    for(i=0;i<n;i++)
    {
        int wybor = rand()%3;
        switch(wybor)
        {
        case 0:
            {
                printf("Typ w Bag nr %d: liczba calkowita\n",i+1);
                bags[i].i = rand()%100;
                break;
            }
        case 1:
            {
                printf("Typ w Bag nr %d: znak\n",i+1);
                bags[i].c = 65+rand()%26;
                break;
            }
        case 2:
            {
                printf("Typ w Bag nr %d: liczba zmiennoprzecinkowa\n",i+1);
                bags[i].f = (rand()%10000)/100;
                break;
            }
        }
    }

    printf("\n");
    wypisz(n,bags);

    return 0;
}
