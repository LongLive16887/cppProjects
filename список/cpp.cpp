#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void replaceElements(Node*& head, int old_value, int new_value) {
    Node* current = head;

    while (current) {
        if (current->data == old_value) {
            current->data = new_value;
        }
        current = current->next;
    }
}


void append(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(const Node* head) {
    const Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* myList = new Node(1);
    srand(time(NULL));
    for(int n = 0; n < 10;n++){
        append(myList,rand()%(7)+1); //1 < x < 7
    }
    cout << "Original List: ";
    printList(myList);
    replaceElements(myList,1,2);
    printList(myList);
    // Освобождаем память
    deleteList(myList);

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void replaceElements(Node*& head, int old_value, int new_value) {
    Node* current = head;

    while (current) {
        if (current->data == old_value) {
            current->data = new_value;
        }
        current = current->next;
    }
}


void append(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(const Node* head) {
    const Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* myList = new Node(1);
    srand(time(NULL));
    for(int n = 0; n < 10;n++){
        append(myList,rand()%(7)+1); //1 < x < 7
    }
    cout << "Original List: ";
    printList(myList);
    replaceElements(myList,1,2);
    printList(myList);
    // Освобождаем память
    deleteList(myList);

    return 0;
}
