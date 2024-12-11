#include "contact.h"

using namespace std;

Contact::Contact() : contactID(0), isFavorite(false) {}

int Contact::getContactID() const {
    return contactID;
}

string Contact::getName() const {
    return name;
}

string Contact::getPhoneNumber() const {
    return phoneNumber;
}

string Contact::getAddress() const {
    return address;
}

string Contact::getEmail() const {
    return email;
}

bool Contact::getIsFavorite() const {
    return isFavorite;
}

void Contact::setName(const string& newName) {
    name = newName;
}

void Contact::setPhoneNumber(const string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Contact::setAddress(const string& newAddress) {
    address = newAddress;
}

void Contact::setEmail(const string& newEmail) {
    email = newEmail;
}

void Contact::setIsFavorite(bool favorite) {
    isFavorite = favorite;
}

void Contact::setContactID(int id) {
    contactID = id;
}
