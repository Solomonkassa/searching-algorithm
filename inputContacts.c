#include "main.h"

int inputContacts(struct Contact contacts[], int *numContacts) 
{
    while (*numContacts < MAX_CONTACTS)
      {
        printf("\nEnter name (or 'quit' to exit): ");
        fgets(contacts[*numContacts].name, sizeof(contacts[*numContacts].name), stdin);
        contacts[*numContacts].name[strcspn(contacts[*numContacts].name, "\n")] = '\0';

        if (strcmp(contacts[*numContacts].name, "quit") == 0) {
            break;
        }

        printf("Enter phone: ");
        fgets(contacts[*numContacts].phone, sizeof(contacts[*numContacts].phone), stdin);
        contacts[*numContacts].phone[strcspn(contacts[*numContacts].phone, "\n")] = '\0';

        (*numContacts)++;
    }
    return *numContacts;
}
