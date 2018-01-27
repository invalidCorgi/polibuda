#include <stdio.h>
#include <stdlib.h>

int main()
{
    int liczba_znakow = 26;
    char alfabet[liczba_znakow];
    int min=97, max=122;    //ascii 97-a 122-z
    char *input_string = "co tam panie w polityce?";
    int input_strlen = strlen(input_string);
    int i;

    for(i = 0; i < liczba_znakow; i++)
    {
        alfabet[i] = 0;
    }

    for(i = 0; i < input_strlen; i++)
    {
        char c = input_string[i];
        if(c>=min && c<=max)
            alfabet[(int)(c - min)] += 1;
    }

    for(i = 0; i < liczba_znakow; i++)
        printf("%c pojawia sie: %d razy\n", 'a' + i, alfabet[i]);
    return 0;
}
