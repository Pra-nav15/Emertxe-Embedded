/* #include<stdio.h>
#include<unistd.h>//library for sleep
int main()
{
    while(1)
    {
        printf("Hello");//print only after buffer is full 
        //printf("\n");//We can use a new line to print to stdion without checking for buffer is full
        //fflush(stdout)://Or we can flush out the buffer and give output to stdio
        sleep(1);//delay of 1 sec
    }
    return 0;
} */
/* #include<stdio.h>
#include<unistd.h>//library for sleep
int main()
{
    int num;
    while(1)
    {
        printf("Enter a number: \n");
        scanf("%d",&num); // stores to memory while reading 
        printf("Read value %d\n",num); // display to stdout because scanf flushes buffer without waiting for i/p buffer full
    }
    return 0;
} */
#include<stdio.h>
#include<unistd.h>//library for sleep
int main()
{
    char str[BUFSIZ]="abc";
    setbuf(stdout,NULL); // disable the output buffer
    while(1)
    {
        printf("%s",str);
        sleep(1);
    }
    return 0;
}