#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>

#if 1
int main()
{
    int fd, fd_1;
    fd = open("new.txt", O_RDONLY);
    fd_1 = open("new1.txt", O_CREAT | O_EXCL | O_WRONLY);
    printf("fd : %d\n", fd);
    printf("fd_1 : %d\n", fd_1);
    if (fd == -1)
    {
        perror("ERROR");
        return -1;
    }
    if (fd_1 == -1)
    {
        perror("ERROR");
        return -1;
    }
    char ch[20];
    int count;
    while (count = read(fd, ch, 20))
    {
        write(4, ch, count);
    }
    return 0;
}
#endif