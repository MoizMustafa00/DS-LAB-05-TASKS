#include<iostream>
using namespace std;

class CircularQueue {
public:
	int front;
	int rear;
	int size;
	int* queue;
	int count;
	
	CircularQueue() {
		size = 0;
		front = -1;
		rear = -1;
		queue = NULL;
		count = 0;
	}
	
	CircularQueue(int s) {
		size = s;
		front = -1;
		rear = -1;
		queue = new int[size];
		count = 0;
	}
	
	bool isEmpty() {
		if(count == 0) {
			return true;
		}
		return false;
	}
	
	bool isFull() {
		if(count == size) {
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
			rear = (rear + 1) % size;
			queue[rear] = data;
			count++;
		}
	}
	
	int dequeue() {
		if(isEmpty()) {
			cout << "Queue is Empty!" << endl;
			return -1; 
		}
		else {
			front = (front + 1) % size;
			int data = queue[front];
			count--;
			return data;
		}
	}
	
	void display() {
		if(isEmpty()) {
			cout << "Queue is Empty!" << endl;
			return;
		}
	
		int i = (front + 1) % size;
		for(int c=0; c<count; c++) {
			cout << queue[i] << " ";
			i = (i + 1) % size;
		}
		cout << endl;
	}
	
	~CircularQueue() {
		delete[] queue;
		queue = NULL;
	}
};

int main() {
	CircularQueue C1(6);
    C1.enqueue(101);
    C1.enqueue(102);
    C1.enqueue(103);
    C1.enqueue(104);
    C1.enqueue(105);
    C1.enqueue(106);
    C1.dequeue();
    C1.dequeue();
    C1.dequeue();
    C1.enqueue(107);
    C1.enqueue(108);
    C1.enqueue(109);
    C1.dequeue();
    C1.dequeue();
    C1.enqueue(110);
    C1.dequeue();
    C1.enqueue(111);
    C1.enqueue(112);
    C1.display();
    cout << "Front: " << C1.front << endl;
    cout << "Rear: " << C1.rear << endl;
}