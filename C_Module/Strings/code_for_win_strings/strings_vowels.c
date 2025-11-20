#include<stdio.h>
int vowel_consonant_check(char str[],int* vowels,int* consonants);
int main()
{
    char str[100];
    int vowels=0,consonants=0;
    scanf("%[^\n]",str);
    vowel_consonant_check(str,&vowels,&consonants);
    printf("No: of Vowels in given String is %d\nNo: of Consonants in given String is %d\n",vowels,consonants);
}
int vowel_consonant_check(char str[],int* vowels,int* consonants)
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]>='a'  && str[i]<='z') || (str[i]>='A'  && str[i]<='Z'))
        {
            switch(str[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                {
                    (*vowels)++;
                    break;
                }
                default:
                {
                    (*consonants)++;
                }
            }
        }
        i++;
    }
    return *vowels,*consonants;
}