#include<stdio.h>
#include<string.h>
#include<ctype.h>
int validate_mobile(char* mobile);
int main()
{
    char mobile[11];
    scanf("%[^\n]", mail);
    int ret = validate_mobile(mobile);
    if (ret == 0)
    {
        printf("Try Again");
        return 0;
    }
    printf("Mobile number is validated ok");
}
int validate_mobile(char* mobile)
{
    int len = strlen(mobile);
    if (len != 10)
    {
        printf("Length should be 10 ");
        return 0;
    }
    if (mobile[0] != '6' && mobile[0] != '7' && mobile[0] != '8' && mobile[0] != '9')
    {
        printf("Starting should be 6 7 8 9 ");
        return 0;
    }
    for (int i = 0;i < len;i++)
    {
        if (!isdigit(mobile[i]))
        {
            printf("Should be only digits ");
            return 0;
        }
    }
    return 1;
}