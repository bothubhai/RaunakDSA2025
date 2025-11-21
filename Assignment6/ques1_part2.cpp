#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insert(int value, int after = -1) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }

    if (after == -1) { // Insert at end
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    } else { // Insert after a specific value
        Node* temp = head;
        while (temp != NULL && temp->data != after)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Value not found.\n";
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteNode(int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Value not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void search(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found.\n";
}

void display() {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int ch, val, after;
    while (true) {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Display\n0.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter value: "; cin >> val;
                cout << "Insert after which value (-1 for end)? "; cin >> after;
                insert(val, after);
                break;
            case 2:
                cout << "Enter value to delete: "; cin >> val;
                deleteNode(val);
                break;
            case 3:
                cout << "Enter value to search: "; cin >> val;
                search(val);
                break;
            case 4:
                display();
                break;
            case 0:
                return 0;
        }
    }
}
