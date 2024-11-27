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
    file.

int main() {
    

    return 0;
}