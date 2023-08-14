#include <iostream>
using namespace std;

typedef struct queue
{
    int front;
    int rear;
    int size;
    int maxsize = 4;
    int entry[4];
} Queue;

void createQueue(Queue* pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void enqueue(int e, Queue* pq)
{
    pq->rear = (pq->rear + 1) % pq->maxsize;
    pq->entry[pq->rear] = e;
    pq->size++;
}

void dequeue(Queue* pq)
{
    pq->front = (pq->front + 1) % pq->maxsize;
    pq->size--;
}

int IsEmpty(Queue* pq)
{
    return (pq->size == 0);
}

int IsFull(Queue* pq)
{
    return (pq->size == pq->maxsize);
}

void display(Queue* pq)
{
    for (int i = pq->front, s = 0; s < pq->size; s++)
    {
        i = (i + 1) % pq->maxsize;
        cout << pq->entry[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;
    createQueue(&q);
    enqueue(5, &q);
    enqueue(10, &q);
    enqueue(15, &q);
    enqueue(20, &q);
    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}