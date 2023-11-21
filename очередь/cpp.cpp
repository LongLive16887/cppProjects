#include <iostream>
#include <stack>
using namespace std;

void removeEvenPositionElements(stack<int>& myStack) {
    stack<int> tempStack;
    size_t position = 1;
    while (!myStack.empty()) {
        if (position % 2 != 0) {
            tempStack.push(myStack.top());
        }
        myStack.pop();
        position++;
    }

    while (!tempStack.empty()) {
        myStack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> myStack;
    for (int i = 1; i <= 10; ++i) {
        myStack.push(i);
    }
    cout << "Исходный стек: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << "\n";
    for (int i = 1; i <= 10; ++i) {
        myStack.push(i);
    }
    removeEvenPositionElements(myStack);
    cout << "Стек после удаления четных по позиции элементов: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    return 0;
}
