#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *top=NULL;

void push(int data);
void pop();
void traverse();

int main(){
    int ch, data;
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Traverse\n");
        printf("4.Quit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Program is terminated");
                exit(1);
                break;
            default:
                printf("Enter a valid choice!!!");
        }
        
        printf("\n");
    }
}

void push(int data){
    struct node *ptr = malloc (sizeof(struct node));
    if(ptr==NULL){
        printf("Stack is overflow");
        exit(1);
    }
    ptr->data=data;
    ptr->link=NULL;

    ptr->link=top;
    top=ptr;
    ptr=NULL;
}

void pop(){
    struct node *temp;
    temp=top;
    if (top==NULL){
        printf("Stack is downflow");
        return;
    }
    top=top->link;
    free(temp);
    temp=NULL;
}

void traverse(){
    struct node *temp;
    temp=top;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->link;
    }
}
