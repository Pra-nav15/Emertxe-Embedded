/* #include<stdio.h>
int main()
{
    char ch;
    printf("Enter a char or string: ");
    while(ch !='n')
    {
        scanf("%c",&ch);
        //(fpurge(stdin) -function is used to flush or clear out the i/p buffer 
        //fpurge(stdin): //solution 1
        while(getchar()!='\n'): //solution 2
           printf("%c",ch);
    }
} */
#include<stdio.h>
#include<unistd.h>
int main()
{
    //setbuf(stdout,NULL); //TO DISABLE BUFFER(To get output HelloWorld)
    while(1)
    {
        fprintf(stdout,"Hello");
        fprintf(stderr,"World");
        sleep(1); // output will be  World because stderr will not wait until buffer is full
    }
}