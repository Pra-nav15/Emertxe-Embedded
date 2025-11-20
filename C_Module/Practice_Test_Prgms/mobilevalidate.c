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
int mobile_validate(AddressBook*, char*);
int main()
{
    AddressBook addressbook = { 0 };
    addressbook.contact_count = 1;
    Contacts* create = &addressbook.contact_details[addressbook.contact_count];
retry:
    printf("Enter the Mobile Number : ");
    scanf("%s", create->mobile);
    int ret = mobile_validate(&addressbook, create->mobile);
    if (ret == 0) {
        printf("Try Again\n");
        goto retry;
    }
    printf("Mobile Number Added");
    return 0;
}
int mobile_validate(AddressBook* addressbook, char* mobilenum)
{
    Contacts* c = &addressbook->contact_details[addressbook->contact_count];
    int len = strlen(mobilenum);
    if (len != 10)
    {
        printf("Length should be 10\n");
        return 0;
    }
    if (mobilenum[0]!= '6' && mobilenum[0]!= '7' && mobilenum[0]!= '8' && mobilenum[0]!= '9')
    {
        printf("Mobile Should start with 6 7 8 9 only\n");
        return 0;
    }
    for (int i = 0;i < len;i++)
    {
        if (!isdigit(mobilenum[i]))
        {
            printf("Mobile number should be only digits\n");
            return 0;
        }
    }
}
