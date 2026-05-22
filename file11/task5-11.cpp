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
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}
// Recursive helper function to find the lowest remaining value element
Node* findMinNode(Node* root) {
    if (root == nullptr || root->left == nullptr) {
        return root;
    }
    return findMinNode(root->left);
}
// Recursive Deletion Function
Node* deleteNodeRecursive(Node* root, int key) {
    // Base Case: Element path terminates as empty
    if (root == nullptr) {
        return root;
    }
    // Step 1: Search for target node down branch pathways
    if (key < root->data) {
        root->left = deleteNodeRecursive(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNodeRecursive(root->right, key);
    } 
    // Step 2: Node found! Handle deletion conditions
    else {
        // Condition A & B: Node has only 1 child or is a terminal leaf
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Condition C: Node has 2 complex structural children
        // Grab the inorder successor (the absolute minimum from right side)
        Node* temp = findMinNode(root->right);
       // Swap structural values
        root->data = temp->data;
        // Delete that successor leaf node out safely
        root->right = deleteNodeRecursive(root->right, temp->data);
    }
    return root;
}
int main() {
    Node* root = nullptr;
    // Standard starting sequence insertion values
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "Recursive BST Deletion"<<endl;
    cout << "Initial In-Order traversal configuration: ";
    inOrder(root);
    cout <<endl;
    int targetDeletion;
    cout << "Enter a value from the list above to delete: ";
    cin >> targetDeletion;
    // Perform operations
    root = deleteNodeRecursive(root, targetDeletion);
    cout << "\nValue " << targetDeletion << " processed for structural deletion.\n";
    cout << "Updated Verification In-Order: ";
    inOrder(root);
    cout <<endl;
    return 0;
}