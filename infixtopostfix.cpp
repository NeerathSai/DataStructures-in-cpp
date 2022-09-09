#include<iostream>
#include<stdio.h>
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

int precedence(char ch) 
{
if(ch == '^')
 return 3;
else if(ch == '/' || ch =='*')
 return 2;
else if(ch == '+' || ch == '-')
 return 1;
else
 return -1;
}


string infixToPostfix(string s) 
{
    Stack st;
string postfix_exp;

for(int i = 0; i < s.length(); i++) 
    {
 char ch = s[i];

 
 if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
 postfix_exp += ch;

 
 else if(ch == '(')
 st.push('(');

 
 else if(ch == ')') {
 while(st.peek() != '(')
 {
  postfix_exp += st.peek();
  st.pop();
 }
 st.pop();
 }

 
 else 
        {
 while(!st.isEmpty() && precedence(s[i]) <= precedence(st.peek())) 
            {
  postfix_exp += st.peek();
  st.pop();
 }
 st.push(ch);
 }
}


while(!st.isEmpty()) 
    {
 postfix_exp += st.peek();
 st.pop();
}

return postfix_exp;
}

int main() 
{
string infix_expression;
cout<<"enter an infix expression";
cin>>infix_expression;
cout<<"The postfix string is: "<<infixToPostfix(infix_expression);
return 0;
}
