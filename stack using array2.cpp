 
#include <iostream>
using namespace std;

#define MAX 10

typedef struct stack {
	int top;
	int items[MAX];
} Stack;

void creatstack(Stack* ps) {
	ps->top = 0;
}

bool Isempty(Stack* ps) {
	return (ps->top == 0);
}

bool Isfull(Stack* ps) {
	return (ps->top == MAX);
}

void push(int e, Stack* ps) {
	if (!Isfull(ps)) {
		ps->items[ps->top] = e;
		ps->top++;
	}
	else {
		cout << "The stack is full" << endl;
	}
}

void pop(Stack* ps) {
	if (!Isempty(ps)) {
		ps->top--;
	}
	else {
		cout << "The stack is empty" << endl;
	}
}

void peek(Stack* ps) {
	if (!Isempty(ps)) {
		cout << ps->items[ps->top - 1] << endl;
	}
	else {
		cout << "The stack is empty" << endl;
	}
}

void display(Stack* ps) {
	for (int i = 0; i < ps->top; i++) {
		cout << ps->items[i] << " ";
	}
	cout << endl;
}

void clear(Stack* ps) {
	ps->top = 0;
}

int main() {
	Stack s;
	creatstack(&s);
	push(5, &s);
	push(6, &s);
	push(7, &s);
	push(8, &s);
	display(&s);
	pop(&s);
	peek(&s);
	clear(&s);

	return 0;
}