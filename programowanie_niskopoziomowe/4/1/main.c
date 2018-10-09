#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strupp(char* beg)
{
    while (*beg = toupper(*beg))beg++;
}

int main()
{
    FILE *f1;
    int l[26],i;
    for(i=0; i<26; i++)
        l[i]=0;

    char temp[100];
    if ((f1=fopen("test.txt", "r"))==NULL)
    {
        printf ("Nie mogê otworzyæ pliku test.txt do odczytu!\n");
        exit(1);
    }

    while ( !feof(f1) )
    {
        fgets(&temp,100,f1);
        strupp(temp);
        for(i=0; i<100; i++)
        {
            if(temp[i]>=65 && temp[i]<=90)
                l[temp[i]-65]++;
        }
        printf("%s",temp);
    }

    printf("\n\n");

    for(i=0;i<26;i++)
    {
        printf("%c wystapilo: %d razy\n",i+65,l[i]);
    }

    return 0;
}
