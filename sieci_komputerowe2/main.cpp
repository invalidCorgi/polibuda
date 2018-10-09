#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h> 
using namespace std;
int main(int argc, char **argv) {
    char buffer[4096];
    int fd = open("date", O_RDONLY);
    if(fd == -1){
        return 1;
    }
    read(fd, buffer, 4096);
    printf("%s", buffer);
    close(fd);
    return 0;
}
