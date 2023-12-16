#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *create_linked_list();
void traversing (struct node *head);
struct node *Ins_at_certain_position(struct node *head, int d, int pos);

int main(){
    struct node *head;
    int data,pos;
    head=create_linked_list();
    printf("Your Linked list has been made...\n");
    traversing(head);

    printf("\nNow, enter the data you want to insert: ");
    scanf("%d", &data);
    printf("Enter position: ");
    scanf("%d", &pos);

    head=Ins_at_certain_position(head, data, pos);
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
    
    while(ch=='Y' || ch=='y'){
        printf("Enter data: ");
        scanf("%d", &data);

        struct node *ptr2=malloc(sizeof(struct node));
        ptr2->data=data;
        ptr2->link=NULL;

        ptr->link=ptr2;
        ptr=ptr2;

        printf("Are you wanted to insert more data(y/n): ");
        scanf(" %c", &ch);
    }

    return head;
}

void traversing (struct node *head){
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
    
}

struct node *Ins_at_certain_position(struct node *head, int d, int pos){
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data=d;
    ptr2->link=NULL;

    if (pos==1){
        ptr2->link=head;
        head=ptr2;
    }
    else if (pos>1){
        struct node *ptr;
        ptr=head;
        while(pos>2){
            ptr=ptr->link;
            pos--;
        }
        ptr2->link=ptr->link;
        ptr->link=ptr2;
    }

    return head;
}