#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node*head, int val);
void display(struct node *head);
void remove_duplicate(struct node *head);

void main()
{
    struct node *head = NULL;
    head = insert(head, 2);
    head = insert(head,3);
    head = insert(head,3);
    head = insert(head,4);
    printf("The list before removing the duplicate node: ");
    display(head);
    remove_duplicate(head);
    printf("\n the list after removing the duplicate nodes: ");
    display(head);
}

struct node *insert(struct node*head, int val)
{
    struct node*current = head;
    struct node *temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    if(head == NULL){
        head = temp;
    }
    else{
        while(current->next != NULL){
            current=current->next;
        }
        current->next = temp;
    }
    return head;
}

void display(struct node *head){
    struct node *current = head;
    while(current!=NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL");
}

void remove_duplicate(struct node *head)
{
    struct node* current = head;
    struct node* current1;

    while (current != NULL && current->next != NULL) {
        current1 = current;
        while (current1->next != NULL) {
            if (current->data == current1->next->data) {
                struct node* temp = current1->next;
                current1->next = current1->next->next;
                free(temp);
            } else {
                current1 = current1->next;
            }
        }
        current = current->next;
    }
}


