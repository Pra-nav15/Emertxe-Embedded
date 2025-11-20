#include<stdio.h>
#include<string.h>
typedef struct Contacts_data{
    char name[20];
    char mobile[11];
    char mail[15];
}Contacts;
typedef struct Address_data{
    Contacts contact_details[100];
    int contact_count;
}AddressBook;

int checkmail(AddressBook *,char *);
int main()
{
    AddressBook addressbook ={0};
    addressbook.contact_count=1;
    Contacts *create=&addressbook.contact_details[addressbook.contact_count];
    strcpy(addressbook.contact_details[0].mail,"pranav123@gmail.com");
    printf("Enter the mail id");
    scanf("%s",create->mail);
    int ret=checkmail(&addressbook,create->mail);
    if(ret==0)
    {
        printf("Duplicate mail found");
        return 0;
    }
    printf("New Mail");
    return 1;
}
int checkmail(AddressBook *addressbook,char *mailid)
{
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].mail,mailid)==0)
        {
            return 0;
        }
    }
    return 1;
}