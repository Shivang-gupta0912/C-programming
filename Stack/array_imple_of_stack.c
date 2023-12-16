#include <stdio.h>
#include <stdlib.h>

#define Max 5

int stack[Max];
int top=-1;

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

        switch(ch){
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
            default:
                printf("Enter a valid choice");
        }
        printf("\n");
    }
}

void push (int data){
    if (top==Max-1){
        printf("Stack is overflow\n");
        return;
    }
    top++;
    stack[top]=data;
}

void pop(){
    if(top==-1){
        printf("Stack is downflow\n");
        return;
    }
    top--;
}

void traverse(){
    for (int i=0; i<=top; i++){
        printf("%d ", stack[i]);
    }
}