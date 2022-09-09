#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 5
class Stack {
    int top;
 
public:

    int a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
 
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow"<<endl;
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
        cout << "Stack Underflow";
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
        cout << "Stack is Empty";
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

int evalPrefix(string exp)
{
    
    Stack stack;
 
    
    for (int i=exp.length()-1;i>=0;--i )
    {
        
        if (exp[i] >= '0' && exp[i] <= '9') {
            stack.push(exp[i] - '0');
        }
        
        else {
            
            int x = stack.peek();
            stack.pop();
 
            int y = stack.peek();
            stack.pop();
 
            
            if (exp[i] == '+') {
                stack.push(x + y);
            }
            else if (exp[i] == '-') {
                stack.push(x - y);
            }
            else if (exp[i] == '*') {
                stack.push(x * y);
            }
            else if (exp[i] == '/') {
                stack.push(x / y);
            }
        }
    }
 
    
    return stack.peek();
}
 
int main()
{
    string exp;
    cout<<"enter an expression:";
    cin>>exp;
 
    cout << evalPrefix(exp);
 
    return 0;
}
