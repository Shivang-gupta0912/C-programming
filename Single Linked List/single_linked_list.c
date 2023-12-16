
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

// Function for Traversing
void traversing(struct node *head);

int main(){
    char ch='y';
    int data;

    printf("Enter data:");
    scanf("%d",&data);

    struct node *head = malloc(sizeof(struct node));
    head->data=data;
    head->link=NULL;

    struct node *ptr ;
    ptr=head;

    printf("Are you wanted to insert more data: ");
    // ch=getch();
    scanf(" %c", &ch);

    while(ch=='y' || ch=='Y'){
        printf("Enter data:");
        scanf("%d", &data);

        struct node *ptr2 = malloc(sizeof(struct node));
        ptr2->data=data;
        ptr2->link=NULL;

        ptr->link=ptr2; // adding node
        ptr=ptr2; //updation

        printf("Are you wanted to insert more data: ");
        // ch=getch();
        scanf(" %c", &ch);
    }

    printf("Your Linked List has been made...\n");

    // trversing and printing data
    traversing(head);
}

void traversing (struct node *head){
    struct node *ptr;
    ptr=head;
    while (ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
}
