#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>


typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount; 
} AddressBook;

void createContact(AddressBook *addressBook);
void  searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContact(AddressBook *addressBook);


int searchbyname(AddressBook *addressBook);
int searchbyphone(AddressBook *addressBook);
int searchbymail(AddressBook *addressBook);

void create_number(AddressBook *addressBook,int i);
void creat_email(AddressBook *addressBook, int i);
void creat_name(AddressBook*addressBook,int i);

#endif