#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Teacher {
    string name;
    string school;
    int experience;
    int grade;
};

void insertionSort(vector<Teacher>& teachers, int& comparisons, int& swaps) {
    int n = teachers.size();
    for (int i = 1; i < n; i++) {
        Teacher key = teachers[i];
        int j = i - 1;

        while (j >= 0 && teachers[j].grade > key.grade) {
            comparisons++;
            teachers[j + 1] = teachers[j];
            swaps++;
            j--;
        }
        comparisons++;
        teachers[j + 1] = key;
        swaps++;
    }
}

void selectionSort(vector<Teacher>& teachers, int& comparisons, int& swaps) {
    int n = teachers.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (teachers[j].grade < teachers[min_index].grade) {
                min_index = j;
            }
        }
        swaps++;
        swap(teachers[i], teachers[min_index]);
    }
}

void bubbleSort(vector<Teacher>& teachers, int& comparisons, int& swaps) {
    int n = teachers.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (teachers[j].grade > teachers[j + 1].grade) {
                swaps++;
                swap(teachers[j], teachers[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void printTeachers(const vector<Teacher>& teachers) {
    for (const Teacher& teacher : teachers) {
        cout << "Name: " << teacher.name << ", School: " << teacher.school << ", Experience: " << teacher.experience << ", Grade: " << teacher.grade << endl;
    }
}

int main() {
    vector<Teacher> teachers;
    ifstream inputFile("baza.txt");

    if (!inputFile) {
        cerr << "error in load file." << endl;
        return 1;
    }

    while (true) {
        Teacher teacher;
        inputFile >> teacher.name;
        inputFile >> teacher.school;
        inputFile >> teacher.experience;
        inputFile >> teacher.grade;

        if (inputFile.eof()) {
            break;
        }

        teachers.push_back(teacher);
    }

    inputFile.close();

    vector<Teacher> teachersCopy1 = teachers;
    vector<Teacher> teachersCopy2 = teachers;
    vector<Teacher> teachersCopy3 = teachers;

    int comparisons1 = 0, swaps1 = 0;
    int comparisons2 = 0, swaps2 = 0;
    int comparisons3 = 0, swaps3 = 0;

    insertionSort(teachersCopy1, comparisons1, swaps1);
    selectionSort(teachersCopy2, comparisons2, swaps2);
    bubbleSort(teachersCopy3, comparisons3, swaps3);

    cout << "Insertion Sort Grade:" << endl;
    cout << "Comparisons: " << comparisons1 << endl;
    cout << "Swaps: " << swaps1 << endl;
    cout << "Sorted Array:" << endl;
    printTeachers(teachersCopy1);

    cout << "\nSelection Sort Grade:" << endl;
    cout << "Comparisons: " << comparisons2 << endl;
    cout << "Swaps: " << swaps2 << endl;
    cout << "Sorted Array:" << endl;
    printTeachers(teachersCopy2);

    cout << "\nBubble Sort Grade:" << endl;
    cout << "Comparisons: " << comparisons3 << endl;
    cout << "Swaps: " << swaps3 << endl;
    cout << "Sorted Array:" << endl;
    printTeachers(teachersCopy3);

    return 0;
}
