#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*STRUCTURE DEFINITION*/
struct node
{
    int info;
    struct node *next;
};

/*GETNODE() DEFINITION*/
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        printf("\n NEW NODE CANNOT BE GENERATED");
    else
        return (p);
};

/*FUNCTION PROTOTYPES*/
void insert_front(struct node **q);    /*INSERTION FRONT*/
void delete_front(struct node **q);    /*DELETION FRONT*/
void insert_end(struct node *q);       /*INSERTION AT END */
void delete_end(struct node *q);       /*DELETION AT END*/
void ins_queue_end(struct node *q);    /*QUEUE INSERTION*/
void del_queue_front(struct node **q); /*QUEUE DELETION*/
void push(struct node **q);            /*STACK IMPLIMENTATION*/
void pop(struct node **q);             /*STACK IMPLIMENTTAION*/
void ins_given_node(struct node *q);   /*GIVEN NODE*/
void del_given_node(struct node **q);  /*GIVEN NODE*/
void count_node(struct node *q);       /*COUNTING NODE*/
void traverse(struct node *q);         /*TRAVERSE*/

/*MAIN FUNCTION*/
void main()
{
    struct node *list;
    int choice;
    char ch;
    list = NULL;
    while(1)
    {
        printf("\n 1.INSERT_NODE \n 2.DELETE_FRONT \n 3.INSERT_END \n");
        printf("\n 4.DELETE_END \n 5.INSERT_QUEUE_END \n 6.DELETE_QUEUE_FRONT \n");
        printf("\n 7.PUSH \n 8.POP \n 9.INSERT_GIVEN_NODE \n");
        printf("\n 10.DELETE_GIVEN_NODE \n 11.COUNT_NODE \n 12.TRAVERSE \n");
        printf("\n ENTER YOUR CHOICE");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front(&list);
            break;

        case 2:
            delete_front(&list);
            break;

        case 3:
            insert_end(list);
            break;

        case 4:
            delete_end(list);
            break;

        case 5:
            ins_queue_end(list);
            break;

        case 6:
            del_queue_front(&list);
            break;

        case 7:
            push(&list);
            break;

        case 8:
            pop(&list);
            break;

        case 9:
            ins_given_node(list);
            break;

        case 10:
            del_given_node(&list);
            break;

        case 11:
            count_node(list);
            break;

        case 12:
            traverse(list);
            break;

        default:
            printf("\n YOU HAVE ENTERED WRONG CHOICE \n");
            break;
        }  
    }
getch();
}

/*INSERTION AT FRONT DEFINITION*/
void insert_front(struct node **q)
{
    struct node *t;
    t = getnode();
    if (t != NULL)
    {
        printf("\n ENTER THE NFO VALUE \n");
        scanf("%d", &t->info);
        t->next = *q;
        *q = t;
    }
}

/*DELETION AT FRONT DEFINITION*/
void delete_front(struct node **q)
{
    int x;
    struct node *t;
    if (*q == NULL)
        printf("\n LINK LIST IS EMPTY\n");
    else
    {
        t = *q;
        x = t->info;
        *q = t->next;
        free(t);
    }
    printf("THE DELETED ELEMENT =%d",x);
}

/*INSERTION AT END*/
void insert_end(struct node *q)
{
    struct node *t;
    while (q->next != NULL)
        q = q->next;
    t = getnode();
    if (t != NULL)
    {
        printf("\n ENTER THE NODE INFO VALUE");
        scanf("%d", t->info);
        t->next = q->next;
        q->next = t;
    }
}

/*DELETION OF NODE AT END*/
void delete_end(struct node *q)
{
    struct node *prev;
    int x;
    if (q = NULL)
        printf("\n LINK LIST IS EMPTY");
    else
    {
        while (q->next != NULL)
        {
            prev = q;
            q = q->next;
        }
        x = q->info;
        prev->next = q->next;
        free(prev);
    }
    printf("THE DELETED ELEMENT :%d",x);
}

/*QUEUE INSERTION*/
void ins_queue_end(struct node *q)
{
    struct node *t;
    while (q->next != NULL)
        q = q->next;
  t = getnode();
    if (t != NULL)
    {
        printf("\n ENTER QUEUE VALUE");
        scanf("%d", t->info);
        t->next = q->next;
        q->next = t;
    }
}

/*QUEUE DELETION*/
void del_queue_front(struct node **q)
{

    int x;
    struct node *t;
    if (*q == NULL)
        printf("\n QUEUE IS EMPTY\n");
    else
    {
        t = *q;
        x = t->info;
        *q = t->next;
        free(t);
    }
    printf("THE DELETED ELEMENT :%d",x);
}

/*STACK IMPLIMENETATION WITH PUSH*/
void push(struct node **q)
{
    struct node *t;
    t = getnode();
    if ((t != NULL))
    {
        printf("\n ENTER STACK VALUE\n");
        scanf("%d", &t->info);
        if (*q = NULL)
        {
            t->next = NULL;
            *q = t;
        }
        else
        {
            t->next = *q;
            *q = t;
        }
    }
}

/*STACK IMPLIMENTATION WITH POP*/
void pop(struct node **q)
{
    int x;
    struct node *t;
    if (*q == NULL)
        printf("\n STACK IS UNDERFLOW");
    else
    {
        t = *q;
        x = t->info;
        *q = t->next;
        free(t);
        printf("\n POPPED ELELMENTS : %d", x);
    }
}

/*INSERTION AT GIVEN NODE*/
void ins_given_node(struct node *q)
{
    int loc, i;
    struct node *t;
    printf("\n ENTER NODE ELEMENT");
    scanf("%d", &loc);
    for (i = 0; i < loc; i++)
        q = q->next;
    if (q == NULL)
        printf("\n link list has less no of node");
    else
    {
        t = getnode();
        if (t != NULL)
        {
            printf("\n enter node info value");
            scanf("%d", &t->info);
            t->next = q->next;
            q->next = t;
        }
    }
}

/*DELETION OF GIVEN NODE*/
void del_given_node(struct node **q)
{
    int loc, i, x;
    struct node *prev, *p;
    if (*q == NULL)
        printf("\n LIST IS EMPTY");
    else
    {
        printf("\n enter node number");
        scanf("%d", &loc);
        p = *q;
        if (loc == 1)
        {
            x = p->info;
            *q = p->next;
        }
        else
        {
            for (i = 0; i < loc; i++)
            {
                prev = p;
                p = p->next;
            }
            if (p == NULL)
                printf("\n LINK LIST IS EMPTY\n");
            else
            {
                x = p->info;
                prev->next = p->next;
            }
            printf("THE DELETED ELEMENT : %d",&p->next);
        }
        free(p);
    }
}

/*COUNTING NODE*/
void count_node(struct node *q)
{
    int count;
    count = 0;
    while (q != NULL)
    {
        count = count + 1;
        q = q->next;
    }
    printf("\n NO. OF NODE : %d", count);
}

/*TRAVERSE*/
void traverse(struct node *q)
{
    if (q == NULL)
        printf("\n LINK LIST IS EMPTY\n");
    else
    {
        while (q != NULL)
        {
            if (q->next==NULL)
                printf("%d", q->info);
            else
                printf("%d->",q->info);
            q = q->next;
        }
    }
}
