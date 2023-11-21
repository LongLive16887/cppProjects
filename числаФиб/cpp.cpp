#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** head, int newData) {
    Node* newNode = new Node(); 
    newNode->data = newData;    
    newNode->next = NULL;   
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

bool isFibonacci(int n) {
    int a = 0, b = 1;
    while (b < n) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return (b == n);
}


int sumFib(Node* head) {
    cout << "Числа Фибоначчи в массиве: ";
    int sum = 0;
    Node* current = head;
    while (current->next != NULL) {
        if (isFibonacci(current->data)) {
            cout << current->data<< " ";
            sum += current->data;
            
        }
        current = current->next;
    }
    cout << endl;
    return sum;
}

void print(Node* s){
    Node* t = s;
    while(t != NULL){
        cout<<t->data<<" ";
        t = t->next;
    }
}


int main() {
    Node* head = NULL;
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int randomNumber = rand() % 10; 
        append(&head, randomNumber);
    }
    cout<<"my-list: "<<print(head);
    cout<<endl;
    int sum = sumFib(head);
    cout << "Сумма элементов: "<<sum<<endl;
    return 0; 
}