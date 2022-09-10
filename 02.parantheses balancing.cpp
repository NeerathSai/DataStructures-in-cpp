#include<stdio.h>
#include<string>
#include<stack>
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
    	
    	cin>>x;
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

bool ArePair(char opening, char closing){
	
	if(opening=='(' && closing==')'){
		return true;
	}
		else if(opening=='[' && closing==']'){
			return true;
		}
			else if(opening=='{' && closing=='}'){
				return true;
			}
				else{
					return false;
				} 
			
}

bool AreParanthesesBalanced(string exp){
	Stack Stack;
	int i;
	
	for(i=0;i<exp.length();i++){
		
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
			Stack.push(exp[i]);
		}
		else{
			if(Stack.isEmpty() || !ArePair(Stack.peek(),exp[i])){
				return false;
			}	
			else{
				Stack.pop();
			}	
			
		}
		
	}
	return Stack.isEmpty() ? true:false;
	
}
int main(){
	string expression;
	cout<<"enter an expression";
	cin>>expression;
	if(AreParanthesesBalanced(expression)){
		cout<<"expreesion is balanced";
	}
	else{
		cout<<"expression is not balanced";
	}
}
