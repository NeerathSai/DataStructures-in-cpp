#include<iostream>
using namespace std;
class Queue
{	
 	string arr[10];
    int rear, front,count,maxSize;
	public:
    Queue()
    {
       front = rear = 0;
       count=0;
	   maxSize=6;
    }
 	bool isEmpty(){
 		if(front == rear){
 			return true;
		 }
	 	return false;
	 }
	 void Enqueue(string n){
	 	if ((rear+1)%maxSize == front){
	 		cout<<"Queue is Full"<<endl;
		 }
	 	else{
	 		arr[rear]=n ;
	 		rear= (rear+1)%maxSize;
	 		count++;
	 		cout<<"String enqueued:"<<n<<endl;
		 }
	 }
	 void Dequeue(){
	 	if(isEmpty()){
	 		cout<<"queue is empty"<<endl;
		 }
		else{
			cout<<"String dequed"<<arr[count]<<endl;
			arr[front]="";
			front = (front+1)%maxSize;
			count--;
		}
	 }
	void display(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
		}
		else{
			cout<<"Queue elements are:"<<endl;
			for(int i=front;i!=rear;i++){
				cout<<arr[i]<<endl;
			}
		}
	}
};
int main()
{
Queue q;
 
	
int ch;
string val;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   do {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         q.Enqueue(val);
         break;

         case 2:
         q.Dequeue();
         break;

         case 3:
         q.display();
         break;

         case 4:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 4);
   return 0;
    
    return 0;
}
