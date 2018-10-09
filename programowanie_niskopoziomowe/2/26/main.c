#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* input_string = "ddffffffcccc";
    char l_char, c_char;
    int l_ilosc, c_ilosc, i, j;

    l_char = '\0';
    l_ilosc = 0;

    for(i = 0; i < strlen(input_string); i++)
    {
        c_char = input_string[i];
        c_ilosc = 1;

        while(c_char == input_string[i+1])
        {
            c_ilosc += 1;
            i++;
            if(i == '\0')
                break;
        }

        if(c_ilosc > l_ilosc)
        {
            l_char = c_char;
            l_ilosc = c_ilosc;
        }
    }

    printf("najdluzszy podciag jednego znaku sklada sie z '%c' i ma dlugosc: %d\n", l_char, l_ilosc);
    return 0;
}
