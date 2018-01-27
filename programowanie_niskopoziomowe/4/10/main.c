#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char zn[10];
    char ln;
    int k=0, l=0;
    int i=0,  x=0,j,n=0;
    file = fopen("file.txt", "r");
    if(file!=NULL)
    {
        while(!feof(file))
        {
            ln = fgetc(file);
            while(ln!='\n' && !feof(file))
            {
                if(ln=='-')
                {
                    x=1;
                    ln = fgetc(file);
                }
                while(ln!='\n' && ln!=' ' && !feof(file))
                {
                    zn[k] = ln;
                    k++;
                    ln = fgetc(file);
                }
                for(j=0;j<k;j++)
                {
                    if(x)
                        i-=((zn[j]-48)*pow(10,k-j-1));
                    else
                        i+=((zn[j]-48)*pow(10,k-j-1));
                }
                printf("|%d", i);
                n+=i;
                i=k=0;
                if(ln==' ') ln = fgetc(file);
            }
            printf("|%d\n", n);
            n=0;
        }
    }

    return 0;
}
