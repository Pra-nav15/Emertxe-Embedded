#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

/* Function definitions */
// void init_intitalization(AddressBook *addressbook)
// {
// }
int name_validate(AddressBook* addressbook, char* name) // function for name validation
{
    Contacts* create = &addressbook->contact_details[addressbook->contact_count];// Pointer c to a contact structure used to access or modify contact details(same throughout program)
    int len = strlen(name);// find the length of the name and store it to len
    if (len == 0 || len > 30) //check if len is 0 or len is greater than 30 if yes then invalid
    {
        printf("\033[1;31mInvalid Name Try Again! Name should not be so Short or so Long.\033[0m\n");
        return 0;
    }
    if (!isupper(name[0])) //Check if first alphabet in name is Uppercase
    {
        printf("\033[1;31mTry Again! First Alphabet Should be in Upper Case.\033[0m\n");
        return 0;
    }
    for (int i = 0; i < len; i++) //loop until the length of the name
    {
        if (!(isalpha(name[i]) || name[i] == ' '))// check if the name consists of alphabets and single space only
        {
            printf("\033[1;31mInvalid Name Try Again! Only Alphabets and Single Spaces are allowed.\033[0m\n");
            return 0;
        }
        if (name[i] == ' ' && name[i + 1] == ' ')// check if 2 adjacent positions contains space
        {
            printf("\033[1;31mInvalid Name Try Again! Multiple Spaces not allowed.\033[0m\n");
            return 0;
        }
    }
    return 1; // return to create contacts function
}
int mobilenumber_validate(AddressBook* addressbook, char* mobile) //function of mobile number validation
{
    Contacts* create = &addressbook->contact_details[addressbook->contact_count];
    int len = strlen(mobile);// find the length of the mobile number and store it to len
    if (len != 10) // check if length of mobile number is correct 10 digits
    {
        printf("\033[1;31mInvalid Mobile Number Try Again! Must be 10 digits only.\033[0m\n");
        return 0;
    }
    if (mobile[0] != '6' && mobile[0] != '7' && mobile[0] != '8' && mobile[0] != '9')// fisrt number in mobile number should be 6 7 8 9
    {
        printf("\033[1;31mInvalid Mobile Number Try Again! Should be Digits only,Start with either 6 or 7 or 8 or 9.\033[0m\n");
        return 0;
    }
    for (int i = 0; i < 10; i++) //loop until the length of the mobile number
    {
        if (!isdigit(mobile[i])) // Check Mobile number consists only digits using isdigit function
        {
            printf("\033[1;31mInvalid Mobile Number Try Again! Only are digits allowed.\033[0m\n");
            return 0;
        }
    }
    return 1; // return to create contacts function
}
int unique_mobilenumber(AddressBook* addressbook, char* mobile) // function to check the mobile number is unique or not
{
    Contacts* create = &addressbook->contact_details[addressbook->contact_count];
    for (int i = 0; i < addressbook->contact_count; i++) //loop upto contact count
    {
        Contacts* c = &addressbook->contact_details[i];
        if (strcmp(c->Mobile_number, mobile) == 0) // using strcmp function compare the entered mobile number with the mobile number stored and if equal continue
        {
            printf("\033[1;31mNumber %s exists in the contacts!\033[0m\n", mobile);
            return 0;
        }
    }
    return 1;
}
int email_validate(AddressBook* addressbook, char* mail) // function to check the mail id  is unique or not
{
    Contacts* create = &addressbook->contact_details[addressbook->contact_count];
    int atindex, dotindex; // declare 2 variables to store the index positions for @ and .
    int len = strlen(mail); // find the length of mailid and store it to len
    if (len == 0 || len > 30) //check if len is 0 or len is greater than 30 if yes then invalid
    {
        printf("\033[1;31mInvalid Mail id Try Again! Length Exceeded The Limit.\033[0m\n");
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        char c = mail[i];
        if (!(islower(c) || isdigit(c) || c == '@' || c == '.'))// check if mail id is lowercase,digits and contain @ and .
        {
            printf("\033[1;31mInvalid Mail id Try Again! Only Lowercase ,Digits ,@ and . are allowed.\033[0m\n");
            return 0;
        }
        if (c == ' ') // check if mail id has a single space
        {
            printf("\033[1;31mInvalid Mail id Try Again! Spaces are not allowed.\033[0m\n");
            return 0;
        }
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (mail[i] == '@') // to check mail id has '@'
        {
            atindex = i; //if yes store the index i to atindex
            count++; // increment count 
        }
    }
    if (count > 1) // if more than 1 '@' is found then it should be invalid
    {
        printf("\033[1;31mInvalid Mail id Try Again! There should be only one @ in mail id.\033[0m\n");
        return 0;
    }
    int count1 = 0;
    for (int i = 0; i < len; i++)
    {
        if (mail[i] == '.') // to check mail id has '.'
        {
            dotindex = i; //if yes store the index i to dotindex
            count1++; // increment count1
        }
    }
    if (count1 > 1) // if more than 1 '.' is found then it should be invalid
    {
        printf("\033[1;31mInvalid Mail id Try Again! There should be only one .com in Mail id.\033[0m\n");
        return 0;
    }
    if (dotindex - atindex <= 1) // check if there is something between '@' and '.' by checking difference of the indexes of '@' and '.'
    {
        printf("\033[1;31mInvalid Mail id Try Again! There should something between @ and .com\033[0m\n");
        return 0;
    }
    if (mail[len - 4] != '.' || mail[len - 3] != 'c' || mail[len - 2] != 'o' || mail[len - 1] != 'm') // check if the last 4 characters of mail id is equal to .com,if any single character in .com is missing then invalid
    {
        printf("\033[1;31mInvalid Mail id Try Again! .com should be present and should be at end of Mail id\033[0m\n");
        return 0;
    }
    for (int i = atindex + 1; i < dotindex; i++) //loop from the next position of '@' index to previous position of '.' index
    {
        if (!isalpha(mail[i])) //check the characters between '@' and '.' is alphabet or not,if not then invalid
        {
            printf("\033[1;31mInvalid Mail id Try Again! There should only alphabets between @ and .com\033[0m\n");
            return 0;
        }
    }
    return 1;
}
int unique_email(AddressBook* addressbook, char* mail)
{
    Contacts* create = &addressbook->contact_details[addressbook->contact_count];
    for (int i = 0; i < addressbook->contact_count; i++)
    {
        Contacts* c = &addressbook->contact_details[i];
        if (strcmp(c->Mail_ID, mail) == 0) // using strcmp function compare the entered mail id with the mail id stored and if equal then continue
        {
            printf("\033[1;31mMail %s exists in the contacts!\033[0m\n", mail);
            return 0;
        }
    }
    return 1;
}
int searchbyname(AddressBook* addressbook, char* name) //function to search the stored contacts by name
{
    int count = 0, check = 0, option;
    int indexarr[50]; // create and integer array to store the index if any contacts with duplicate name is found
    for (int i = 0; i < addressbook->contact_count; i++)
    {
        Contacts* c = &addressbook->contact_details[i];
        if (strcmp(c->Name, name) == 0) // using strcmp check if the stored name and entered name is equal or not
        {
            indexarr[count] = i; //if yes then stored the name's index to the first array element since count is 0 initially
            count++; //increment the count
        }
    }
    if (count == 1) // if count is 1 then no duplicate and the contact is found in the list
    {
        check = indexarr[0]; //if no duplicates found the array index 0 will have the contact to be searched ,store it to check
        Contacts* c = &addressbook->contact_details[check];
        printf("\033[0;33mContact found:\033[0m\n");// print the full contact details when found
        printf("\033[0;33mName: %s\033[0m\n", c->Name);
        printf("\033[0;33mMobile Number: %s\033[0m\n", c->Mobile_number);
        printf("\033[0;33mMail ID: %s\033[0m\n", c->Mail_ID);
        return check; // return the index of the contact found on search
    }
    else if (count > 1) // if count is greater than 1 then contacts with duplicate names are found
    {
        printf("\n\033[1;32mMultiple Contacts found! They are Listed Below\033[0m\n"); // list the duplicate contacts like a table
        printf("\033[1;33m+-----+-------+-------------------------+-------------------+-----------------------------+\033[0m\n");
        printf("\033[1;33m| SlNo| Index | Name                    | Mobile Number     | Mail ID                     |\033[0m\n");
        printf("\033[1;33m+-----+-------+-------------------------+-------------------+-----------------------------+\033[0m\n");
        for (int i = 0; i < count; i++) // loop until how may duplicates are found
        {
            check = indexarr[i]; //store the index of duplicate name to check
            Contacts* c = &addressbook->contact_details[check];
            printf("\033[0;32m| %-4d| %-6d| %-23s| %-18s| %-28s|\033[0m\n", i + 1, check, c->Name, c->Mobile_number, c->Mail_ID);
        }
        printf("\033[1;33m+-----+-------+-------------------------+-------------------+-----------------------------+\033[0m\n");
        printf("\033[1;34mSelect The Sl No of the Contact to be Searched: \033[0m");
        scanf("%d", &option);
        if (option > 0 && option <= count)// check if entered option is in range of 1 and total duplicate count
        {
            check = indexarr[option - 1]; //store indexarr[option -1] is used because we should access the first index of array(0) if 1 is pressed
            Contacts* c = &addressbook->contact_details[check];
            //print all the details of the contact whose slno is selected
            printf("\033[0;33mName: %s\033[0m\n", c->Name);
            printf("\033[0;33mMobile Number: %s\033[0m\n", c->Mobile_number);
            printf("\033[0;33mMail ID: %s\033[0m\n", c->Mail_ID);
            return check; //return the index of contact found
        }
        else//if selected option is below or above the range of option selection then it's invalid
        {
            printf("\033[1;31mInvalid option,Try Again!\033[0m\n");
            return -1;
        }
    }
    else if (count == 0)//if count is 0 then there is no contact existing
    {
        printf("\033[1;31mContact with name %s is not found Try Again.\033[0m\n", name);
        return -1;
    }
}
int searchbymobilenumber(AddressBook* addressbook, char* mobile) //function to serach the contact by mobile number
{
    for (int i = 0; i < addressbook->contact_count; i++)//loop until the total count count
    {
        Contacts* c = &addressbook->contact_details[i];
        if (strcmp(c->Mobile_number, mobile) == 0) // using strcmp compare if the entered mobile number and mobile number in the list is equal or not
        {
            printf("\033[0;33mContact found:\033[0m\n");// if yes then print all the contact details of the searched contact
            printf("\033[0;33mName: %s\033[0m\n", c->Name);
            printf("\033[0;33mMobile Number: %s\033[0m\n", c->Mobile_number);
            printf("\033[0;33mMail ID: %s\033[0m\n", c->Mail_ID);
            return i; // return the index of the contact searched
        }
    }
    printf("\033[1;31mContact with mobile number %s not found Try Again.\033[0m\n", mobile);
    return -1;
}
int searchbyemail(AddressBook* addressbook, char* email) //function to serach the contact by mail id
{
    for (int i = 0; i < addressbook->contact_count; i++)
    {
        Contacts* c = &addressbook->contact_details[i];
        if (strcmp(c->Mail_ID, email) == 0) // using strcmp compare if the entered mail id and mail id in the list is equal or not
        {
            printf("\033[0;33mContact found!\n");// if yes then print all the contact details of the searched contact
            printf("\033[0;33mName: %s\033[0m\n", c->Name);
            printf("\033[0;33mMobile Number: %s\033[0m\n", c->Mobile_number);
            printf("\033[0;33mMail ID: %s\033[0m\n", c->Mail_ID);
            return i; // return the index of the contact searched
        }
    }
    printf("\033[1;31mContact with mail id %s not found Try Again.\033[0m\n", email);
    return -1;
}
int create_contact(AddressBook* addressbook) // function to add a contact to the list
{
    char ch;
    Contacts* create = &addressbook->contact_details[addressbook->contact_count];
    printf("\033[1;33mEnter Name: \033[0m");
    scanf(" %[^\n]", create->Name);
    while (!name_validate(addressbook, create->Name)) //validate the name if not valid try again until valid
    {
        printf("\033[1;33mEnter Name: \033[0m");
        scanf(" %[^\n]", create->Name);
    }
    printf("\033[1;33mEnter Mobile Number: \033[0m");
    scanf("%s", create->Mobile_number);
    while (!mobilenumber_validate(addressbook, create->Mobile_number) || !unique_mobilenumber(addressbook, create->Mobile_number)) //validate the mobile number and also check its unique or not, if not try again until valid
    {
        printf("\033[1;33mEnter Mobile Number: \033[0m");
        scanf("%s", create->Mobile_number);
    }
    printf("\033[1;33mEnter Mail ID: \033[0m");
    scanf(" %[^\n]", create->Mail_ID);
    while (!email_validate(addressbook, create->Mail_ID) || !unique_email(addressbook, create->Mail_ID)) //validate the mail id and also check its unique or not, if not try again until valid
    {
        printf("\033[1;33mEnter Mail ID: \033[0m");
        scanf(" %[^\n]", create->Mail_ID);
    }
    printf("-------------------------------------------------\n");
    addressbook->contact_count++; // increment contact count to store another contact
    save_contacts(addressbook); // save the contacts to the file contacts.txt
    printf("\033[1;32mContact added successfully.\033[0m\n");
    printf("\033[0;34mDo you want to Continue Create(Y/N) : \033[0m");// Ask the user to continue or not
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') // if yes then recursively call the function again 
    {
        create_contact(addressbook);
    }
    else // if not return to the main menu
    {
        return 0;
    }
}
void list_contacts(AddressBook* addressbook) //function to list contacts
{
    printf("\033[1;33m+-----+----------------------+-----------------+------------------------------+\033[0m\n");
    printf("\033[1;33m| SlNo|       Name           |  Mobile Number  |      Mail ID                 |\033[0m\n");
    printf("\033[1;33m+-----+----------------------+-----------------+------------------------------\033[0m\n");
    for (int i = 0; i < addressbook->contact_count; i++)
    {
        Contacts* c = &addressbook->contact_details[i];
        printf("\033[0;32m| %-4d| %-20s | %-15s | %-28s|\033[0m\n", i + 1, c->Name, c->Mobile_number, c->Mail_ID); // display all the stored contacts
    }
    printf("\033[1;33m+-----+----------------------+-----------------+------------------------------+\033[0m\n");
}
int search_contacts(AddressBook* addressbook) //function to serach the contacts
{
    char ch;
    int option, index;
    scanf("%d", &option);// choose the option how to search the contact by name,number or mail id
    switch (option)
    {
    case 1: // if search by name
    {
        char name[32];
        printf("\033[1;33mEnter Name to search: \033[0m");
        scanf(" %[^\n]", name);
        index = searchbyname(addressbook, name); // call the searchbyname function and store return value to index
        while (!name_validate(addressbook, name) || index == -1) // if the entered name is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            printf("\033[1;33mEnter Name to search: \033[0m");
            scanf(" %[^\n]", name);
        }
        break;
    }
    case 2: // if search by mobile number
    {
        char mobile[11];
        printf("\033[1;33mEnter Mobile Number to search: \033[0m");
        scanf("%s", mobile);
        index = searchbymobilenumber(addressbook, mobile);  // call the searchbymobilenumber function and store return value to index
        while (!mobilenumber_validate(addressbook, mobile) || index == -1) //if the entered mobile number is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            printf("\033[1;33mEnter Mobile Number to search: \033[0m");
            scanf("%s", mobile);
        }
        break;
    }
    case 3: // if search by mail id
    {
        char mail[35];
        printf("\033[1;33mEnter Mail ID to search: \033[0m");
        scanf(" %[^\n]", mail);
        index = searchbyemail(addressbook, mail); // call the searchbyemail function and store return value to index
        while (!email_validate(addressbook, mail) || index == -1) //if the entered mail id is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            printf("\033[1;33mEnter Mail ID to search: \033[0m");
            scanf(" %[^\n]", mail);
        }
        break;
    }
    default: //exit
    {
        return -1;
    }
    }
    printf("\033[0;34mDo you want to Continue Search(Y/N):\033[0m");// Ask the user do you want to continue or not
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') //if yes recursively call the function again
    {
        printf("\033[0;35mSearch Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : \033[0m");
        search_contacts(addressbook);
    }
    return index;
}
int edit_contact(AddressBook* addressbook) //function for edit contact
{
    char ch;
    int choose, index;
    scanf("%d", &choose);// choose the option how to search the contact by name,number or mail id for edit purpose
    switch (choose)
    {
    case 1: // if search by name
    {
        char name[32];
    name:
        printf("\033[1;33mEnter Name to search: \033[0m");
        scanf(" %[^\n]", name);
        index = searchbyname(addressbook, name); // call the searchbyname function and store return value to index
        while (!name_validate(addressbook, name) || index == -1) // if the entered name is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            goto name;
        }
        break;
    }
    case 2: // if search by mobile number
    {
        char mobile[11];
    mobilenumber:
        printf("\033[1;33mEnter Mobile Number to search: \033[0m");
        scanf("%s", mobile);
        index = searchbymobilenumber(addressbook, mobile);  // call the searchbymobilenumber function and store return value to index
        while (!mobilenumber_validate(addressbook, mobile) || index == -1) //if the entered mobile number is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            goto mobilenumber;
        }
        break;
    }
    case 3: // if search by mail id
    {
        char mail[35];
    emailid:
        printf("\033[1;33mEnter Mail ID to search: \033[0m");
        scanf(" %[^\n]", mail);
        index = searchbyemail(addressbook, mail); // call the searchbyemail function and store return value to index
        while (!email_validate(addressbook, mail) || index == -1) //if the entered mail id is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            goto emailid;
        }
        break;
    }
    default: //exit
    {
        return -1;
    }
    }
    int option;
    char name[30], mobilenumber[11], emailid[30];
    //edit menu
    printf("What do you want to edit?\n");
    printf("\033[1;33m1.Name\033[0m\n");
    printf("\033[1;33m2.Mobile Number\033[0m\n");
    printf("\033[1;33m3.Mail ID\033[0m\n");
    printf("\033[1;33m4.All Fields\033[0m\n");
    printf("\033[1;33m5.Exit\033[0m\n");
    printf("Enter the option: ");
    scanf("%d", &option);
    Contacts* c = &addressbook->contact_details[index]; // for edit use the index of contact found on search by parameters
    switch (option)
    {
    case 1: //edit by name
    {
        printf("\033[1;33mEnter New Name: \033[0m");
        scanf(" %[^\n]", name);
        while (!name_validate(addressbook, name))//validate the name if invalid then try agin
        {
            printf("\033[1;33mEnter New Name: \033[0m");
            scanf(" %[^\n]", name);
        }
        strcpy(c->Name, name);// store the new name after edit to the list using strcpy function
        break;
    }
    case 2: //edit by mobile number
    {
        printf("\033[1;33mEnter New Mobile Number: \033[0m");
        scanf("%s", mobilenumber);
        while (!mobilenumber_validate(addressbook, mobilenumber) || !unique_mobilenumber(addressbook, mobilenumber)) //validate the mobile number and check for unique if not then try again
        {
            printf("\033[1;33mEnter Mobile Number: \033[0m");
            scanf("%s", mobilenumber);
        }
        strcpy(c->Mobile_number, mobilenumber); //store the new mobile number after edit to the list using strcpy function
        break;
    }
    case 3: //edit by mail id
    {
        printf("\033[1;33mEnter New Mail ID: \033[0m");
        scanf(" %[^\n]", emailid);
        while (!email_validate(addressbook, emailid) || !unique_email(addressbook, emailid)) //validate the mail id and check for unique if not then try agin
        {
            printf("\033[1;33mEnter New Mail ID: \033[0m");
            scanf(" %[^\n]", emailid);
        }
        strcpy(c->Mail_ID, emailid); //store the new mobile number after edit to the list using strcpy function
        break;
    }
    case 4: //edit by all name,mobile number and mail id(All)
    {
        printf("\033[1;33mEnter New Name: \033[0m");
        scanf(" %[^\n]", name);
        while (!name_validate(addressbook, name))
        {
            printf("\033[1;33mEnter New Name: \033[0m");
            scanf(" %[^\n]", name);
        }
        strcpy(c->Name, name);
        printf("\033[1;33mEnter New Mobile Number: \033[0m");
        scanf("%s", mobilenumber);
        while (!mobilenumber_validate(addressbook, mobilenumber) || !unique_mobilenumber(addressbook, mobilenumber))
        {
            printf("\033[1;33mEnter New Mobile Number: \033[0m");
            scanf("%s", mobilenumber);
        }
        strcpy(c->Mobile_number, mobilenumber);
        printf("\033[1;33mEnter New Mail ID: \033[0m");
        scanf(" %[^\n]", emailid);
        while (!email_validate(addressbook, emailid) || !unique_email(addressbook, emailid))
        {
            printf("\033[1;33mEnter New Mail ID: \033[0m");
            scanf(" %[^\n]", emailid);
        }
        strcpy(c->Mail_ID, emailid);
        break;
    }
    default://exit 
        return 0;
    }
    save_contacts(addressbook);// save contacts after edit
    printf("\033[1;32mContact edited successfully!\033[0m\n");
    printf("\033[0;34mDo you want to Continue Edit(Y/N): \033[0m");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        printf("\033[0;35mEdit Contact menu : \n1.Search By Name to edit\n2.Search By Mobile number to edit\n3.Search By Mail ID to edit\n4.Exit\nEnter the option : \033[0m");
        edit_contact(addressbook);
    }
    else
    {
        return 0;
    }
}
int delete_contact(AddressBook* addressbook) //function to delete contact
{
    char ch;
    int choose, index;
    scanf("%d", &choose);// choose the option how to search the contact by name,number or mail id for delete purpose
    switch (choose)
    {
    case 1: // if search by name
    {
        char name[32];
    name1:
        printf("\033[1;33mEnter Name to search: \033[0m");
        scanf(" %[^\n]", name);
        index = searchbyname(addressbook, name); // call the searchbyname function and store return value to index
        while (!name_validate(addressbook, name) || index == -1) // if the entered name is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            goto name1;
        }
        break;
    }
    case 2: // if search by mobile number
    {
        char mobile[11];
    mobilenumber1:
        printf("\033[1;33mEnter Mobile Number to search: \033[0m");
        scanf("%s", mobile);
        index = searchbymobilenumber(addressbook, mobile);  // call the searchbymobilenumber function and store return value to index
        while (!mobilenumber_validate(addressbook, mobile) || index == -1) //if the entered mobile number is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            goto mobilenumber1;
        }
        break;
    }
    case 3: // if search by mail id
    {
        char mail[35];
    emailid1:
        printf("\033[1;33mEnter Mail ID to search: \033[0m");
        scanf(" %[^\n]", mail);
        index = searchbyemail(addressbook, mail); // call the searchbyemail function and store return value to index
        while (!email_validate(addressbook, mail) || index == -1) //if the entered mail id is not valid and if contact not found allow user to try again (if index is -1 then contact not found)
        {
            goto emailid1;
        }
        break;
    }
    default: //exit
    {
        return -1;
    }
    }
    printf("\033[0;34mDo you want to Delete This Contact (Y/N) : \033[0m");// prompt message before delete
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') //if yes then 
    {
        for (int j = index; j < addressbook->contact_count - 1; j++)
        {
            addressbook->contact_details[j] = addressbook->contact_details[j + 1]; // delete by using shifting the details to previous index
        }
        addressbook->contact_count--;//Decrementing the count to eliminate the contact details
        save_contacts(addressbook);//save the contact after delete
        printf("\033[1;32mContact deleted successfully!\033[0m\n");
    }
    printf("\033[0;34mDo you want to Continue Delete(Y/N) : \033[0m");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        printf("\033[0;35mDelete Contact menu : \n1.Search By Name to delete\n2.Search By Mobile number to delete\n3.Search By Mail ID to delete\n4.Exit\nEnter the option : \033[0m");
        delete_contact(addressbook);
    }
    else
    {
        return 0;
    }
}
void save_contacts(AddressBook* addressbook) // function to save the details to the file
{
    FILE* fp;// Declare the file pointer
    fp = fopen("contacts.txt", "w");// open file in the write mode 
    //no need to check fp==NULL because write mode create a file if it doesnot exist
    fprintf(fp, "#%d\n", addressbook->contact_count); //write total contact count to the file
    for (int i = 0; i < addressbook->contact_count;i++)
    {
        Contacts* c = &addressbook->contact_details[i];
        fprintf(fp, "%s,%s,%s\n", c->Name, c->Mobile_number, c->Mail_ID);//write the contact details name,mobilenumber and mail id to file seperated by , using fprintf
    }
    fclose(fp);// close the file
    return;
}
void load_contacts(AddressBook* addressbook) // function to read the details to the file
{
    FILE* fp;
    fp = fopen("contacts.txt", "r"); // open file in the read only mode
    if (fp == NULL) //if fp is returning NULL then file cannot be opened
    {
        printf("Error! File doesnot exist");
        return;
    }
    fscanf(fp, "#%d\n", &addressbook->contact_count); //read total contact count from the file
    for (int i = 0; i < addressbook->contact_count;i++)
    {
        Contacts* c = &addressbook->contact_details[i];
        fscanf(fp, "%[^,],%[^,],%[^\n]\n", c->Name, c->Mobile_number, c->Mail_ID); //read the contact details name,mobilenumber and mail id to file seperated by , using fscanf(don't read anything other than these 3)
    }
    fclose(fp);// close the file
    return;
}


