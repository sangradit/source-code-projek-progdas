#include "phonebook.h"
#include "user_interface.h"

int main() {
    Phonebook phonebook;
    phonebook.readFromFile("storage.txt");
    UserInterface ui(phonebook);
    ui.printHeader();
    ui.mainMenu();

    return 0;
}
