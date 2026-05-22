#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
// Constructor to easily initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
// Recursive Pre-order Traversal: Root -> Left -> Right
void preOrder(Node* root) {
    if (root == nullptr) return;
    
    std::cout << root->data << " "; // Visit Root
    preOrder(root->left);           // Traverse Left Subtree
    preOrder(root->right);          // Traverse Right Subtree
}
// Recursive In-order Traversal: Left -> Root -> Right
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);            // Traverse Left Subtree
    std::cout << root->data << " "; // Visit Root
    inOrder(root->right);           // Traverse Right Subtree
}
// Recursive Post-order Traversal: Left -> Right -> Root
void postOrder(Node* root) {
    if (root == nullptr) 
    return;
    postOrder(root->left);          // Traverse Left Subtree
    postOrder(root->right);         // Traverse Right Subtree
    std::cout << root->data << " "; // Visit Root
}
int main() {
    // Manually constructing a simple binary tree with 5 nodes
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    cout << "Binary Tree Traversals" <<endl;
    cout << "Pre-order Traversal:  ";
    preOrder(root);
    cout <<endl;
    cout << "In-order Traversal:   ";
    inOrder(root);
    cout <<endl;
    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;
    return 0;
}