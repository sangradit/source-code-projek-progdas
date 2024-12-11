#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <vector>
#include <string>
#include "contact.h"

class Phonebook {
private:
    std::vector<Contact> contacts;
    int nextContactID = 1;

public:
    void viewAllContacts();
    void listAllContacts();
    int findContactIndexByID(int contactID);
    void removeContact(int contactID);
    void editContact(int contactID, Contact updatedContact);
    void addToFavorite(int contactID);
    void addContact(const Contact& contact);
    void viewContactByName(const std::string& searchName);
    std::vector<Contact> sortContacts(const std::string& criteria);
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename);
};

#endif
