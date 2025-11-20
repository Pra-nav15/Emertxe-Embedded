#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

/* Function declarations */
//void init_intitalization(AddressBook *);
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
void save_contacts(AddressBook *);
void load_contacts(AddressBook *);
int name_validate(AddressBook *, char *);
int mobilenumber_validate(AddressBook *,char *);
int email_validate(AddressBook *,char *);
int searchbyname(AddressBook *,char *);
int searchbymobilenumber(AddressBook *,char *);
int searchbyemail(AddressBook *,char *);
int unique_mobilenumber(AddressBook *,char *);
int unique_email(AddressBook *, char*);


#endif // CONTACT_H
       // CONTACT_H