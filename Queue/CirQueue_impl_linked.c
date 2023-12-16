// note: always tries to make circular linked list

#include <stdio.h>
#include <stdlib.h> // to use free() function

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

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
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->link = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        // to make circular linked list
        rear->link = front;
    }
    else
    {
        rear->link = temp;
        rear = temp;
        rear->link = front;
    }
}

void deque()
{
    struct node *temp;
    temp = front;

    if (front == NULL && rear == NULL)
    {
        printf("Queue is downflow!\n");
    }
    else if (front == rear)
    {
        printf("removed element: %d\n", front->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("removed element: %d\n", front->data);
        front = front->link;
        free(temp);
        // to make it circular
        rear->link = front;
    }
}

void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        struct node *temp;
        temp = front;
        printf("Queue: ");
        while (temp != rear)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("%d", temp->data);
        printf("\n");
    }
}