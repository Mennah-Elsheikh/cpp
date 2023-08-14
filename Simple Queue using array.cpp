#include <iostream>
using namespace std; 
#define SIZE 5 
int queue[SIZE];
int front = -1;
int rear = -1;
void enqueue(int value);
void dequeue();
void peek();
void display();
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    display();
    dequeue();
    display();
    peek();
    display();
    return 0;
}
void enqueue(int value)
{
    if (rear != SIZE)
    {
        if (front == -1 && rear == -1)
        {
            front ++;
            rear++;
            queue[rear] = value;
        }
        else
        {
            rear++;
            queue[rear] = value;
        }
    }
}
void dequeue()
{
    if (front != -1 && rear != -1 && front <= rear)
    {
        front++;

    }
    else {
        cout << "the queue is empty" << endl;
    }    
}
void peek()
{

    if (front != -1 && rear != -1 && front <= rear)
    {
        cout << queue[front];

    }
    else {
        cout << "the queue is empty" << endl;
    }

}
void display()
{

    if (front != -1 && rear != -1 && front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " " << endl;
        }

    }
    else {
        cout << "the queue is empty" << endl;
    }
}
 