#include<stdio.h>
#include<iostream>
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

bool isPalindrome(string s)
{
	Stack st;
    int length = s.size();
 
    
 
    // Finding the mid
    int i, mid = length / 2;
 
    for (i = 0; i < mid; i++) {
        st.push(s[i]);
    }
 
    // Checking if the length of the string
    // is odd, if odd then neglect the
    // middle character
    if (length % 2 != 0) {
        i++;
    }
   
    char ele;
    // While not the end of the string
    while (s[i] != '\0')
    {
         ele = st.peek();
         st.pop();
 
    // If the characters differ then the
    // given string is not a palindrome
    if (ele != s[i])
        return false;
        i++;
    }
 
return true;
}
 
// Driver code
int main()
{
    string s;
    cout<<"enter a string: ";
    cin>>s;
 
    if (isPalindrome(s)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
 
    return 0;
} 
