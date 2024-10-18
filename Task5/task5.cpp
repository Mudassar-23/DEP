#include <iostream>
#include <string>
using namespace std;

void intro();
void forest();
void cave();
void village();
void gameOver(const string& reason);
void win();

// ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {
    intro();  // Start the game with the introduction
    return 0;
}

void intro() {
    cout << YELLOW << "Welcome to the Text-Based Adventure Game!\n" << RESET;
    cout << "You wake up in a " << GREEN << "dark forest" << RESET << " with no memory of how you got there.\n";
    cout << "In front of you are three paths:\n";
    cout << "1. Follow the " << GREEN << "forest trail\n" << RESET;
    cout << "2. Enter a " << BLUE << "dark cave\n" << RESET;
    cout << "3. Walk towards a " << YELLOW << "distant village\n" << RESET;

    int choice;
    cout << "Enter your choice (1/2/3): ";
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << RED << "Invalid input. Please enter 1, 2, or 3: " << RESET;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    switch (choice) {
    case 1:
        forest();
        break;
    case 2:
        cave();
        break;
    case 3:
        village();
        break;
    }
}

void forest() {
    cout << "\nYou follow the forest trail and encounter a " << RED << "wild bear!\n" << RESET;
    cout << "What will you do?\n";
    cout << "1. " << RED << "Fight the bear\n" << RESET;
    cout << "2. " << GREEN << "Run away\n" << RESET;

    int choice;
    cout << "Enter your choice (1/2): ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << RED << "Invalid input. Please enter 1 or 2: " << RESET;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (choice == 1) {
        gameOver("The bear overpowers you. Game Over.");
    }
    else {
        cout << "You run back to where you started.\n";
        intro();
    }
}

void cave() {
    cout << "\nYou enter the " << BLUE << "dark cave" << RESET << " and find a " << YELLOW << "treasure chest!\n" << RESET;
    cout << "However, a " << RED << "sleeping dragon" << RESET << " lies nearby.\n";
    cout << "What will you do?\n";
    cout << "1. " << YELLOW << "Open the chest\n" << RESET;
    cout << "2. " << GREEN << "Sneak away quietly\n" << RESET;

    int choice;
    cout << "Enter your choice (1/2): ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << RED << "Invalid input. Please enter 1 or 2: " << RESET;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (choice == 1) {
        gameOver("The dragon wakes up and burns you to ashes. Game Over.");
    }
    else {
        cout << "You escape the cave safely and find yourself back at the start.\n";
        intro();
    }
}

void village() {
    cout << "\nYou arrive at the " << YELLOW << "village" << RESET << ", where the townsfolk welcome you.\n";
    cout << "A villager offers you " << GREEN << "food and shelter.\n" << RESET;
    cout << "What will you do?\n";
    cout << "1. " << GREEN << "Accept the offer\n" << RESET;
    cout << "2. " << RED << "Decline and leave the village\n" << RESET;

    int choice;
    cout << "Enter your choice (1/2): ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << RED << "Invalid input. Please enter 1 or 2: " << RESET;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (choice == 1) {
        win();
    }
    else {
        cout << "You leave the village and return to the starting point.\n";
        intro();
    }
}

void gameOver(const string& reason) {
    cout << RED << "\n" << reason << "\n" << RESET;
    cout << "Would you like to try again? (y/n): ";

    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        intro();
    }
    else {
        cout << "Thanks for playing! Goodbye.\n";
    }
}

void win() {
    cout << GREEN << "\nCongratulations! You found a safe place to rest and made new friends.\n" << RESET;
    cout << GREEN << "You win the game!\n" << RESET;
}
