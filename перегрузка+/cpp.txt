#include <iostream>
#include <string>

using namespace std;

class EnglishNumber {
private:
    int value;

public:
    EnglishNumber(int num) : value(num) {}

    // Перегрузка оператора сложения
    EnglishNumber operator+(const EnglishNumber& other) {
        int result = value + other.value;
        return EnglishNumber(result);
    }

    // Перегрузка оператора вывода в консоль
    friend ostream& operator<<(ostream& os, const EnglishNumber& num) {
        if (num.value < 1 || num.value > 100) {
            os << "unknown";
        } else {
            string englishNum = toEnglish(num.value);
            os << englishNum;
        }
        return os;
    }

    // Преобразование числа в английскую строку
    static string toEnglish(int num) {
        if (num < 20) {
            static const string numbers[] = {
                "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
            };
            return numbers[num];
        } else if (num < 100) {
            static const string tens[] = {
                "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
            };
            return tens[num / 10] + (num % 10 ? "-" + toEnglish(num % 10) : "");
        } else if (num == 100) {
            return "one hundred";
        }
        return "unknown";
    }
};

int main() {
    int num1, num2;
    
    cout << "Enter the first number (1-100): ";
    cin >> num1;
    
    cout << "Enter the second number (1-100): ";
    cin >> num2;

    EnglishNumber numObj1(num1);
    EnglishNumber numObj2(num2);

    EnglishNumber result = numObj1 + numObj2;
    cout << num1 << " + " << num2 << " = " << result << endl;

    return 0;
}
