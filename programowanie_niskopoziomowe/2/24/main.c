#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* baza = "alabbfdcalaigigiala";
    char* wzorzec = "ala";
    int i, j, wystapienia=0;
    char pierwszy_znak = wzorzec[0];

    for(i = 0; i < strlen(baza); i++)
    {
        if(baza[i] == pierwszy_znak)
        {
            if( (i+strlen(wzorzec)) <= strlen(baza) )
                for(j = 0; j < strlen(wzorzec); j++)
                {
                    if(baza[i+j] != wzorzec[j])
                        break;
                    if(wzorzec[j+1] == '\0')
                        wystapienia++;
                }
        }
    }

    printf("Wystapienia wzorca: %d\n", wystapienia);
    return 0;
}
