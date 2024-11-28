// Lab 36: Records BST
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"

using namespace std;

void loadFromFile(IntBinaryTree &tree, const string &filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file. Check files name" << endl;
        return;
    }

     string code;
    while (file >> code) {
        tree.insertNode(code);
    }
    file.close();
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Add a record" << endl;
    cout << "2. Delete a record" << endl;
    cout << "3. Search a record" << endl;
    cout << "4. Display records (In-Order)" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    IntBinaryTree tree;

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
                tree.insertN
    

    return 0;
}