#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

#if 1
int main()
{
    int fd;
    fd = open("pranav.txt", O_CREAT,O_WRONLY, 0600);
    if (fd == -1)
    {
        perror("ERROR");
        return -1;
    }
    printf("fd : %d\n", fd);
    close(fd);
    return 0;
}
#endif