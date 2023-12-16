#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *create_linked_list();
void traversing(struct node *head);
struct node *Del_at_last(struct node *head);

int main(){
    struct node *head;
    head=create_linked_list();
    printf("Your Linked list has been created...\n");
    traversing(head);
    head=Del_at_last(head);
    printf("\nYour last node has been deleted...\n");
    traversing(head);

    return 0;
}

struct node *create_linked_list(){
    int data;
    char ch;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node *head = malloc (sizeof(struct node));
    head->data=data;
    head->link=NULL;

    struct node *ptr;
    ptr=head;

    printf("Are you wanted to insert more data(y/n): ");
    scanf(" %c", &ch);

    while(ch=='y' || ch=='Y'){
        printf("Enter data: ");
        scanf("%d", &data);
        struct node* ptr2 = malloc(sizeof(struct node));
        ptr2->data=data;
        ptr2->link=NULL;

        ptr->link=ptr2;
        ptr=ptr2;
        printf("Are you wanted to insert more data(y/n): ");
        scanf(" %c", &ch);
    }

    return head;
}

void traversing(struct node*head){
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
    free(ptr);
}

struct node* Del_at_last(struct node* head){
    struct node *ptr;
    ptr=head;
    while(ptr->link->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=NULL;
    return head;
}

