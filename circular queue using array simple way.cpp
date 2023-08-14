#include <iostream>
using namespace std;
#define size 5
int queue[size];
int front = -1;
int rear = -1;

bool IsEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else {
        return false;
    }
}

bool IsFull()
{
    if (front == 0 && rear == size - 1)
    {
        return true;
    }
    else if (rear == front - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int value)
{
    if (rear == -1 && front == -1)
    {
        front = 0;
        rear++;
        queue[rear] = value;
    }
    else if (IsFull())
    {
        cout << "The queue is full" << endl;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}

int peek()
{
    return queue[front];
}

void dequeue()
{
    if (IsEmpty())
    {
        cout << "The queue is empty " << endl;
    }
    else if (front == rear) //the queue is full
    {
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
        //to return the front to 0 to continue
    }
}

void display()
{
    if (IsEmpty())
    {
        cout << "The queue is empty " << endl;
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else {
            for (int i = 0; i < size; i++)
            {
                cout << queue[i] << " ";
            }
        }
    }
    cout << endl;
}
//void display_reverse ()
//{
//    if (IsEmpty())
//    {
//        cout << "The queue is empty " << endl;
//    }
//    else
//    {
//        if (front <= rear)
//        {
//            for (int i = front; i <= rear; i++)
//            {
//                cout << queue[i] << " ";
//            }
//        }
//        else {
//            for (int i = size -1 ; i > 0 ; i--)
//            {
//                cout << queue[i] << " ";
//            }
//        }
//    }
//    cout << endl;
//}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    display();

    dequeue();
    display();

    cout << peek() << endl;
    display();

    return 0;
}