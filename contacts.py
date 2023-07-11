MAX_CONTACTS = 100

class Contact:
    def __init__(self, name, phone):
        self.name = name
        self.phone = phone

def inputContacts(contacts):
    numContacts = 0
    while numContacts < MAX_CONTACTS:
        name = input("\nEnter name (or 'quit' to exit): ")
        if name == "quit":
            break
        phone = input("Enter phone: ")
        contacts.append(Contact(name, phone))
        numContacts += 1
    return numContacts

def searchContact(contacts):
    searchName = input("\nEnter a name to search (or 'quit' to exit): ")
    while searchName != "quit":
        found = False
        for contact in contacts:
            if contact.name == searchName:
                print("\nContact found!")
                print("Name:", contact.name)
                print("Phone:", contact.phone)
                found = True
                break
        if not found:
            print("\nContact not found!")
        searchName = input("\nEnter a name to search (or 'quit' to exit): ")

def saveContacts(contacts):
    with open("contacts.txt", "w") as file:
        for contact in contacts:
            file.write(f"Name: {contact.name}\n")
            file.write(f"Phone: {contact.phone}\n")
            file.write("==============================\n")
    print("Contacts saved successfully!")

if __name__ == "__main__":
    contacts = []
    print("===== Contact Management System =====")
    numContacts = inputContacts(contacts)
    searchContact(contacts)
    saveContacts(contacts)
