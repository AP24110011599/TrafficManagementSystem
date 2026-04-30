#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int front, rear;
    char vehicles[MAX][20];
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Check empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Enqueue
void enqueue(Queue *q, char vehicle[]) {
    if (isFull(q)) {
        printf("Queue Full! %s cannot enter.\n", vehicle);
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    strcpy(q->vehicles[q->rear], vehicle);

    printf(" %s arrived at signal.\n", vehicle);
}

// Dequeue
char* dequeue(Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }

    char *temp = q->vehicles[q->front];

    q->front++;

    if (q->front > q->rear)
        q->front = q->rear = -1;

    return temp;
}

// Check priority vehicle
int isPriority(char vehicle[]) {
    if (strcmp(vehicle, "ambulance") == 0 ||
        strcmp(vehicle, "firetruck") == 0 ||
        strcmp(vehicle, "police") == 0) {
        return 1;
    }
    return 0;
}

// Display
void display(Queue *q, char name[]) {
    printf("%s Queue: ", name);

    if (isEmpty(q)) {
        printf("Empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%s ", q->vehicles[i]);
    }
    printf("\n");
}

int main() {
    Queue priorityQ, normalQ;
    initQueue(&priorityQ);
    initQueue(&normalQ);

    int choice;
    char vehicle[20];

    while (1) {
        printf("\n===== TRAFFIC SIGNAL WITH PRIORITY =====\n");
        printf("1. Vehicle Arrives\n");
        printf("2. Signal GREEN (Allow Vehicle)\n");
        printf("3. Display Queues\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter vehicle name (ambulance/firetruck/car/bike): ");
                scanf("%s", vehicle);

                if (isPriority(vehicle)) {
                    enqueue(&priorityQ, vehicle);
                } else {
                    enqueue(&normalQ, vehicle);
                }
                break;

            case 2:
                printf("Signal is GREEN...\n");

                if (!isEmpty(&priorityQ)) {
                    printf(" PRIORITY PASS: %s\n", dequeue(&priorityQ));
                }
                else if (!isEmpty(&normalQ)) {
                    printf("NORMAL PASS: %s\n", dequeue(&normalQ));
                }
                else {
                    printf("No vehicles waiting.\n");
                }
                break;

            case 3:
                display(&priorityQ, "Priority");
                display(&normalQ, "Normal");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}