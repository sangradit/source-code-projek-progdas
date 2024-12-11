#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    int contactID;
    std::string name;
    std::string phoneNumber;
    std::string address;
    std::string email;
    bool isFavorite;

public:
    Contact();
    int getContactID() const;
    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;
    std::string getEmail() const;
    bool getIsFavorite() const;
    void setName(const std::string& newName);
    void setPhoneNumber(const std::string& newPhoneNumber);
    void setAddress(const std::string& newAddress);
    void setEmail(const std::string& newEmail);
    void setIsFavorite(bool favorite);
    void setContactID(int id);
};

#endif
