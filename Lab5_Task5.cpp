#include<iostream>
using namespace std;

class Stack {
public:
    int top;
    int size;
    int* stack;

    Stack(int s) {
        top = -1;
        size = s;
        stack = new int[size];
    }

    ~Stack() { 
		delete[] stack; 
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

    void push(int val) {
        if(isFull()) {
            cout << "Stack is Full!" << endl;
            return;
        }
        stack[++top] = val;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return stack[top--];
    }
};

class MyQueue {
public:
    Stack in;
    Stack out;

    MyQueue() : in(100), out(100) {}

    void enqueue(int val) {
        in.push(val);
    }

    int dequeue() {
        if(out.isEmpty()) {
            while(!in.isEmpty())
                out.push(in.pop());
        }
        if(out.isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return out.pop();
    }

    void display() {
        for(int i = out.top; i >= 0; i--)
            cout << out.stack[i] << " ";
            
        for(int i = 0; i <= in.top; i++)
            cout << in.stack[i] << " ";
        cout << endl;
    }
};

int main() {
    MyQueue mq;
    mq.enqueue(10);
    mq.enqueue(11);
    cout << "Dequeued: " << mq.dequeue() << endl;
    mq.enqueue(12);
    cout << "Dequeued: " << mq.dequeue() << endl;
    cout << "Dequeued: " << mq.dequeue() << endl;
    mq.dequeue();
    mq.display();
}