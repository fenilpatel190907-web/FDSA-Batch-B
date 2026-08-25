#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertFront(Node*& head, int value)
{
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(Node*& head, int value, int position)
{
    if (position == 1)
    {
        insertFront(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(Node*& head, int value)
{
    if (head == NULL)
    {
        cout << "Queue is empty!!" << endl;
        return;
    }

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Patient " << value << " removed." << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Patient " << value << " not found!" << endl;
        return;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;

    cout << "Patient " << value << " removed." << endl;
}

void displayForward(Node* head)
{
    cout << "Front to Back: ";

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void displayReverse(Node* head)
{
    if (head == NULL)
        return;

    displayReverse(head->next);

    cout << head->data << " ";
}

int main()
{
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original Queue:" << endl;
    displayForward(head);

    cout << "\nDeleting patient 20:" << endl;
    deleteByValue(head, 20);
    displayForward(head);

    cout << "\nForward Traversal:" << endl;
    displayForward(head);

    cout << "\nReverse Printing (Last to First): ";
    displayReverse(head);
    cout << endl;

    return 0;
}