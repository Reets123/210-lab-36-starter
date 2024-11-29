// Lab 36: Records BST
// COMSC-210 - Ibrahim Alatig 

#ifndef STRINGBINARYTREE_H
#define STRINGBINARYTREE_H

#include <string>
using namespace std;

// The StringBinaryTree class manages a binary tree of strings.
class StringBinaryTree {
private:
   // TreeNode is a private structure for StringBinaryTree nodes.
   struct TreeNode {
      string value;         // The value in the node
      TreeNode *left;      // Pointer to left child node
      TreeNode *right;     // Pointer to right child node
   };

   TreeNode *root;      

   // Private member functions for internal operations.
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(const string&, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;

public:
   StringBinaryTree()     { root = nullptr; }
   ~StringBinaryTree()    { destroySubTree(root); }

   void insertNode(const string&);
   bool searchNode(const string&);
   void remove(const string&);

   void displayInOrder() const     {  displayInOrder(root); }
};

#endif // STRINGBINARYTREE_H