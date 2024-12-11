#include "phonebook.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void Phonebook::viewAllContacts() {
    if (contacts.empty()) {
        cout << "No contacts in the phonebook." << "\n";
        return;
    }
    cout << "Contact List:\n";
    cout << "=======================================\n";
    for (const auto& contact : contacts) {
        cout << "ID: " << contact.getContactID() << "\n"
             << "Name: " << contact.getName() << "\n"
             << "Phone: " << contact.getPhoneNumber() << "\n"
             << "Address: " << contact.getAddress() << "\n"
             << "Email: " << contact.getEmail() << "\n"
             << "Favorite: " << (contact.getIsFavorite() ? "Yes" : "No") << "\n"
             << "=======================================\n";
    }
}

void Phonebook::listAllContacts() {
    if (contacts.empty()) {
        cout << "No contacts in the phonebook." << "\n";
        return;
    }
    cout << "Contact List:\n";
    for (const auto& contact : contacts) {
        cout << "ID: " << contact.getContactID()
             << ", " << contact.getName()
             << ", " << contact.getPhoneNumber()
             << ", " << contact.getAddress()
             << ", " << contact.getEmail()
             << ", Favorite: " << (contact.getIsFavorite() ? "Yes" : "No") << "\n";
    }
}

int Phonebook::findContactIndexByID(int contactID) {
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getContactID() == contactID) {
            return i;
        }
    }
    return -1;
}

void Phonebook::removeContact(int contactID) {
    int index = findContactIndexByID(contactID);
    if (index != -1) {
        contacts.erase(contacts.begin() + index);
        cout << "Contact removed successfully." << "\n";
    } else {
        cout << "Contact with ID " << contactID << " not found.\n";
    }
}

void Phonebook::editContact(int contactID, Contact updatedContact) {
    int index = findContactIndexByID(contactID);
    if (index != -1) {
        updatedContact.setContactID(contacts[index].getContactID());
        contacts[index] = updatedContact;
        cout << "Contact updated successfully.\n";
    } else {
        cout << "Contact with ID " << contactID << " not found.\n";
    }
}

void Phonebook::addToFavorite(int contactID) {
    int index = findContactIndexByID(contactID);
    if (index != -1) {
        contacts[index].setIsFavorite(true);
        cout << "Contact added to favorites.\n";
    } else {
        cout << "Contact with ID " << contactID << " not found.\n";
    }
}

void Phonebook::addContact(const Contact& contact) {
    Contact newContact = contact;
    newContact.setContactID(nextContactID++);
    contacts.push_back(newContact);
    cout << "Contact added successfully with ID " << newContact.getContactID() << "\n";
}

void Phonebook::viewContactByName(const string& searchName) {
    bool found = false;
    cout << "=======================================\n";
    for (const auto& contact : contacts) {
        if (contact.getName().find(searchName) != string::npos) {
            cout << "ID: " << contact.getContactID() << "\n"
                      << "Name: " << contact.getName() << "\n"
                      << "Phone: " << contact.getPhoneNumber() << "\n"
                      << "Address: " << contact.getAddress() << "\n"
                      << "Email: " << contact.getEmail() << "\n"
                      << "Favorite: " << (contact.getIsFavorite() ? "Yes" : "No") << "\n"
                      << "=======================================\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No contacts found with the name \"" << searchName << "\"." << "\n";
    }
}

vector<Contact> Phonebook::sortContacts(const string& criteria) {
    vector<Contact> sortedContacts = contacts;
    if (criteria == "name") {
        sort(sortedContacts.begin(), sortedContacts.end(), [](const Contact& a, const Contact& b) {
            return a.getName() < b.getName();
        });
    } else if (criteria == "phoneNumber") {
        sort(sortedContacts.begin(), sortedContacts.end(), [](const Contact& a, const Contact& b) {
            return a.getPhoneNumber() < b.getPhoneNumber();
        });
    } else if (criteria == "favorite") {
        sort(sortedContacts.begin(), sortedContacts.end(), [](const Contact& a, const Contact& b) {
            return a.getIsFavorite() && !b.getIsFavorite();
        });
    }
    return sortedContacts;
}

void Phonebook::readFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        contacts.clear();
        nextContactID = 1;
        string line;
        while (getline(file, line)) {
            Contact contact;
            contact.setContactID(nextContactID++);
            size_t pos = line.find('|');
            contact.setName(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
            contact.setPhoneNumber(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
            contact.setAddress(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
            contact.setEmail(line.substr(0, pos));
            contact.setIsFavorite(line.substr(pos + 1) == "true");
            contacts.push_back(contact);
        }
        file.close();
        cout << "Phonebook loaded from file.\n";
    } else {
        cout << "Unable to open the file.\n";
    }
}

void Phonebook::writeToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.getName() << "|"
                 << contact.getPhoneNumber() << "|"
                 << contact.getAddress() << "|"
                 << contact.getEmail() << "|"
                 << (contact.getIsFavorite() ? "true" : "false") << "\n";
        }
        file.close();
        cout << "Phonebook saved to file." << "\n";
    } else {
        cout << "Unable to open the file." << "\n";
    }
}
