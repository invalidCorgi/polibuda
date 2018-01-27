#include <stdio.h>
#include <stdlib.h>

long binaryToDecimal(long n)
{
    int remainder;
    long decimal = 0, i=0;
    while(n != 0)
    {
        remainder = n%10;
        n = n/10;
        decimal = decimal + (remainder*pow(2,i));
        ++i;
    }
    return decimal;
}

long decimalToBinary(long n)
{
    int remainder;
    long binary = 0, i = 1;

    while(n != 0)
    {
        remainder = n%2;
        n = n/2;
        binary= binary + (remainder*i);
        i = i*10;
    }
    return binary;
}

long decimalToOctal(long n)
{
    int remainder;
    long binary = 0, i = 1;

    while(n != 0)
    {
        remainder = n%8;
        n = n/8;
        binary= binary + (remainder*i);
        i = i*10;
    }
    return binary;
}

long octalToDecimal(long n)
{
    int remainder;
    long decimal = 0, i=0;
    while(n != 0)
    {
        remainder = n%10;
        n = n/10;
        decimal = decimal + (remainder*pow(8,i));
        ++i;
    }
    return decimal;
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

long hexaToDecimal(char hexadecimal[])
{
    long decimalNumber=0;
    char hexDigits[] = "0123456789ABCDEF";
    int i, j, power=0, digit;
    for(i=strlen(hexadecimal)-1; i >= 0; i--) {
        for(j=0; j<16; j++){
            if(hexadecimal[i] == hexDigits[j]){
                decimalNumber += j*pow(16, power);
            }
        }
        power++;
    }
    return decimalNumber;
}

int main()
{
    int wybor;
    printf("1-bin to oct\n2-bin to dec\n3-bin to hex\n4-oct to bin\n5-oct to dec\n6-oct do hex\n7-dec to bin\n8-dec to oct\n9-dec to hex\n10-hex to bin\n11-hex to oct\n12-hex to dec\nWybor: ");
    scanf("%d",&wybor);

    switch(wybor)
    {
        case 1:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            printf("%d",decimalToOctal(binaryToDecimal(liczba)));
            break;
        }
        case 2:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            printf("%d",binaryToDecimal(liczba));
            break;
        }
        case 3:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            decimalToHexa(binaryToDecimal(liczba));
            break;
        }
        case 4:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            printf("%d",decimalToBinary(octalToDecimal(liczba)));
            break;
        }
        case 5:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            printf("%d",octalToDecimal(liczba));
            break;
        }
        case 6:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            decimalToHexa(octalToDecimal(liczba));
            break;
        }
        case 7:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            printf("%d",decimalToBinary(liczba));
            break;
        }
        case 8:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            printf("%d",decimalToOctal(liczba));
            break;
        }
        case 9:
        {
            long liczba;
            printf("Podaj liczbe do konwersji: ");
            scanf("%d",&liczba);
            decimalToHexa(liczba);
            break;
        }
        case 10:
        {
            char liczba[20];
            printf("Podaj liczbe do konwersji: ");
            fflush(stdin);
            gets(liczba);
            printf("%d",decimalToBinary(hexaToDecimal(liczba)));
            break;
        }
        case 11:
        {
            char liczba[20];
            printf("Podaj liczbe do konwersji: ");
            fflush(stdin);
            gets(liczba);
            printf("%d",decimalToOctal(hexaToDecimal(liczba)));
            break;
        }
        case 12:
        {
            char liczba[20];
            printf("Podaj liczbe do konwersji: ");
            fflush(stdin);
            gets(liczba);
            printf("%d",hexaToDecimal(liczba));
            break;
        }
    }

    return 0;
}
