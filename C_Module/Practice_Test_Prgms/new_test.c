/* #include<stdio.h>
#include<string.h>
int mobile_validate(char* ognumber, char* number);
int main()
{
    char number[11];
    char ognumber[11] = "7994858713";
    scanf("%[^\n]", number);
    int ret = mobile_validate(ognumber, number);
    if (ret == 0)
    {
        printf("Mobile Number exists");
        return 0;
    }
    else
    {
        printf("New mobile number");
    }
}
int mobile_validate(char* ognumber, char* number)
{
    if (strcmp(ognumber, number) == 0)
    {
        return 0;
    }
    return 1;
} */
#include<stdio.h>
#include<string.h>
int mail_validate(char* ognumber, char* number);
int main()
{
    char mail[25];
    char ogmail[25] = "pranav123@gmail.com";
    scanf("%[^\n]", mail);
    int ret = mail_validate(ogmail, mail);
    if (ret == 0)
    {
        printf("Mail id exists");
        return 0;
    }
    else
    {
        printf("New mail id");
    }
}
int mail_validate(char* ogmail, char* mail)
{
    if (strcmp(ogmail, mail) == 0)
    {
        return 0;
    }
    return 1;
}