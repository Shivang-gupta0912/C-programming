
// function Del_a_node_using_data() have not yet made

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *create_linked_list();
void traversing(struct node *head);
struct node *Del_a_node_using_data(struct node* head, int d);

int main(){
    struct node *head;
    int data;
    head=create_linked_list();
    printf("Your Linked list has been created...\n");
    traversing(head);
    printf("\nEnter the data of node to be deleted: ");
    scanf("%d", &data);
    head=Del_a_node_using_data(head, data);
    
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

struct node* Del_a_node_using_data(struct node* head, int d){
    struct node *ptr, *del; //del- node to be deleted and ptr-just previous node 

    del=head;
    if (del->data==d){  //checking the first node 
        del=del->link;
        head=del;

        free(del);
        printf("Your data has been deleted: \n");
        return head;
    }
    else{
        while(del->data!=d){  //checking untill the required node is not found
            if (del->link==NULL){ //checking Is there a place for del pointer to shift
                printf("Data not Found...\n");  // del pointer points the last node means data doesn't match
                return head;
            }
            //shifting of ptr and del pointer
            ptr=del; 
            del=del->link;
        }
        // node found which we want to delete
        // and del pointer points that node 
        ptr->link=del->link;
        free(del);
        printf("Your data has been deleted: \n");
        return head;
    }
    
}
