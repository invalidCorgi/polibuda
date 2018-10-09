#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scalanie(char a[], char b[], char c[])
{
    int p=0;
    int q=0;
    int r=0;

    while ( (p < strlen(a))  && (q < strlen(b)) )   //poki ani lewy ani prawy znacznik nie przekracza swojego zakresu
    {
        if (a[p] < b[q])        //przepisz mniejszy na odpowiednia pozycje
        {
            c[r] = a[p];
            r++;
            p++;
        }
        else
        {
            c[r] = b[q];
            r++;
            q++;
        }
    }
    while (p < strlen(a))
    {
        c[r] = a[p];
        r++;
        p++;
    }
    while (q < strlen(b))
    {
        c[r] = b[q];
        r++;
        q++;
    }
    c[strlen(a)+strlen(b)]='\0';
    printf("%s\n",c);
    system("pause");
}

int main()
{
    char a[100], b[100], c[200];
    gets(a);
    fflush(stdin);
    gets(b);

    scalanie(a,b,c);

    return 0;
}
