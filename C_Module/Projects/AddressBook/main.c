/*
                                  Project Documentation
Name: Pranav Prasad
Date: 21/09/2025
Description:
• This project is an AddressBook System made in C.
• It helps users to add, view, search, edit, store and delete contacts easily.
• Each contact has three details: name, mobile number, and email.
• The program checks every input to make sure it is correct(validations for all 3).
• Names must only have letters and spaces.
• Mobile numbers must be exactly ten digits starting with 6, 7, 8, or 9.
• Emails must be in the right format and must end with ".com".
• The program makes sure that no two contacts have the same mobile number or email.
• All contacts are saved into a file so that they are not lost when the program closes.
• When the program starts, it loads the saved contacts.
• Every change like adding, editing, or deleting is updated in the file.
• The system uses a simple menu where the user can choose what they want to do.
• It shows clear messages for errors and successful actions with proper colour code.
• This project shows how to use pointers, functions, structures, validations, file handling, and menus.
*/
#include<stdio.h>
#include "contact.h"
int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;
    load_contacts(&addressbook);// call only once when the program starts

    // init_intitalization(&addressbook);

    while (1)
    {
        printf("\033[0;34m\n=============Address Book=============\033[0m\n"); /* Give a prompt message for a user */
        printf("\033[0;35m1.Add contact\n2.Search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Save and Exit\033[0m\n");
        printf("\033[0;33mEnter the option : \033[0m");
        scanf("%d", &option);
        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook);// pass by reference is used here because we want to modify the original structure in the given location
            break;
        }
        case 2:
        {
            printf("\033[0;35mSearch Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : \033[0m"); /* Providing menu */
            search_contacts(&addressbook);
            break;
        }
        case 3:
            printf("\033[0;35mEdit Contact menu : \n1.Search By Name to edit\n2.Search By Mobile number to edit\n3.Search By Mail ID to edit\n4.Exit\nEnter the option : \033[0m"); /* Providing menu */
            edit_contact(&addressbook);
            break;

        case 4:
        {
            printf("\033[0;35mDelete Contact menu : \n1.Search By Name to delete\n2.Search By Mobile number to delete\n3.Search By Mail ID to delete\n4.Exit\nEnter the option : \033[0m"); /* Providing menu */
            delete_contact(&addressbook);
            break;
        }
        case 5:
        {
            printf("\033[0;36mList Contacts\033[0m\n");
            list_contacts(&addressbook);
            break;
        }

        case 6:
            printf("\033[0;36mSaving contacts...\033[0m\n");
            save_contacts(&addressbook);
            break;

        case 7:
            printf("\033[0;36mINFO : Save and Exit...\033[0m\n");
            save_contacts(&addressbook);
            return 0;

        default:
            printf("\033[0;31mInvalid option\033[0m\n");
            break;
        }
    }
    return 0;
}
