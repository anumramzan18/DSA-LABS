#include <iostream>
using name spaces std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {   //// Constructor for quick initialization
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
// Recursive function to insert an integer into the BST
Node* insert(Node* root, int val) {
    // If the position is empty, create a new node here
    if (root == nullptr) {
        return new Node(val);
    }
    // Recur down the tree based on the value property
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    // Return the unchanged node pointer
    return root;
}
// Recursive In-Order Traversal (Left -> Root -> Right)
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);            // Visit left subtree
    cout << root->data << " "; // Print current node
    inOrder(root->right);           // Visit right subtree
}
int main() {
    Node* root = nullptr;
    // Insert array items into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "BST Insertion and In-Order Traversal "<<endl;;
    cout << "In-Order Traversal elements: ";
    inOrder(root);
    cout <<endl;
    return 0;
}