
#include <iostream>
using namespace std;
class DoublyLinkedList
{
private:
struct Node
    {
        int data;
        Node* next;
        Node* prev;

        Node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head;
public:

    DoublyLinkedList()
    {
        head = NULL;
    }
    Node* insertEndRec(Node* temp, int val)
    {
        if (temp == NULL)
            return new Node(val);

        if (temp->next == NULL)
        {
            Node* newNode = new Node(val);
            temp->next = newNode;
            newNode->prev = temp;
            return temp;
        }

        temp->next = insertEndRec(temp->next, val);

        return temp;
    }
    void insertAtEnd(int val)
    {
        head = insertEndRec(head, val);
    }
    void printForward(Node* temp)
    {
        if (temp == NULL)
        {
            cout << endl;
            return;
        }

        cout << temp->data << " ";
        printForward(temp->next);
    }

    void displayForward()
    {
        printForward(head);
    }
    void printReverse(Node* temp)
    {
        if (temp == NULL)
            return;

        printReverse(temp->next);

        cout << temp->data << " ";
    }

    void displayReverse()
    {
        printReverse(head);
        cout << endl;
    }
    int searchRec(Node* temp, int val, int pos)
    {
        if (temp == NULL)
            return -1;

        if (temp->data == val)
            return pos;

        return searchRec(temp->next, val, pos + 1);
    }

    int search(int val)
    {
        return searchRec(head, val, 1);
    }
    Node* getTail(Node* temp)
    {
        if (temp == NULL || temp->next == NULL)
            return temp;

        return getTail(temp->next);
    }
    bool palindromeRec(Node* left, Node* right)
    {
        if (left == NULL || right == NULL)
            return true;

        if (left == right || left->prev == right)
            return true;

        if (left->data != right->data)
            return false;

        return palindromeRec(left->next, right->prev);
    }
    bool isPalindrome()
    {
        Node* tail = getTail(head);

        return palindromeRec(head, tail);
    }
};
int main()
{
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    cout << "Forward: ";
    list.displayForward();
    cout << "Reverse: ";
    list.displayReverse();
    if (list.isPalindrome())
        cout << "List is Palindrome";
    else
        cout << "List is NOT Palindrome";
    return 0;
}