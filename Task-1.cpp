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

    void insertNode(int value) {
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

    cll.insertNode(10);
    cll.insertNode(20);
    cll.insertNode(30);
    cll.insertNode(40);

    cout << "Circular Linked List: ";
    cll.printList();

    return 0;
}
