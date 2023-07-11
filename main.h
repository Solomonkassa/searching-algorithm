#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[80];
    char phone[100];
};

int inputContacts(struct Contact contacts[], int *numContacts);

void searchContact(const struct Contact contacts[], int numContacts);

void saveContacts(const struct Contact contacts[], int numContacts);


#endif /* MAIN_H */
