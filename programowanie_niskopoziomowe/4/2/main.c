#include <stdio.h>
#include <stdlib.h>

long hexaToDecimal(char hexadecimal[])
{
    long decimalNumber=0;
    char hexDigits[] = "0123456789ABCDEF";
    int i, j, power=0, digit;
    for(i=strlen(hexadecimal)-1; i >= 0; i--)
    {
        for(j=0; j<16; j++)
        {
            if(hexadecimal[i] == hexDigits[j])
            {
                decimalNumber += j*pow(16, power);
            }
        }
        power++;
    }
    return decimalNumber;
}

void decimalToHexa(long n)
{
    char hexDigits[] = "0123456789ABCDEF";
    char hexadecimalNumber[40];
    int index=0, remaindar;
    while(n != 0)
    {
        remaindar = n % 16;
        hexadecimalNumber[index] = hexDigits[remaindar];
        n /= 16;
        index++;
    }
    hexadecimalNumber[index] = '\0';

    strrev(hexadecimalNumber);
    printf("%s\n",hexadecimalNumber);
}

int main()
{
    printf("Prosze uzywac wielkich liter\n");
    char a[20];
    printf("a(hexadecimal)= ");
    fflush(stdin);
    gets(a);
    char b[20];
    printf("b(hexadecimal)= ");
    fflush(stdin);
    gets(b);
    long la=hexaToDecimal(a);
    long lb=hexaToDecimal(b);

    long wynik = la+lb;
    printf("a+b= ");
    decimalToHexa(wynik);
    wynik = la-lb;
    printf("a-b= ");
    decimalToHexa(wynik);
    wynik = la*lb;
    printf("a*b= ");
    decimalToHexa(wynik);
    return 0;
}
