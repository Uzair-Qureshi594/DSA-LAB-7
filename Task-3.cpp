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

    void deleteNode(int value) {
        if (!head) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        Node *temp = head, *prev = nullptr;

        if (temp->data == value) {
            if (temp->next == head) { 
                delete head;
                head = nullptr;
            } else { 
                while (temp->next != head) {
                    temp = temp->next; 
                }
                temp->next = head->next; 
                delete head; 
                head = temp->next; 
            }
            return;
        }

        prev = head;
        temp = head->next;
        while (temp != head) {
            if (temp->data == value) {
                prev->next = temp->next; 
                delete temp; 
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Node with value " << value << " not found." << endl;
    }

    void printList() const {
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
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(5);

    cout << "Circular Linked List: ";
    cll.printList();

    cll.deleteNode(5);
    cout << "After deleting 5: ";
    cll.printList();

    cll.deleteNode(30);
    cout << "After deleting 30: ";
    cll.printList();

    cll.deleteNode(40);
    cout << "After deleting 40: ";
    cll.printList();

    cll.deleteNode(10);
    cout << "After deleting 10: ";
    cll.printList();

    cll.deleteNode(20); 

    return 0;
}
