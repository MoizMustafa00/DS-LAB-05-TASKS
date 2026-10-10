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
		stack = new int[size];
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
		}
		else {
			top++;
			stack[top] = val;
			showTop();
		}
	}
	
	void undo() {
		if(isEmpty()) {
			cout << "Stack is Empty!" << endl;
		}
		else {
			int val = stack[top];
			top--;
			showTop();
		}
	}
	
	int peek() {
		if(isEmpty()) {
			cout << "Stack is Empty!" << endl;
			return -1;
		}
		else {
			return stack[top];
		}
	}
	
	void showTop() {
        if (isEmpty())
            cout << "Top: (empty)" << endl;
        else
            cout << "Top: " << stack[top] << endl;
    }
	
	void display() {
		cout << "Remaining (Top to Bottom): ";
        if (isEmpty()) {
            cout << "(empty)";
        }
		for(int i=top; i>=0; i--) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Stack s(8);

	s.push(12);
	s.push(25);
	s.push(17);
	s.push(31);
	s.push(44);
	s.push(19);
	
	s.undo();
	s.undo();
	s.undo();

	s.push(52);

	s.undo();
	s.undo();
	s.display();
	return 0;
}