#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void initializeQueue(struct Queue *queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue *queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue *queue, int num) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return 0;
    }
    int count = 0;
    printf("Deleted elements are: ");
    for (int i = 0; i < num; i++) {
        if (isEmpty(queue)) {
            printf("\nDequeued %d elements.\n", count);
            return count;
        }
        printf("%d ", queue->front->data);
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        count++;
        if (queue->front == NULL) {
            queue->rear = NULL;
            printf("\nDequeued %d elements.\n", count);
            return count;
        }
    }
    printf("\nDequeued %d elements.\n", count);
    return count;
}

int countElements(struct Queue *queue) {
    int count = 0;
    struct Node* current = queue->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void displayQueue(struct Queue *queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int choice, value, num;
    printf("Initializing a queue!\n");
    do {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display number of elements in the queue\n");
        printf("4. Display queue elements\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                printf("Number of elements in queue: %d\n", countElements(&queue));
                break;
            case 2:
                printf("Enter the number of elements to dequeue: ");
                scanf("%d", &num);
                dequeue(&queue, num);
                printf("Number of elements in queue: %d\n", countElements(&queue));
                break;
            case 3:
                printf("Number of elements in queue: %d\n", countElements(&queue));
                break;
            case 4:
                printf("Queue elements are: ");
                displayQueue(&queue);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("What ra??\n");
        }
    } while (choice != 5);

    return 0;
}
