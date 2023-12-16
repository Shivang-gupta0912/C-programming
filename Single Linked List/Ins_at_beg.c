#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *Ins_at_beg(struct node* head, int data);
void traversing (struct node *head);

int main (){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *head = malloc(sizeof(struct node));
    head->data=data;
    head->link=NULL;

    char ch;
    printf("Are you wanted to insert more data (y/n): ");
    scanf(" %c", &ch);

    struct node* ptr;
    ptr=head;

    while(ch=='Y' || ch=='y'){
        printf("Enter data: ");
        scanf("%d", &data);
        struct node *ptr2 = malloc(sizeof(struct node));
        ptr2->data = data;
        ptr2->link = NULL;

        ptr->link=ptr2;
        ptr=ptr2;
        printf("Are you wanted to insert more data (y/n): ");
        scanf(" %c", &ch);
    }

    printf("You Linked list is ready: \n");
    // Traversing
    traversing (head);

    printf("Now, enter data you want to insert at begining: ");
    scanf("%d", &data);

    head=Ins_at_beg(head,data);

    printf("Your data has been inserted...\n");
    // again, Traversing
    traversing(head);

    return 0;
}

struct node *Ins_at_beg(struct node* head, int d){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link = NULL;

    ptr->link=head;
    head=ptr;

    return head;
}

void traversing (struct node *head){
    struct node *ptr;
    ptr = head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
}