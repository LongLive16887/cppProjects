#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
    private:
        Node* top;

    public:
        Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void removeEvenPosition() {
        Node* current = top;
        Node* prev = nullptr;
        int position = 0;

        while (current) {
            if (position % 2 == 1) { // Удаляем элементы с четной позицией (нумерация с 0)
                if (prev) {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                } else {
                    Node* temp = top;
                    top = top->next;
                    delete temp;
                    current = top;
                }
            } else {
                prev = current;
                current = current->next;
            }

            ++position;
        }
    }

    void print() const {
        Node* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Stack() {
        Node* current = top;
        Node* nextNode = nullptr;
        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    srand(time(NULL));
    Stack myStack;

    for(int n = 0; n < 10;n++){
        myStack.push(rand()%(100+1)-50); //-50 < x < 50
    }

    cout << "Original Stack: ";
    myStack.print();

    myStack.removeEvenPosition();

    cout << "Stack after removing even-positioned elements: ";
    myStack.print();

    return 0;
}
