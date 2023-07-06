// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define size 5
int stack[size], top = -1;
void push(int value);
int  pop();
int peek();
void display();
int main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    display();
    pop();
    display();
    cout<<"peek="<<peek()<<endl;
   display();
    return 0;
}
void push(int value)
{
    if (top == size - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}
int  pop()
{
    if (top == -1)
    {
        cout << " the stack is empty";
    }
    else
    {
        return stack[top--];
    }
}
int peek()
{
    if (top == -1)
    {
        cout << "the stack is empty";
    }
    else
    {
        return stack[top];
    }
}
void display()
{
    if (top == -1)
    {
        cout << "the stack is empty";
    }
    else
    {
        cout << "[";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << "]";
    }
    cout << endl;
}
 

 
