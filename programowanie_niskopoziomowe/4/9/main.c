#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char ln;
    int k=0, l=0;
    file = fopen("file.txt", "r");
    if(file==NULL)
        return -1;
    while(!feof(file))
    {
        ln = fgetc(file);
        if(ln=='\n')
        {
            ln = fgetc(file);
            if(ln==';')
                l=1;
            else
            {
                l=0;
                k++;
            }
        }
        else if(l==0 && (ln==' ' || ln=='\t'))
            k++;
    }
    printf("%d", k+1);
    fclose(file);

    return 0;
}
