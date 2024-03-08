#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *front = nullptr;
Node *rear = nullptr;
void enqueue(int value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;
    if (front == nullptr)
    {
        front = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}
void dequeue()
{
    if (rear == nullptr)
    {
        cout << "the queue is empty";
    }
    else if (front == rear)
    {
        Node *ptr = front;
        front = rear = nullptr;
        delete (ptr);
    }
    else
    {
        Node *ptr = front;
        front = front->next;
        delete (ptr);
    }
}
void Display()
{
    if (front == nullptr)
    {
        cout << "the queue is empty";
    }
    else
    {
        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
}
int Peek()
{
    if (front == nullptr)
    {
        return -1;
    }
    else
    {
        return front->data;
    }
}
int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    Display();
    dequeue();
    Display();
    cout << "peek :" << Peek();

    return 0;
}
