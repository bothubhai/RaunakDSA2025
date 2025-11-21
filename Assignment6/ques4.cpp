#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};
Node* head = NULL;

void insert(char val) {
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

bool isPalindrome() {
    if (head == NULL) return true;

    Node* left = head;
    Node* right = head;
    while (right->next)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter characters: ";
    cin >> s;
    for (char c : s)
        insert(c);

    if (isPalindrome())
        cout << "Palindrome Linked List\n";
    else
        cout << "Not a Palindrome\n";

    return 0;
}
