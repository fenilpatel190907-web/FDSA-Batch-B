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
    Node* newNode = new Node(value);

    // Insert at first position
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position!!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head)
{
    Node* temp = head;

    cout << "Queue: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node* head = NULL;

    int choice, value, position;

    while (true)
    {
        cout << "\n1. Critical Patient (Front)";
        cout << "\n2. Routine Patient (End)";
        cout << "\n3. Priority Patient (Specific Position)";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 4)
            break;

        cout << "Enter patient token: ";
        cin >> value;

        if (choice == 1)
        {
            insertFront(head, value);
        }
        else if (choice == 2)
        {
            insertEnd(head, value);
        }
        else if (choice == 3)
        {
            cout << "Enter position: ";
            cin >> position;

            insertAtPosition(head, value, position);
        }
        else
        {
            cout << "Invalid choice!" << endl;
            continue;
        }

        display(head);
    }

    return 0;
}