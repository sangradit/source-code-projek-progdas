#include "user_interface.h"
#include <iostream>

using namespace std;

UserInterface::UserInterface(Phonebook& pb) : phonebook(pb) {}

void UserInterface::printHeader() {
    cout << "=======================================\n"
         << " _____ _               _           _   \n"
         << "|  _  | |_ ___ ___ ___| |_ ___ ___| |_ \n"
         << "|   __|   | . |   | -_| . | . | . | '_|\n"
         << "|__|  |_|_|___|_|_|___|___|___|___|_,_|\n"
         << "=======================================\n"
         << "All changes will be permanently saved\nif the program is terminated properly.\n";
}

void UserInterface::mainMenu() {
    int choice;
    do {
        cout << "\nPhonebook Menu:\n";
        cout << "1. View All Contacts\n";
        cout << "2. Search Contacts by Name\n";
        cout << "3. Add Contact\n";
        cout << "4. Remove Contact\n";
        cout << "5. Edit Contact\n";
        cout << "6. Add to Favorites\n";
        cout << "7. Sort Contacts\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                phonebook.viewAllContacts();
                break;
            }
            case 2: {
                string searchName;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, searchName);
                phonebook.viewContactByName(searchName);
                break;
            }
            case 3: {
                Contact newContact;
                string name, phoneNumber, address, email;
                cout << "Enter contact name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter email: ";
                getline(cin, email);

                newContact.setName(name);
                newContact.setPhoneNumber(phoneNumber);
                newContact.setAddress(address);
                newContact.setEmail(email);
                newContact.setIsFavorite(false);

                phonebook.addContact(newContact);
                break;
            }
            case 4: {
                int contactID;
                phonebook.listAllContacts();
                cout << "Enter contact ID to remove: ";
                cin >> contactID;
                phonebook.removeContact(contactID);
                break;
            }
            case 5: {
                int contactID;
                phonebook.listAllContacts();
                cout << "Enter contact ID to edit: ";
                cin >> contactID;

                Contact updatedContact;
                string name, phoneNumber, address, email;
                cin.ignore();
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new phone number: ";
                getline(cin, phoneNumber);
                cout << "Enter new address: ";
                getline(cin, address);
                cout << "Enter new email: ";
                getline(cin, email);

                updatedContact.setName(name);
                updatedContact.setPhoneNumber(phoneNumber);
                updatedContact.setAddress(address);
                updatedContact.setEmail(email);
                updatedContact.setIsFavorite(false);

                phonebook.editContact(contactID, updatedContact);
                break;
            }
            case 6: {
                int contactID;
                phonebook.listAllContacts();
                cout << "Enter contact ID to add to favorites: ";
                cin >> contactID;
                phonebook.addToFavorite(contactID);
                break;
            }
            case 7: {
                string sortCriteria;
                cout << "Enter sort criteria (name, phoneNumber, favorite): ";
                cin >> sortCriteria;
                vector<Contact> sortedContacts = phonebook.sortContacts(sortCriteria);
                cout << "=======================================\n";
                for (size_t i = 0; i < sortedContacts.size(); ++i) {
                    const auto& contact = sortedContacts[i];
                    cout << "ID: " << contact.getContactID() << "\n"
                         << "Name: " << contact.getName() << "\n"
                         << "Phone: " << contact.getPhoneNumber() << "\n"
                         << "Address: " << contact.getAddress() << "\n"
                         << "Email: " << contact.getEmail() << "\n"
                         << "Favorite: " << (contact.getIsFavorite() ? "Yes" : "No") << "\n"
                         << "=======================================\n";
                }
                break;
            }
            case 8:
                phonebook.writeToFile("storage.txt");
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 8);
}
