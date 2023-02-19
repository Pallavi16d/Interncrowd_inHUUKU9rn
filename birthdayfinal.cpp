#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    string birthdate;
};

const int MAX_ENTRIES = 50;
Person persons[MAX_ENTRIES];
int numEntries = 0;

void addPerson() {
    if (numEntries < MAX_ENTRIES) {
        Person person;
        cout << "Enter name: ";
        cin >> person.name;
          cout << "Enter birthdate (MM/DD/YYYY): ";
        cin >> person.birthdate;
        persons[numEntries] = person;
        numEntries++;
        cout << "Person added successfully!" << endl;
    }
    else {
        cout << "Error: Maximum number of entries reached." << endl;
    }
}

void editBirthdate() {
    string name;
    cout << "Enter name: ";
    cin >> name;
    for (int i = 0; i < numEntries; i++) {
        if (persons[i].name == name) {
            cout << "Enter new birthdate: ";
            cin >> persons[i].birthdate;
            cout << "Birthdate updated successfully!" << endl;
            return;
        }
    }
    cout << "Error: Person not found." << endl;
}

void searchBirthdate() {
    string name;
    cout << "Enter name: ";
    cin >> name;
    for (int i = 0; i < numEntries; i++) {
        if (persons[i].name == name) {
            cout << "Birthdate: " << persons[i].birthdate << endl;
            return;
        }
    }
    cout << "Error: Person not found." << endl;
}

void listMonthlyBirthdays() {
    string month;
    cout << "Enter month: ";
    cin >> month;
    for (int i = 0; i < numEntries; i++) {
        if (persons[i].birthdate.substr(0, 2) == month) {
            cout << persons[i].name << endl;
        }
    }
}

void displayMenu() {
    cout << "1. Add person" << endl;
    cout << "2. Edit birthdate" << endl;
    cout << "3. Search birthdate" << endl;
    cout << "4. List monthly birthdays" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addPerson();
                break;
            case 2:
                editBirthdate();
                break;
            case 3:
                searchBirthdate();
                break;
            case 4:
                listMonthlyBirthdays();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
