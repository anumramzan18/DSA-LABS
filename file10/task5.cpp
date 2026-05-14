#include <iostream>
using namespace std;
class SinglyLinkedList
{
private:
struct Node
    {
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
    };
Node* head;
public:
SinglyLinkedList()
    {
        head = NULL;
    }
    void print(Node* temp)
    {
        if (temp == NULL)
        {
            cout << endl;
            return;
        }

        cout << temp->data << " ";
        print(temp->next);
    }
    void display()
    {
        print(head);
    }
    void insertAtBeginning(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    Node* insertEndRec(Node* temp, int val)
    {
        if (temp == NULL)
            return new Node(val);

        temp->next = insertEndRec(temp->next, val);

        return temp;
    }
    void insertAtEnd(int val)
    {
        head = insertEndRec(head, val);
    }
    Node* insertPosRec(Node* temp, int val, int pos)
    {
        if (pos == 1)
        {
            Node* newNode = new Node(val);
            newNode->next = temp;
            return newNode;
        }
        if (temp == NULL)
            return NULL;

        temp->next = insertPosRec(temp->next, val, pos - 1);

        return temp;
    }
    void insertAtPosition(int val, int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position\n";
            return;
        }

        head = insertPosRec(head, val, pos);
    }
    Node* deleteValueRec(Node* temp, int val)
    {
        if (temp == NULL)
            return NULL;

        if (temp->data == val)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
            return temp;
        }

        temp->next = deleteValueRec(temp->next, val);

        return temp;
    }
 void deleteByValue(int val)
    {
        head = deleteValueRec(head, val);
    }
    Node* deletePosRec(Node* temp, int pos)
    {
        if (temp == NULL)
            return NULL;

        if (pos == 1)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
            return temp;
        }

        temp->next = deletePosRec(temp->next, pos - 1);

        return temp;
    }
    void deleteAtPosition(int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position\n";
            return;
        }

        head = deletePosRec(head, pos);
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
};
int main()
{
    SinglyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    cout << "After insert at beginning:\n";
    list.display();
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    cout << "After insert at end:\n";
    list.display();
    list.insertAtPosition(15, 3);
    cout << "After insert at position:\n";
    list.display();
    list.deleteByValue(20);
    cout << "After delete by value:\n";
    list.display();
    list.deleteAtPosition(2);
    cout << "After delete at position:\n";
    list.display();
    int pos = list.search(30);
    cout << "30 found at position: " << pos << endl;
    return 0;
}
