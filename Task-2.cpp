#include <iostream>
using namespace std;

class Node {
public:
    int data;  
    Node* next; 

    Node(int value) : data(value), next(nullptr) {} 
};

class CircularLinkedList {
private:
    Node* head; 

public:
    CircularLinkedList() : head(nullptr) {} 

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next; 
            }
            temp->next = newNode; 
            newNode->next = head; 
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next; 
            }
            temp->next = newNode; 
            newNode->next = head; 
            head = newNode; 
        }
    }

    void printList() {
        if (!head) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll; 

    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);

    cout << "Circular Linked List after inserting at the end: ";
    cll.printList();

    cll.insertAtBeginning(10);
    cll.insertAtBeginning(5);

    cout << "Circular Linked List after inserting at the beginning: ";
    cll.printList();

    return 0;
}
