#include<stdio.h>
#define size 8

void enqueue(int value);
void dequeue();
void display();
void queue_sort();

int queue[size];
int front = -1;
int rear = -1;

void main(){
    enqueue(6);
    enqueue(4);
    enqueue(9);
    enqueue(2);
    enqueue(7);
    enqueue(3);
    enqueue(1);
    enqueue(8);
    printf("The initial queue is: ");
    display();
    queue_sort();
    printf("\nThe queue after sorting is: ");
    display();
    
}

void enqueue(int value){
    if(rear == size-1){
        printf("\n The queue is full!");
        return;
    }
    else{
    if(front == -1)
        front++;
    rear++;
    queue[rear] = value;
    
    }
}

void dequeue(){
    if(front == -1){
        printf("\n\nQueue is empty!");
        return;
    }
    printf("\nThe value %d is deleted.",queue[front]);
    front++;
    if(front > rear){
        front = rear = -1;
    }
}

void display()
{
    int i;
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

void queue_sort(){
    int i,j;
    int temp;
    for(i=front;i<=rear;i++){
        for(j=i+1;j<=rear;j++){
            if(queue[i]>queue[j]){
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}