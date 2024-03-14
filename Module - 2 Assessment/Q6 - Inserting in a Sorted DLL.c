#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
};

struct node *insert (struct node * head, int val);
void display (struct node * head);
struct node *insert_sorted(struct node *head , int newval);

void main()
{
  struct node *head = NULL;
  int n;
  printf("Enter the number of nodes to be inserted: ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
      printf("Enter the data for node %d: ",i+1);
      int val;
      scanf("%d",&val);
      head = insert(head, val);
  }
  printf("\nThe initial list: ");
  display(head);
  printf("\nEnter the data for the new node: ");
  int newval;
  scanf("%d",&newval);
  head = insert_sorted(head,newval);
  printf("\nThe list after inserting %d:",newval);
  display(head);


}

struct node *insert(struct node *head, int val)
{
    struct node*current = head;
    struct node *temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
    }
    else{
        while(current->next!=NULL){
            current = current->next;
        }
        temp->prev = current;
        current->next = temp;
    
    }
    return head;
}

void display(struct node*head){
    struct node *ptr = head;
    printf("NULL");
    while(ptr!=NULL){
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

struct node *insert_sorted(struct node *head, int newval)
{
    struct node *current = head;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = newval;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL || newval < head->data) {
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        head = temp;
    } else {
        while (current != NULL && newval >= current->data) {
            current = current->next;
        }

        if (current != NULL) {
            temp->prev = current->prev;
            temp->next = current;
            current->prev->next = temp;
            current->prev = temp;
        } else {
            
            struct node *last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = temp;
            temp->prev = last;
        }
    }

    return head;
}


