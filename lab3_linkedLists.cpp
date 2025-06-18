/*
id: 24006779
name: Aniq Haikal
contact: 0163906960
email: aniqhaikalsaharuddin@gmail.com
*/

#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* nextptr;

    Node(string name, Node* nextptr = nullptr) {
        this->name = name;
        this->nextptr = nextptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->nextptr = newNode;
            tail = newNode;
        }
    }

    void deleteByValue(string name) {
        if (head == nullptr) return;

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->nextptr;
        }

        if (temp == nullptr) {
            cout << "Node with name \"" << name << "\" not found.\n";
            return;
        }

        if (temp == head) {
            head = head->nextptr;
        } else {
            prev->nextptr = temp->nextptr;
        }

        if (temp == tail) {
            tail = prev;
        }

        delete temp;
        cout << "Node with name \"" << name << "\" deleted.\n";
    }

    void displayList() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " -> ";
            currNode = currNode->nextptr;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory 

    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->nextptr;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    LinkedList list;

    list.addNode("Aniq");
    list.addNode("Aliff");
    list.addNode("Adam");

    cout << "Original List:\n";
    list.displayList();

    list.deleteByValue("Aliff");

    cout << "\nAfter Deletion:\n";
    list.displayList();

    return 0;
}
