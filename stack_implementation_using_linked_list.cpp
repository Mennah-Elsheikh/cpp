

#include <iostream>
using namespace std;

template<class t>
class stack {
	struct node
	{
		t item;
		node* next;
	};
	node* top;
public:
	stack() {
		top = NULL;
	}
	void push(t newItem)
	{
		node* newItemPtr = new node;
		if (newItemPtr == NULL)
		{
			cout << "Stack push cannot allocate memory";
		}
		else {
			newItemPtr->item = newItem;
			newItemPtr->next = top;
			top = newItemPtr;
		}
	}
	bool IsEmpty()
	{
		return top == NULL;
	}
	void pop() {
		if (IsEmpty())
		{
			cout << "the stack is empty";
		}
		else
		{
			node* current = top;
			top = top->next;
			current->next = NULL;
			delete current;
		}
	}
	void peek() {
		if (IsEmpty())
		{
			cout << "the stack is empty";
		}
		else
		{
			cout << top->item << endl;
		}
	}
	void display() {
		if (IsEmpty()) {
			cout << "Stack is empty." << endl;
		}
		else {
			node* current_node = top;
			while (current_node != NULL)
			{
				cout << current_node->item << "\t";
				current_node = current_node->next;
			}
			cout << endl;
		}
	}
};

int main()
{
	stack<int>s;
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.display();
	s.peek();
	s.display();
	s.pop();
	s.display();

	return 0;
}