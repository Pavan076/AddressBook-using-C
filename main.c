#include "contact.h"
#include <ctype.h>
int main()
{
	//creat structure variable
	AddressBook addressBook;//datatype and variable name
   
    //all function calls should be inside the main
    addressBook.contactCount = 0; 
    initialize(&addressBook);

    int choice = 0;
        int i=1,n;
    
    
    do
    {
        printf("  ------------Menu:--------\n");
        printf("\t1.Add Contact\n\t2.Delete contact\n\t3.search contact\n\t4. edit conact\n\t5. save conact\n\t6.list all conact\n\t7. To Exit\n");
        printf("\tEnter the choice :");
        scanf("%d",&choice);
        printf("------------------------------\n");
       
        switch(choice)
        {
        case 1:
            createContact(&addressBook);
        break;
        case 2:
            deleteContact(&addressBook);
        break;
        case 3:
            searchContact(&addressBook);
        break;
        case 4:
            editContact(&addressBook);
        break;
        case 5:
            saveContact(&addressBook); 
        break;
        case 6:
            listContacts(&addressBook);
        break;
        default:
            printf("----INvalid choice enter bw 1 to 7!!!!----\n");
        
        break;

        
        }
       
      
        getchar();

    
    }while (choice!=7);
}

