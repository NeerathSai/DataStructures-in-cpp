#include <iostream>
using namespace std;


struct Node { 
  int data; 
  Node *next; 
};

class LinkedList
{
    
    Node* head;

  public:
    
    LinkedList()
    {
      head = NULL;
    }

    
    void insert(int val)
    {
      
      Node* new_node = new Node;
      new_node->data = val;
      new_node->next = NULL;

      
      if (head == NULL)
        head = new_node;
      
      else
      {
        new_node->next = head;
        head = new_node;
      }
    }

    
    Node* insertAtBegin(Node* head, int x)
{

    // creation of a new node of linked list.
    Node* newNode = new Node(x)

    // checking if the linked list is empty.
    if(head == NULL)         
    return newNode;

    // insertion of the node at the beginning.
    else     
    {
        newNode->next = head;
        return newNode;
    }
}

	Node* insertAtEnd(Node* head, int x)
{

    // If the list is empty.
    if( head == NULL )     
    {
        Node* newNode = new Node(x);
        head = newNode;
        return head;
    }
    Node* temp = head;

    // Traversing the list till the last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* newNode = new Node(x);
    temp->next = newNode;
    return head;
}

	void insertAfterNode(Node* givenNode, int x)
{
    Node* newNode = new Node(x);
   
    newNode->next = givenNode->next;
    givenNode->next = newNode;
}

    
    void remove(int val)
    {
      
      if (head->data == val)
      {
        delete head;
        head = head->next;
        return;
      }

      
      if (head->next == NULL)
      {
        
        if (head->data == val)
        {
          delete head;
          head = NULL;
          return;
        }
        
        cout << "Value not found!" << endl;
        return;
      }

     
      Node* temp = head;
      while(temp->next!= NULL)
      {
        
        if (temp->next->data == val)
        {
          Node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }

      
      cout << "Value not found" << endl;
    }

    void display()
    {
      Node* temp = head;
      while(temp != NULL)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main(){
	
	int choice;
	while(1){
		
		cout<<"1)insert at beginning:"<<endl;
		cout<<"2)insert at end:"<<endl;
		cout<<"3)insert at position:"<<endl;
		cout<<"4)delete a given element:"<<endl;
		cout<<"5)print list:"<<endl;
		
		switch (choice) {
        case 1:
            insertAtFront();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            remove();
            break;
        case 5:
            display();
            break;
		
	}
}
