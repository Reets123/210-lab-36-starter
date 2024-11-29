// Lab 36: Records BST
// COMSC-210 - Ibrahim Alatig 

// Implementation file for the IntBinaryTree class
#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"

using namespace std;

// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by 
// the TreeNode pointer. This function is called recursively.
void StringBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

// insertNode creates a new node to hold num as its value,
// and passes it to the insert function.                  
void StringBinaryTree::insertNode(const string &str) {
    TreeNode *newNode = new TreeNode; // Pointer to a new node.
    newNode->value = str;
    newNode->left = newNode->right = nullptr;       
   
   // Insert the node.
   insert(root, newNode);
}

// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.                
void StringBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
      destroySubTree(nodePtr->left);
      destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
// searchNode determines if a value is present in  
// the tree. If so, the function returns true.     
// Otherwise, it returns false.                    
bool StringBinaryTree::searchNode(const string &str) {
   TreeNode *nodePtr = root;
   while (nodePtr)    {
      if (nodePtr->value == str)
         return true;
      else if (str < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

// remove calls deleteNode to delete the      
// node whose value member is the same as num.
void StringBinaryTree::remove(const string &str) {
   deleteNode(str, root);
}

// deleteNode deletes the node whose value 
// member is the same as num.              
void StringBinaryTree::deleteNode(const string& str, TreeNode *&nodePtr) {
   if (str < nodePtr->value)
      deleteNode(str, nodePtr->left);
   else if (str > nodePtr->value)
      deleteNode(str, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


// makeDeletion takes a reference to a pointer to the node 
// that is to be deleted. The node is removed and the      
// branches of the tree below the node are reattached.     
void StringBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (!nodePtr)
      cout << "Cannot delete empty node.\n";
   else if (!nodePtr->right) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   } else if (!nodePtr->left) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

// The displayInOrder member function displays the values       
// in the subtree pointed to by nodePtr, via inorder traversal. 
void StringBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}