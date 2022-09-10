#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX 20
 
class Stack {
    int top;
 
public:
    int a[MAX];
 
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
 
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}
 
int Stack::pop()
{
    if (top < 0) {
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()
{
    return (top < 0);
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPrefix(Stack s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((s.peek() != '(') && (!s.isEmpty())) {
                prefix += s.peek();
                s.pop();
            }

            if (s.peek() == '(') {
                s.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (s.isEmpty()) {
                s.push(infix[i]);
            }
            else {
                if (precedence(infix[i]) > precedence(s.peek())) {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.peek()))
                    && (infix[i] == '^')) {
                    while ((precedence(infix[i]) == precedence(s.peek()))
                        && (infix[i] == '^')) {
                        prefix += s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.peek())) {
                    s.push(infix[i]);
                }
                else {
                    while ((!s.isEmpty()) && (precedence(infix[i]) < precedence(s.peek()))) {
                        prefix += s.peek();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.isEmpty()) {
        prefix += s.peek();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{

    string infix, prefix;
    cout << "Enter a Infix Expression :" << endl;
    cin >> infix;
    Stack s;
    cout << "INFIX EXPRESSION: " << infix << endl;
    prefix = InfixToPrefix(s, infix);
    cout << endl
         << "PREFIX EXPRESSION: " << prefix;

    return 0;
}
