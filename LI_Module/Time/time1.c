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
    struct timeval tv;
    int status;
    status = gettimeofday(&tv, NULL);
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
#if 1
int main()
{
    time_t sec;
    sec = time(NULL);
    char* str;
    str = ctime(&sec);
    printf("%s\n", str);
    struct tm* tm;
    tm = localtime(&sec);
    char* s;
    s = asctime(tm);
    printf("%s\n", str);
    printf("sec :%d\n", tm->tm_sec);
    printf("min :%d\n", tm->tm_min);
    printf("hour :%d\n", tm->tm_hour);
    printf("md :%d\n", tm->tm_mday);
    printf("mon :%d\n", tm->tm_mon);
    printf("yr :%d\n", tm->tm_year);
    printf("yrd :%d\n", tm->tm_yday);
    return 0;
}
#endif