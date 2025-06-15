#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteByValue(string name) {
        Node* temp = head;

        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node \"" << name << "\" not found.\n";
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail != nullptr) tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Deleted node \"" << name << "\".\n";
    }

    void displayForward() {
        Node* curr = head;
        cout << "Forward: ";
        while (curr != nullptr) {
            cout << curr->name << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        Node* curr = tail;
        cout << "Backward: ";
        while (curr != nullptr) {
            cout << curr->name << " <-> ";
            curr = curr->prev;
        }
        cout << "NULL" << endl;
    }

    // Destructor to clean up
    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.addNode("Aniq");
    list.addNode("Aliff");
    list.addNode("Adam");

    list.displayForward();
    list.displayBackward();

    list.deleteByValue("Aliff");

    cout << "\nAfter deletion:\n";
    list.displayForward();
    list.displayBackward();

    return 0;
}
