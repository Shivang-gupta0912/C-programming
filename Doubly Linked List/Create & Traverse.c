#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create();
void traverse(struct node *head);

int main(){
    struct node *head;
    head = create();
    printf("Your Doubly Linked List has been created...\n");
    traverse(head);
    return 0;
}

struct node* create(){
    int data;
    char ch;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node *head = malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=data;
    head->next=NULL;

    struct node *ptr;
    ptr=head;

    printf("Are You wanted to insert more data(y/n): ");
    scanf(" %c", &ch);

    while(ch=='Y' || ch=='y'){
        printf("Enter data: ");
        scanf("%d", &data);
        struct node *ptr2 = malloc(sizeof(struct node));
        ptr2->prev=NULL;
        ptr2->data=data;
        ptr2->next=NULL;

        ptr2->prev=ptr;
        ptr->next=ptr2;

        ptr=ptr2;

        printf("Are You wanted to insert more data(y/n): ");
        scanf(" %c", &ch);
    }

    return head;
}

void traverse(struct node *head){
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}