#include <iostream>
using namespace std;

struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
};

class Linked_Queue
{
private:
    Node *front = nullptr;
    Node *rear = nullptr;
    int length = 0;
    int size;

public:
    Linked_Queue(int size) : size(size) {}

    ~Linked_Queue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        length = 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == size;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "The queue is full" << endl;
        }
        else
        {
            Node *new_node = new Node(value);
            if (isEmpty())
            {
                rear = front = new_node;
            }
            else
            {
                rear->next = new_node;
                rear = new_node;
            }
            length++;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            length--;
            if (isEmpty())
            {
                rear = nullptr;
            }
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
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

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return front->data;
        }
    }
};

int main()
{
    Linked_Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.display();
    cout << "Peek: " << q.peek() << endl;
    return 0;
}
