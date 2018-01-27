void gsub(char *tekst, char *wynik, char *tablica)
{
    char *p = strstr(tablica, tekst);
    do
    {
        if(p)
        {
            char b[1024];
            memset(b,'\0',strlen(b));

            if(tablica == p)
            {
                strcpy(b,wynik);
                strcat(b,p+strlen(tekst));
            }
            else
            {
                strncpy(b,tablica,strlen(tablica) - strlen(p));
                strcat(b,wynik);
                strcat(b,p+strlen(tekst));
            }

            memset(tablica,'\0',strlen(tablica));
            strcpy(tablica,b);
        }

    }while(p && (p = strstr(tablica, tekst)));
}


char *gensub(char *tekst, char *wynik, char *tablica)
{
    char *finalny = malloc(sizeof(char)*1024);
    char *p = strstr(tablica, tekst);
    do
    {
        if(p)
        {
            char b[1024];
            memset(b,'\0',strlen(b));

            if(tablica == p)
            {
                strcpy(b,wynik);
                strcat(b,p+strlen(tekst));
            }
            else
            {
                strncpy(b,tablica,strlen(tablica) - strlen(p));
                strcat(b,wynik);
                strcat(b,p+strlen(tekst));
            }

            memset(tablica,'\0',strlen(tablica));
            strcpy(finalny,b);
        }

    }while(p && (p = strstr(tablica, tekst)));
    return finalny;
}


int index(char *tekst, char *wynik, char *tablica)
{
    char *p = strstr(tablica, tekst);
    int finalny = 0;
    int found = 0;
    do
    {
        if(p)
        {
            char b[1024];
            memset(b,'\0',strlen(b));

            if(tablica == p)
            {
                strcpy(b,wynik);
                strcat(b,p+strlen(tekst));
            }
            else
            {
                strncpy(b,tablica,strlen(tablica) - strlen(p));
                strcat(b,wynik);
                strcat(b,p+strlen(tekst));
            }

            memset(tablica,'\0',strlen(tablica));
            strcpy(tablica,b);
            found = 1;
            return finalny;
        }
        finalny++;

    } while(!found && p && (p = strstr(tablica, tekst)));
}


void sub(char *tekst, char *wynik, char *tablica)
{
    char *p = strstr(tablica, tekst);
    int found = 0;
    do
    {
        if(p)
        {
            char b[1024];
            memset(b,'\0',strlen(b));

            if(tablica == p)
            {
                strcpy(b,wynik);
                strcat(b,p+strlen(tekst));
            }
            else
            {
                strncpy(b,tablica,strlen(tablica) - strlen(p));
                strcat(b,wynik);
                strcat(b,p+strlen(tekst));
            }

            memset(tablica,'\0',strlen(tablica));
            strcpy(tablica,b);
            found = 1;
        }

    } while(!found && p && (p = strstr(tablica, tekst)));
}

int main()
{
    return 0;
}
