#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert(int value, int after = -1) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    if (after == -1) { 
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    } else { 
        Node* temp = head;
        do {
            if (temp->data == after) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Value not found.\n";
    }
}

void deleteNode(int key) {
    if (head == NULL) return;

    Node* curr = head;
    Node* prev = NULL;

    if (head->data == key) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    do {
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    cout << "Value not found.\n";
}

void search(int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            cout << "Found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Not found.\n";
}

void display() {
    if (head == NULL) {
        cout << "List empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
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
