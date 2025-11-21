#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
Node* head = NULL;

void insert(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int size() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    insert(10); insert(20); insert(30);
    cout << "Size of Doubly Linked List: " << size() << endl;
    return 0;
}
