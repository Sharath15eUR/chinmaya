#include<stdio.h>
#include<stdlib.h>

struct node
{
  char data;
  struct node *prev;
  struct node *next;
};

struct node *insert (struct node * head, char val);
void display (struct node * head);
struct node *rotateList(struct node *head, int N);

void main()
{
  struct node *head = NULL;
  head = insert (head, '1');
  head = insert (head, '2');
  head = insert (head, '3');
  head = insert (head, '4');
  head = insert (head, '5');
  head = insert (head, '6');
  head = insert (head, '7');
  head = insert (head, '8');
  printf("The list before rotation: ");
  display(head);
  printf("\nEnter the rotation count: ");
  int N;
  scanf("%d",&N);
  head = rotateList(head,N);
  printf("\nThe list after rotation: ");
  display(head);

}

struct node *insert(struct node *head, char val)
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
        printf(" %c ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

struct node *rotateList(struct node *head, int N) {
    if (head == NULL || N == 0) {
        return head;
    }

    int length = 0;
    struct node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    
    int rotation = N % length;
    if (rotation == 0) {
        return head; 
    }


    temp = head;
    for (int i = 0; i < (length - rotation - 1); i++) {
        temp = temp->next;
    }


    struct node *newHead = temp->next;
    newHead->prev = NULL;
    temp->next = NULL;

    
    struct node *end = newHead;
    while (end->next != NULL) {
        end = end->next;
    }
    end->next = head;
    head->prev = end;

    return newHead;
}
