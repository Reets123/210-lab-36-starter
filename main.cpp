// Lab 36: Records BST
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"

using namespace std;

void loadFromFile(StringBinaryTree &tree, const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file. Check filename." << endl;
        return;
    }

    string code;
    while (file >> code) {
        tree.insertNode(code);
    }
    file.close();
}

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Add a record" << endl;
    cout << "2. Delete a record" << endl;
    cout << "3. Search a record" << endl;
    cout << "4. Display records (In-Order)" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    StringBinaryTree tree;
    loadFromFile(tree, "codes.txt");

    int choice;
    string code;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter code to add: ";
                getline(cin, code);
                tree.insertNode(code);
                break;

            case 2:
                cout << "Enter code to delete: ";
                getline(cin, code);
                tree.remove(code);
                break;

            case 3:
                cout << "Enter code to search: ";
                getline(cin, code);
                if (tree.searchNode(code))
                    cout << "Code found." << endl;
                else
                    cout << "Code not found." << endl;
                break;

            case 4:
                cout << "Records (In-Order):" << endl;
                tree.displayInOrder();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}