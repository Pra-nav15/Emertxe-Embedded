#include <stdio.h>
#include <time.h>

#if 0
int main()
{
    time_t sec;
    sec = time(NULL);
    printf("Sec : %ld\n", sec);
    return 0;
}
#endif

#if 0
int main()
{
    time_t sec, sec1;
    sec1 = time(&sec);
    printf("Sec : %ld\n", sec);
    printf("Sec1 : %ld\n", sec1);
    return 0;
}
#endif

#if 1
int main()
{
    struct timeval tv;
    int status;
    status = gettimeofday + (&tv, NULL);
    if (status == -1)
    {
        perror("");
        return -1;
    }
    printf("Sec : %ld\n", tv.tv_sec);
    printf("Micro Sec : %ld\n", tv.tv_usec);
    return 0;
}
#endif