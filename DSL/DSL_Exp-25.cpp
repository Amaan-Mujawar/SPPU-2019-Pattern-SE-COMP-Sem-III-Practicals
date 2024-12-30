/*
A palindrome is a string of character that‘s the same forward and backward. Typically, 
punctuation, capitalization, and spaces are ignored. For example, ‖Poor Dan is in a droop‖ 
is a palindrome, as can be seen by examining the characters ―poor danisina droop‖ and 
observing that they are the same forward and backward. One way to check for a palindrome 
is to reverse the characters in the string and then compare with them the original- 
in a palindrome, the sequence will be identical. Write C++ program with functions- 
1. To check whether given string is palindrome or not that uses a stack to determine whether a string is a 
   palindrome. 
2. To remove spaces and punctuation in string, convert all the Characters to lowercase, and then call 
   above Palindrome checking function to check for a palindrome 
3. To print string in reverse order using stack. 
*/


#include <iostream>
#include <cstring>
#define MAX 50

using namespace std;

class STACK {
private:
    char a[MAX];
    int top;

public:
    STACK() {
        top = -1;
    }

    void push(char c) {
        if (top < MAX - 1) {
            a[++top] = c;
            cout << c << " is pushed onto the stack...\n";
        } else {
            cout << "Stack overflow! Cannot push more characters.\n";
        }
    }

    void reverse() {
        cout << "\nReversed string is: ";
        for (int i = top; i >= 0; i--) {
            cout << a[i];
        }
        cout << endl;
    }

    void convert(char str[]) {
        int j = 0, len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (isalpha(str[i])) {
                if (isupper(str[i])) {
                    str[j++] = tolower(str[i]);
                } else {
                    str[j++] = str[i];
                }
            }
        }
        str[j] = '\0';
        cout << "Converted string: " << str << endl;
    }

    void palindrome(char str[]) {
        char reversed[MAX];
        int i, j;

        for (i = top, j = 0; i >= 0; i--, j++) {
            reversed[j] = a[i];
        }
        reversed[j] = '\0';

        if (strcmp(str, reversed) == 0) {
            cout << "\nThe string is a palindrome.\n";
        } else {
            cout << "\nThe string is not a palindrome.\n";
        }
    }
};

int main() {
    STACK stack;
    char str[MAX];

    cout << "Enter a string to reverse and check if it is a palindrome: ";
    cin.getline(str, MAX);

    stack.convert(str);

    for (int i = 0; str[i] != '\0'; i++) {
        stack.push(str[i]);
    }

    stack.palindrome(str);

    stack.reverse();

    return 0;
}