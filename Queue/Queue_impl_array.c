#include <stdio.h>
#define size 7

int queue[size], front = -1, rear = -1;
void enque(int val);
void deque();
void display();

int main()
{
    enque(8);
    display();

    deque();
    display();

    enque(7);
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
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else if (rear == size - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}

void deque()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue downflow!\n");
    }
    else if (front == rear)
    {
        printf("element removed: %d \n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("element removed: %d \n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}
