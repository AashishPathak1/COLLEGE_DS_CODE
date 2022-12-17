#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define QUEUESIZE 5

typedef struct
{
    int item[QUEUESIZE];
    int front, rear;
} queue;

void insert(int x, queue *q);
int delete1(queue *q);
void display(queue *q);

void main()
{
    int x;
    queue q;
    int choice;
    int c;
    q.front = -1;
    q.rear = -1;

    while (1)
    {
        printf("\n 1.INSERT \n 2.DELETE \n 3. DISPLAY\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n ENTER ELEMENTS :");
            scanf("%d", &x);
            insert(x, &q);
            break;

        case 2:
            printf("\n the deleted elemet %d", delete1(&q));
            break;

        case 3:
            display(&q);
            break;

        default:
            printf("\n YOU HAVE ENTERED WRONG CHOICE");
            break;
        }
    }
}

void insert(int x, queue *q)
{
    if (q->rear >= QUEUESIZE - 1)
    {
        printf("\n CIRCULAR QUEUE IS OVERFLOW");
    }

    if (q->front == -1)
        q->front = (q->front + 1);
    q->rear = (q->rear + 1);
    q->item[q->rear] = x;
}

int delete1(queue *q)
{
    int x;
    if (q->front == -1)
    {
        printf("\n CIRCULAR QUEUE UNDERFLOW \n");
        return (0);
    }
    else
    {
        x = q->item[q->front];
        if (q->front = q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front + 1) % QUEUESIZE;
        return (x);
    }
}

void display(queue *q)
{
    int i, x;
    if (q->front == -1 || q->front > q->rear)
    {
        printf("\nCIRCULAR QUEUE IS EMPTY\n");
    }
    else
    {
        for (i = q->front; i <= q->rear; i++)
            printf("%d\t", q->item[i]);
    }
}
