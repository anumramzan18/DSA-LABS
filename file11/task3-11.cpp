#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//function to handle setup insertion
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Recursive function to search for a value in the BST
bool searchRecursive(Node* root, int key) {
    // Base Case 1: Tree is empty or value isn't found
    if (root == nullptr) {
        return false;
    }
    // Base Case 2: Value matches the current node
    if (root->data == key) {
        return true;
    }

    // Value is smaller -> search left subtree
    if (key < root->data) {
        return searchRecursive(root->left, key);
    }
    
    // Value is larger -> search right subtree
    return searchRecursive(root->right, key);
}
int main() {
    Node* root = nullptr;
    
    // Populating the tree
    root = insert(root, 45);
    insert(root, 25);
    insert(root, 65);
    insert(root, 15);
    insert(root, 35);
    cout << "Recursive Search in BST"<<endl;
    int searchVal;
    cout << "Enter an integer value to search for: ";
    cin >> searchVal;

    // Execute search and return matching confirmation messages
    if (searchRecursive(root, searchVal)) {
       cout << "Message: Success! Value " << searchVal << " was FOUND in the BST"<<endl;
    } else {
       cout << "Message: Sorry, Value " << searchVal << " does NOT exist in the BST"<<endl;
    }
    return 0;
}