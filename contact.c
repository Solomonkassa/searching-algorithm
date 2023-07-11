#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[80];
    char phone[100];
};

// Function to input contacts
int inputContacts(struct Contact contacts[], int *numContacts) {
    while (*numContacts < MAX_CONTACTS) {
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

// Function to search for a contact
void searchContact(const struct Contact contacts[], int numContacts) {
    char searchName[80];
    printf("\nEnter a name to search (or 'quit' to exit): ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    while (strcmp(searchName, "quit") != 0) {
        int found = 0;
        for (int i = 0; i < numContacts; i++) {
            if (strcmp(contacts[i].name, searchName) == 0) {
                printf("\nContact found!\n");
                printf("Name: %s\n", contacts[i].name);
                printf("Phone: %s\n", contacts[i].phone);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nContact not found!\n");
        }

        printf("\nEnter a name to search (or 'quit' to exit): ");
        fgets(searchName, sizeof(searchName), stdin);
        searchName[strcspn(searchName, "\n")] = '\0';
    }
}

int main(void) {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    printf("===== Contact Management System =====\n");

    // Input contacts
    numContacts = inputContacts(contacts, &numContacts);

    // Search for a contact
    searchContact(contacts, numContacts);

    return 0;
}
