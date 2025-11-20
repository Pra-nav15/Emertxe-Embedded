#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct Contacts_data
{
    char name[20];
    char mobile[11];
    char mail[15];
}Contacts;
typedef struct Address_data
{
    Contacts contact_details[100];
    int contact_count;
}AddressBook;
int mail_validate(AddressBook*, char*);
int main()
{
    AddressBook addressbook = { 0 };
    addressbook.contact_count = 1;
    Contacts* create = &addressbook.contact_details[addressbook.contact_count];
retry:
    printf("Enter the Mail id : ");
    scanf("%s", create->mail);
    int ret = mail_validate(&addressbook, create->mail);
    if (ret == 0) {
        printf("Try Again\n");
        goto retry;
    }
    printf("Mobile Number Added");
    return 0;
}
int mail_validate(AddressBook* addressbook, char* mailid)
{
    Contacts* c = &addressbook->contact_details[addressbook->contact_count];
    int len = strlen(mailid);
    if (len != 10)
    {
        printf("Length should be 10\n");
        return 0;
    }
    if (!(isalnum(mailid) || islower(mailid) || mailid[i]==@ || mailid[i]=='.'))
    {
        printf("It should always be digits and alpha lowercase");
    }
    int atindex, dotindex, count = 0, count1 = 0;
    for (int i = 0;i < len;i++)
    {
        if (mailid[i] == '@')
        {
            atindex = i;
            count++;
        }
    }
    for (int i = 0;i < len;i++)
    {
        if (mailid[i] == '.')
        {
            dotindex = i;
            count1++;
        }
    }
    if (dotindex - atindex <= 1)
    {
        printf("There should be something in between @ and .");
    }
    for (int i = dotindex - 1;i >= atindex;i--)
    {
        if (!isalpha(mailid[i]))
        {
            printf("There should be alphabets in between @ and .");
        }
    }
    if (mail[len - 4] != '.' && mail[len - 3] != 'c' && mail[len - 2] != 'o' && mail[len - 1] != 'm')
    {
        printf(".com should be at last");
    }
}
