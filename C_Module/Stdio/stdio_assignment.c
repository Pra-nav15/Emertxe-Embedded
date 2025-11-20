#include<stdio.h>
int main()
{
    int ch_count=0,line_count=0,word_count=0;
    char ch;
    int flag=0;
    while((ch = getchar() ) !=EOF)
    {
        ch_count++;
        if(ch=='\n')
          line_count++;
        if(ch==' ' || ch=='\t' || ch=='\n')
          flag=0;
        else if(flag==0)
        {
            flag=1;
            word_count++;
        }
    }
    
    printf("Character Count is %d\n",ch_count);
    printf("Line Count is %d\n",line_count);
    printf("Word Count is %d",word_count);
}