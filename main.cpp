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
    

    return 0;
}