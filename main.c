#include "main.h"


int main(void) 
{
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    printf("===== Contact Management System =====\n");

    numContacts = inputContacts(contacts, &numContacts);

    searchContact(contacts, numContacts);

    saveContacts(contacts, numContacts);

    return 0;
}
