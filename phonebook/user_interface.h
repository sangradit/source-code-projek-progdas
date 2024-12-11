#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "phonebook.h"

class UserInterface {
private:
    Phonebook& phonebook;

public:
    UserInterface(Phonebook& pb);
    void printHeader();
    void mainMenu();
};

#endif
