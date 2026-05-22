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
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}
// Recursive function to find the minimum value (Leftmost element)
int findMinRecursive(Node* root) {
    // Assumption: The calling function verifies the tree isn't completely empty
    if (root->left == nullptr) {
        return root->data; // Deepest left node achieved
    }
    return findMinRecursive(root->left);
}
// Recursive function to find the maximum value (Rightmost element)
int findMaxRecursive(Node* root) {
    if (root->right == nullptr) {
        return root->data; // Deepest right node achieved
    }
    return findMaxRecursive(root->right);
}
int main() {
    Node* root = nullptr;
    // Tree creation
    root = insert(root, 100);
    insert(root, 70);
    insert(root, 150);
    insert(root, 40);
    insert(root, 90);
    insert(root, 120);
    insert(root, 200);
    cout << "Recursive Min & Max Finder"<<endl;
    if (root != nullptr) {
        std::cout << "Minimum value in the BST is: " << findMinRecursive(root) <<endl;
        std::cout << "Maximum value in the BST is: " << findMaxRecursive(root) <<endl;
    } else {
           cout << "The tree is empty"<<endl;
    }
    return 0;
}