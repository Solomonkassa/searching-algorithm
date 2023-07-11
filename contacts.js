const MAX_CONTACTS = 100;

class Contact {
    constructor(name, phone) {
        this.name = name;
        this.phone = phone;
    }
}

function inputContacts(contacts) {
    let numContacts = 0;
    while (numContacts < MAX_CONTACTS) {
        const name = prompt("\nEnter name (or 'quit' to exit): ");
        if (name === "quit") {
            break;
        }
        const phone = prompt("Enter phone: ");
        contacts.push(new Contact(name, phone));
        numContacts++;
    }
    return numContacts;
}

function searchContact(contacts) {
    let searchName = prompt("\nEnter a name to search (or 'quit' to exit): ");
    while (searchName !== "quit") {
        let found = false;
        for (const contact of contacts) {
            if (contact.name === searchName) {
                console.log("\nContact found!");
                console.log("Name:", contact.name);
                console.log("Phone:", contact.phone);
                found = true;
                break;
            }
        }
        if (!found) {
            console.log("\nContact not found!");
        }
        searchName = prompt("\nEnter a name to search (or 'quit' to exit): ");
    }
}

function saveContacts(contacts) {
    let content = "";
    for (const contact of contacts) {
        content += `Name: ${contact.name}\n`;
        content += `Phone: ${contact.phone}\n`;
        content += "==============================\n";
    }
    console.log("Contacts saved successfully!");
    console.log(content);
    // Code to save 'content' to an external file in JavaScript depends on the environment, such as Node.js or a browser-based solution.
    // The specific file saving mechanism will vary based on the environment and is beyond the scope of this code snippet.
}

const contacts = [];
console.log("===== Contact Management System =====");
const numContacts = inputContacts(contacts);
searchContact(contacts);
saveContacts(contacts);
