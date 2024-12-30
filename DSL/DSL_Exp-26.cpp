/*
In any language program mostly syntax error occurs due to unbalancing delimiter such 
as (),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.
*/


#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 10

class StackExp {
    int top;
    char stk[SIZE];

public:
    StackExp() {
        top = -1;
    }

    void push(char x) {
        if (isfull()) {
            cout << "\nStack Overflow! Cannot push " << x << "\n";
        } else {
            stk[++top] = x;
        }
    }

    char pop() {
        if (isempty()) {
            cout << "\nStack Underflow! Attempt to pop from an empty stack.\n";
            return '\0';
        } else {
            return stk[top--];
        }
    }

    int isfull() {
        return (top == SIZE - 1);
    }

    int isempty() {
        return (top == -1);
    }
};

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main() {
    StackExp s1;
    char exp[20], ch;
    int i = 0;

    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
    cout << "\nEnter the expression to check whether it is well-formed: ";
    cin >> exp;

    while (exp[i] != '\0') {
        ch = exp[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            s1.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            char popped = s1.pop();
            if (!isMatchingPair(popped, ch)) {
                cout << "\nInvalid Expression: Mismatched parenthesis.\n";
                return 0;
            }
        }
        i++;
    }

    if (s1.isempty()) {
        cout << "\nExpression is well parenthesized.\n";
    } else {
        cout << "\nInvalid Expression: Unmatched opening parenthesis.\n";
    }

    return 0;
}
