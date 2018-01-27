#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct stat stats;
    struct passwd* passwds;
    struct group* groups;
    struct tm* tms;
    int fd;
    
    fd = open(argv[1],O_RDONLY);
    
    fstat(fd,&stats);
    
    if(stats.st_mode & 0100000) //0 na poczatku to kod oktalny
        printf("-");
    else printf("!"); //nie ogarniam kodow typow plikow w tablicy bitow, wiec jak nie jest plikiem zwyklym to niech bedzie po prostu wykrzyknik [*]
    
    //uzytkownik
    if(stats.st_mode & 0000400)
        printf("r");
    else printf("-");
    if(stats.st_mode & 0000200)
        printf("w");
    else printf("-");
    if(stats.st_mode & 0000100)
        printf("x");
    else printf("-");
    
    //grupa
    if(stats.st_mode & 0000040)
        printf("r");
    else printf("-");
    if(stats.st_mode & 0000020)
        printf("w");
    else printf("-");
    if(stats.st_mode & 0000010)
        printf("x");
    else printf("-");
    
    //inni
    if(stats.st_mode & 0000004)
        printf("r");
    else printf("-");
    if(stats.st_mode & 0000002)
        printf("w");
    else printf("-");
    if(stats.st_mode & 0000001)
        printf("x");
    else printf("-");
    
    //ilosc dowiazan do pliku
    printf(" %ld",stats.st_nlink);
    
    //nazwa wlasciciela
    passwds = getpwuid(stats.st_uid);
    printf(" %s",passwds->pw_name);
    
    //i jego grupy?
    groups = getgrgid(stats.st_gid);
    printf(" %s",groups->gr_name);
    
    //rozmiar pliku w bajtach
    printf(" %ld",stats.st_size);
    
    //czas ostatniej modyfikacji
    tms = localtime(&stats.st_mtime);
    printf(" %d-%d %d:%d",tms->tm_mon+1,tms->tm_mday,tms->tm_hour,tms->tm_min);
    
    printf(" %s",argv[1]);
    
    close(fd);
    printf("\n");
    
    return 0;
}
