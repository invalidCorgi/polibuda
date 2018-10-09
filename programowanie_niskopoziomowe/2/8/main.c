//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int l_pierwsza(int n)
{
    int i;
    for(i=2; i<=n/2; i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int zakres=1000, i, j, k, done=0;

    for(i=2; i<=zakres; i+=2)
    {
        for(k=1; k<i; k++)
            if(done == 0)
            {
                for(j=k+1; j<i; j++)
                {
                    if( l_pierwsza(k) && l_pierwsza(j) && k+j==i )
                    {
                        printf("Liczba: %d = %d + %d (prawda)\n",i, k, j);
                        done=1;
                    }
                }
            }
        done=0;
    }

    return 0;
}
