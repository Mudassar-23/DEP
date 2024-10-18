#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;

public:
   
    Contact(string contactName, string contactPhone) {
        name = contactName;
        phoneNumber = contactPhone;
    }

   
    string getName() const {
        return name;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }
};

void showMenu() {
    cout << "\nContact Management System" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. View Contacts" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}


void addContact(vector<Contact>& contacts) {
    string name, phoneNumber;
    cout << "Enter contact name: ";
    getline(cin, name);
    cout << "Enter contact phone number: ";
    getline(cin, phoneNumber);

    Contact newContact(name, phoneNumber);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available!" << endl;
    }
    else {
        cout << "\nContact List:" << endl;
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". " << contacts[i].getName() << " - " << contacts[i].getPhoneNumber() << endl;
        }
    }
}

void deleteContact(vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to delete: ";
    getline(cin, name);

    bool found = false;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getName() == name) {
            contacts.erase(it);
            found = true;
            cout << "Contact deleted successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found!" << endl;
    }
}

int main() {
    vector<Contact> contacts;  
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            viewContacts(contacts);
            break;
        case 3:
            deleteContact(contacts);
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
