#include "contact.h"

//sunfunction in searchcontact-->Phone
int searchbyphone(AddressBook *addressBook)
{
    char number[20];
    int status, i;
    printf("Enter the number want to search :");
    scanf("%s", number);

    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, number) == 0)
        {
            status = 1;
            break;
        }
    }
    if (status == 1)
    {
        printf("\t******PhoneNumber Found******\n");
        printf("\tName : %s\n", addressBook->contacts[i].name);
        printf("\tPhone : %s\n", addressBook->contacts[i].phone);
        printf("\tEmail :%s\n", addressBook->contacts[i].email);
        printf("\n\n");
        return i;
    }
    else
    {

        printf("\t******Number Not Found******\n");
        return -1;
    }
    // return i;
}

// sun function in searchcontact-->Email
int searchbymail(AddressBook *addressBook)
{
    char mail[20];
    int i, status;
    printf("Enter the Mail want to search: ");
    scanf("%s", mail);

    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, mail) == 0)
        {
            status = 1;
            break;
        }
    }
    if (status == 1)
    {
        printf("\t******Email Found******\n");
        printf("\tName : %s\n", addressBook->contacts[i].name);
        printf("\tPhone : %s\n", addressBook->contacts[i].phone);
        printf("\tEmail :%s\n", addressBook->contacts[i].email);
        printf("\n");
        return i;
    }
    else
    {
        printf("\t****** EMAIL NOT Found********\n");
        return -1;
    }
}


// sub function in searchcontact-->Name
int searchbyname(AddressBook *addressBook)
{
    char name[20];
    int status=0, i,j;
    printf("Enter the name whant to search____ :");
    scanf(" %[^\n]", name);
    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(name, addressBook->contacts[i].name) == 0)
        {
            printf("\t******Name Found******\n");
            printf("\tName : %s\n", addressBook->contacts[i].name);
            printf("\tPhone : %s\n", addressBook->contacts[i].phone);
            printf("\tEmail :%s\n", addressBook->contacts[i].email);
            printf("\n\n");
            j=i;

            status++;
        }
    }


    if (status == 1)
    {
        // printf("\t******Name Found******\n");
        // printf("\tName : %s\n", addressBook->contacts[i].name);
        // printf("\tPhone : %s\n", addressBook->contacts[i].phone);
        // printf("\tEmail :%s\n", addressBook->contacts[i].email);
        // printf("\n\n");
        return j;
    }
    else if (status>1)
    {
        int x;
        printf("*****Multipal Same Names are Present*****\n");
        printf("Enter 1.To search by number\nEnter 2.To search by email\n");
        scanf("%d",&x);
        if(x==1)
        {
            return searchbyphone(addressBook);
        }
        else if(x==2)
        {
            return searchbymail(addressBook);
        }

    }
    else
    {  
        printf("\t*****NAME Not Found******\n");
        return -1;
    }
}




// list all Contact-->option 6
void listContacts(AddressBook *addressBook)
{
    printf("\n%d Contacts\n", addressBook->contactCount);
    printf("%-4s %-20s %-15s %-30s\n","No","Name","Phone","Email");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // printf("Contact [%d]:\t", i + 1);
        // printf("Name: %s\t", addressBook->contacts[i].name);
        // printf("Phone: %s\t", addressBook->contacts[i].phone);
        // printf("Email: %s\n", addressBook->contacts[i].email);

        printf("[%d]  |  %-20s %-15s %-30s\n", i + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        
        
    }
    printf("------------------------------------------------------------\n");
}



void creat_name(AddressBook*addressBook,int i)
{
    
    // char name[20];
    printf("enter the new name : ");
    scanf(" %[^\n]", addressBook->contacts[i].name);
}

void create_number(AddressBook *addressBook,int i)
{
    char number[20];
    while (1)
    {
        int count = 0;
        printf("enter the new numbers :");
        scanf("%s", number);
        int j = 0,k;

        for(k=0;k<addressBook->contactCount;k++)
        {
        if(strcmp(number,addressBook->contacts[k].phone)==0)
        {
            printf("Number is already present");
            k=88;//just for refference;
            break;
        }
        }

        if(k!=88)
        {

        while (number[j] != '\0')
        {
            if (number[j] >= '0' && number[j] <= '9')
                count++;
            j++;
        }
        if (count != 10)
        {
            printf("_______Invalid number_______");
        }
        else
        {
            strcpy(addressBook->contacts[i].phone, number);
            break;
        }
        }
        
        printf("\n");
    }
}


void creat_email(AddressBook *addressBook, int i)
{
     char mail[30];
    char check[10] = ".com";
    while (1)
    {
        int j = 0,k, count = 0;
        int flage = 0;
        printf("enter new  email :");
        scanf("%s", mail);

        for(k=0;k<addressBook->contactCount;k++)
        {
        if(strcmp(mail,addressBook->contacts[k].email)==0)
        {
            printf("Mail is already present\n");
            k=88;//just for refference;
            break;
        }
        }

        if(k!=88)
        {

        for (j = 0; mail[j] != '\0'; j++)
        {
            if (mail[j] == '@')
            {
                count = 1;
                break;
            }
        }


        int lencheck = strlen(check);
        int lenmail = strlen(mail);
        if (lenmail > lencheck)
        {
            if (strcmp(&mail[lenmail - lencheck], check) == 0)
            {
                flage = 1;
            }
        }

        if (count != 1 || flage != 1)
        {
            printf("________invalid email_________\n");
        }
        else
        {
            strcpy(addressBook->contacts[i].email, mail);
            printf("valid emai\n");
            break;
        }
        }
        printf("\n");
    }
}

// creat contact -->option 1;
void createContact(AddressBook *addressBook)
{
    int i=addressBook->contactCount++;
    creat_name(addressBook, i);
    // char number[20];
    create_number(addressBook, i);
    creat_email(addressBook, i);
    
}

// search contact-->option 3
void searchContact(AddressBook *addressBook)
{
    int choice = 0;
    printf("1.search by name\n2.search by phone\n3.search by email\n");
    printf("Enter choice___ :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        searchbyname(addressBook);
        break;
    case 2:
        searchbyphone(addressBook);
        break;
    case 3:
        searchbymail(addressBook);
        break;
    }
}

void editContact(AddressBook *addressBook)
{
    int choice = 0;
    printf("1.Edit name\n2.Edit phone\n3.Edit email\n");
    printf("Enter choice :");
    scanf("%d", &choice);
    int i;
    switch (choice)
    {

    case 1:
        i = searchbyname(addressBook);
        if(i!=-1)
        {
        printf("Enter new name:");
        scanf(" %[^\n]", addressBook->contacts[i].name);
        }

        break;
    case 2:
    {
        i = searchbyphone(addressBook);
        if (i != -1)
        {
            create_number(addressBook, i);
        }
       

        break;
    }

    case 3:
    {
        i = searchbymail(addressBook);
        if(i!=-1)
        {
        creat_email(addressBook, i);
        }
        

        break;
    }
    }
}

void deleteContact(AddressBook *addressBook)
{
    int i, choice;
    printf("\t1.delete By Name\n\t2.delete By number\n\t3.delete By Email\n");
    printf("Enter the choice__ :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        i = searchbyname(addressBook);
        if(i!=-1)
        {
        for (int j = i; j < addressBook->contactCount; j++)
        {
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        }
        addressBook->contactCount--;
    
        printf("********Contact Deleted*********\n\n");
        }
    }
        break;

    case 2:
    {
        i = searchbyphone(addressBook);
        if(i!=-1)
        {
        for (int j = i; j < addressBook->contactCount; j++)
        {
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        }
        addressBook->contactCount--;
    
        printf("*******Contact Deleted******\n\n");
        }
    }
        break;

    case 3:
    {
        i = searchbymail(addressBook);
        if(i!=-1)
        {
        for (int j = i; j < addressBook->contactCount; j++)
        {
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        }
        addressBook->contactCount--;
        printf("*******Contact Deleted******\n\n");
        }
    
        
    }
        break;
    }
}

void saveContact(AddressBook *addressBook)
{

   FILE *fp;
   int i;
    fp=fopen("copy.csv","w");
    if(fp==NULL)
    {
        perror("Error:");
        return;
    }
    
    fprintf(fp,"#%d#\n",addressBook->contactCount);



    for( i=0;i<addressBook->contactCount;i++)
    {
    fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fp);

    printf("******Contact saved******\n");
    


    
}

    
