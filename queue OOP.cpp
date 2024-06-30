#include<iostream>
using namespace std;

const int max_size = 5;

class Queue {
private:
    int q[max_size], front, rear;


public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        	if(front==-1 && rear==-1)
        	{
			return 1;
	        }
	else{
		return 0;
    	}
    }

    bool isFull() {
        	if(rear==max_size-1)
        	{
			return 1;
	        }
	else{
		return 0;
    	}
    }

    void enqueue(int val) {
       	if(isFull()==true){
		cout<<"Queue is full!"<<endl;
		return;
	}
	if(isEmpty()==true){
		front=0;
		rear=0;
		q[rear]=val;
		cout<<val<<" enqued!"<<endl;
	}
	else{
		rear++;
		q[rear]=val;
		cout<<val<<" enqued again!"<<endl;

	}
}

    void dequeue() {
        	if(isEmpty()==true){
		cout<<"dequeue failed!"<<endl;
	}
	else if(front==rear){

		front=-1;
		rear=-1;
	}
	else{
		front++;
	    }
    }
    void display() {
       	if(isEmpty()==true){
		cout<<"Nothing to show!"<<endl;
	}
	else{
		cout<<"the elements are: ";
		for(int i=front;i<=rear;i++){
			cout<<q[i]<<" ";
		}
		cout<<endl;
	  }
  }

};

int main() {

    Queue q;
    q.enqueue(1);
    q.enqueue(8);
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.display();

}
