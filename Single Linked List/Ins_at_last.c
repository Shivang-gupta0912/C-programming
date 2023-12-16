#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node *Ins_at_last(struct node *head, int d);
void traversing (struct node *head);

int main(){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node* head= malloc(sizeof(struct node));
    head->data= data;
    head->link=NULL;

    struct node *ptr;
    ptr=head;

    char ch;
    printf("Are you wanted to insert more data: ");
    scanf(" %c", &ch);

    while(ch=='Y' || ch=='y'){
        printf("Enter data: ");
        scanf("%d", &data);

        struct node *ptr2 = malloc(sizeof(struct node));
        ptr2->data=data;
        ptr2->link = NULL;

        ptr->link=ptr2;
        ptr=ptr2;

        printf("Are you wanted to insert more data: ");
        scanf(" %c", &ch);
    }

    printf("Your Linked list has been made...\n");
    //traversing and printing data
    ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
    
    printf("\nNow, enter data you want to insert at last: ");
    scanf("%d", &data);
    head=Ins_at_last(head,data);

    printf("Your data has been inserted...\n");
    //traversing and printing data
    traversing(head);

    return 0;
}

struct node *Ins_at_last(struct node *head, int d){
    struct node *ptr;
    ptr=head;

    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data=d;
    ptr2->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }

    ptr->link=ptr2;

    return head;

}

void traversing (struct node *head){
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
}