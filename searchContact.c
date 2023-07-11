#include "main.h"

void searchContact(const struct Contact contacts[], int numContacts)
{
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
