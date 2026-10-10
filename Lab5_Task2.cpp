#include<iostream>
#include<string>
using namespace std;

class Stack {
public:
	int top;
	int size;
	string* stack;
	
	Stack() {
		top = -1;
		size = 0;
		stack = NULL;
	}
	
	Stack(int s) {
		top = -1;
		size = s;
		stack = new string[size];
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
	
	void push(string str) {
		if(isFull()) {
			cout << "Stack is Full!" << endl;
			return;
		}
		top++;
		stack[top] = str;
	}
	
	string pop() {
		if(isEmpty()) {
			cout << "Stack is Empty!" << endl;
			return "";
		}
		string str = stack[top];
		top--;
		return str;
	}
	
	string peek() {
		if(isEmpty()) {
			cout << "Stack is Empty!" << endl;
			return "";
		}
		return stack[top];
	}
	
	void print() {
		for(int i=0; i<=top; i++) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};

class TextEditor {
public:
	Stack s1;
	Stack s2;
	
	TextEditor() : s1(100), s2(100) {}
	
	void type(string word) {
	s1.push(word);
	s2.top = -1;
	}
	
	void undo() {
		if(s1.isEmpty()) {
			cout << "Cannot Undo" << endl;
			return;
		}
		s2.push(s1.pop());
	}
	
	void redo() {
		if(s2.isEmpty()) {
			cout << "Cannot Redo" << endl;
			return;
		}
		s1.push(s2.pop());
	}
	
	void print() {
		s1.print();
	}
};

int main() {
	TextEditor t;
	
	t.type("Hello");
	t.print();
	t.type("World");
	t.print();
	t.undo();
	t.print();
	t.redo();
	t.print();
	t.undo();
	t.print();
	t.type("There");
	t.print();
	t.redo();
	t.print();
}