#include<stdio.h>
#include<math.h>

int main()
{
    //Zadanie 8

    FILE *file;
    char line, c [10];
    int pl[100][2];
    int n=0,i,j;
    file = fopen("file.txt", "r");
    if(file==NULL)
        return -1;

    while(!feof(file))
    {
        int k = 0;
        line = fgetc(file);
        for(i=0;line!='\n' && !feof(file); i++)
        {
            while(line!='\n' && line!=' ' && !feof(file))
            {
                c[k] = line;
                k++;
                line = fgetc(file);
            }
            for(j=0;j<k;j++)
                pl[i][0]+=((c[j]-48)*pow(10,k-j-1));
            k=0;
            pl[i][1]++;
            if(line==32)
                line = fgetc(file);
        }
    }
    printf("Suma: ");
    for(i=0;i<n;i++)
        printf("%d ", pl[i][0]);
    printf("\nSrednia: ");
    for(i=0;i<n;i++)
        printf("%lf ", (pl[i][0]*1.0)/(pl[i][1]*1.0));
    fclose(file);
    return 0;
}
