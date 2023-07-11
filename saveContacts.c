#include "main.h"

void saveContacts(const struct Contact contacts[], int numContacts) 
{
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        fprintf(file, "Name: %s\n", contacts[i].name);
        fprintf(file, "Phone: %s\n", contacts[i].phone);
        fprintf(file, "==============================\n");
    }

    fclose(file);
    printf("Contacts saved successfully!\n");
}
