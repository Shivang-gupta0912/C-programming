#include <stdio.h>
#include <stdlib.h> // for using free() function

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
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->link = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void deque()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (front == NULL && rear == NULL)
    {
        printf("Queue downflow!\n");
    }
    else if (front == rear)
    {
        printf("removed element: %d\n", front->data);
        temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("removed element: %d\n", front->data);
        temp = front;
        front = front->link;
        free(temp);
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
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}