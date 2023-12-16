// rear=rear+1  -> increment
// rear=(rear+1)%N  -> behaves like increment untill rear+1<N , when rear+1=N it gives 0

#include <stdio.h>
#define size 5

int queue[size], front = -1, rear = -1;
void enque(int val);
void deque();
void display();

int main()
{
    enque(8);
    display();

    enque(7);
    display();

    enque(6);
    display();

    enque(5);
    display();

    deque();
    display();

    deque();
    display();

    enque(9);
    display();

    enque(2);
    display();

    deque();
    display();

    enque(3);
    display();
}

void enque(int val)
{
    if (front == -1 && rear == -1)
    {
        // empty condition
        front = rear = 0;
        queue[rear] = val;
    }
    else if ((rear + 1) % size == front)
    {
        // full condition
        printf("Queue is overflow!\n");
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = val;
    }
}

void deque()
{
    if (front == -1 && rear == -1)
    {
        // empty condition
        printf("Queue is downflow!\n");
    }
    else if (front == rear)
    {
        // single element
        printf("removed element: %d \n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("removed element: %d \n", queue[front]);
        front = (front + 1) % size;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        int i = front;

        // important part
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d", queue[rear]);
        printf("\n");
    }
}