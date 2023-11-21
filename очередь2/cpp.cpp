#include <iostream>
#include <list>
using namespace std;
void replaceElements(list<int>& myList, int oldValue, int newValue) {
    for (auto& element : myList) {
        if (element == oldValue) {
            element = newValue;
        }
    }
}
int main() {
    list<int> myList = {1, 2, 3, 6,6,6,4, 2, 5, 2, 6,6,6,6};
    cout << "Исходный список: ";
    for (const auto& element : myList) {
        cout << element << " ";
    }
    cout << "\n";
    replaceElements(myList, 6, 1);
    cout << "Список после замены всех вхождений 2 на 8: ";
    for (const auto& element : myList) {
        cout << element << " ";
    }
    return 0;
}
