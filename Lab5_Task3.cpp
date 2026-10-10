#include<iostream>
using namespace std;

class Stack {
public:
	int top;
	int size;
	int* stack;
	
	Stack() {
		top = -1;
		size = 0;
		stack = NULL;
	}
	
	Stack(int s) {
		top = -1;
		size = s;
		stack = new int [size];
	}
	
	bool isEmpty() {
		if(top < 0) {
			return true;
		}
		return false;
	}
	
	bool isFull() {
		if(top >= size-1) {
			return true;
		}
		return false;
	}
	
	void push(int data) {
		if(isFull()) {
			cout << "Stack is Full!" << endl;
			return;
		}
		else {
			top++;
			stack[top] = data;
		}
	}
	
	int pop() {
		if(isEmpty()) {
			cout << "Stack is Empty!" << endl;
			return -1;
		}
		else {
			int data = stack[top];
			top--;
			return data;
		}
	}
};

class Queue {
public:
	int front;
	int rear;
	int size;
	int* queue;
	
	Queue() {
		front = -1;
		rear = -1;
		size = 0;
		queue = NULL;
	}
	
	Queue(int s) {
		front = -1;
		rear = -1;
		size = s;
		queue = new int[size];
	}
	
	bool isEmpty() {
		if(front >= rear) {
			return true;
		}
		return false;
	}
	
	bool isFull() {
		if(rear == size-1) {
			return true;
		}
		return false;
	}
	
	void enqueue(int data) {
		if(isFull()) {
			cout << "Queue is Full!" << endl;
			return;
		}
		else {	
			queue[++rear] = data;
		}
	}
	
	int count() {
		return rear - front;
	}
	
	int dequeue() {
		if(isEmpty()) {
			cout << "Queue is Empty!" << endl;
			return -1; 
		}
		else {
			int data = queue[++front];
			return data;
		}
	}
	
	void display() {
		for (int i = front + 1; i <= rear; i++) {
        	cout << queue[i] << " ";
		}
		cout << endl;
	}
};

void reverseFirstK(Queue& q, int k) {
	if (k > q.count())
		k = q.count();
    if (k <= 1)
		 return;
	
	Stack s(k);
	int start = q.front + 1;
	
	for(int i=start; i<start+k; i++) {
		s.push(q.queue[i]);
	}
	
	for(int i=start; i<start+k; i++) {
		q.queue[i] = s.pop();
	}
}

int main() {
    Queue Q1(7);
    Q1.enqueue(1);
    Q1.enqueue(2);
    Q1.enqueue(3);
    Q1.enqueue(4);
    Q1.enqueue(5);
    Q1.enqueue(6);
    Q1.enqueue(7);
    Q1.display();
    reverseFirstK(Q1,3);
    Q1.display();
}