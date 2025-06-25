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

class Stack {
private:
    Node* top;

public:
    Stack(int size) {
        top = nullptr;
    }
    
    void isFull() {
        cout << "\n Stack is full !";
    }

    void push(string name) {
        
        Node* newNode = new Node(name, top);
        top = newNode;
        cout << name << " has been added onto the stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "\nStack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        top = top->nextptr;
        cout << "\nElement " << temp->name << " has been deleted";
        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "\nStack is empty." << endl;
        } else {
            cout << "\nTop element is \"" << top->name << "\"" << endl;
        }
    }

    void displayStack() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        
        Node* currNode = top;
        cout << "Stack (from top to bottom): ";
        while (currNode != nullptr) {
            if (currNode->nextptr == nullptr) {
                cout << currNode->name;
                return;
            }
            cout << currNode->name << " -> ";
            currNode = currNode->nextptr;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack stack(5);

    stack.push("Aniq");
    stack.push("Aliff");
    stack.push("Adam");
    stack.push("Safrul");
    stack.push("Muaz");
    stack.push("test");

    cout << "\nOriginal List:\n";
    stack.displayStack();
    
    cout << endl;
    stack.pop();
    stack.pop();
    
    cout << endl;
    cout << "\nAfter Deletion:\n";
    stack.displayStack();
    
    cout << endl;
    stack.peek();

    return 0;
}

