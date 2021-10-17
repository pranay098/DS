#include <stdio.h>
#include <stdlib.h>

struct node
{
    int payload;
    struct node *next;
};

void printList(struct node *start)
{
    if (start != NULL)
    {
        struct node *itr = start;
        while (itr != NULL)
        {
            printf("%d -> ", itr->payload);
            itr = itr->next;
        }
        printf("X");
    }
    else
    {
        printf("Empty list!");
    }
}

void insertAtBegining(struct node **start_ref, int inputValue)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    ///creating a new node
    newNode->payload = inputValue;
    ///new node points to previous first node, i.e. copy value from head
    newNode->next = *start_ref;
    ///head will now point to new node
    *start_ref = newNode;
}

void deleteFromEnd(struct node **start_ref)
{
    struct node *itr;
    if (*start_ref != NULL)
    {
        itr = *start_ref;
        while (itr->next->next != NULL)
            itr = itr->next;

        free(itr->next);
        itr->next = NULL;
    }
    else
    {
        printf("\nList is empty nothing to delete\n");
    }
}

void insertSorted(struct node **start_ref, int val)
{
    struct node *itr;

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->payload = val;

    if ((*start_ref != NULL) && ((*start_ref)->next != NULL))
    {

        if (val < (*start_ref)->payload)
        {
            newNode->next = *start_ref;
            *start_ref = newNode;
        }
        else
        {
            itr = *start_ref;
            while (itr->next != NULL)
            {
                if (val < itr->next->payload)
                    break;
                itr = itr->next;
            }
            struct node *temp = itr->next;
            itr->next = newNode;
            newNode->next = temp;
        }
    }
    else if ((*start_ref != NULL) && (((*start_ref)->next) == NULL))
    {
        printf("\nonly one node\n");
        if (val >= (*start_ref)->payload)
        {
            newNode->next = NULL;
            (*start_ref)->next = newNode;
        }
        else
        {
            newNode->next = *start_ref;
            *start_ref = newNode;
        }
    }
    else
    {
        newNode->next = NULL;
        *start_ref = newNode;
    }
}

void deleteFromBegining(struct node **start_ref)
{
    if (*start_ref != NULL)
    {
        //struct node* temp;
        //temp = *start_ref;
        //temp = temp->next;
        //free(*start_ref);
        //*start_ref=temp;
        struct node *temp;
        temp = *start_ref;
        (*start_ref) = (*start_ref)->next;
        free(temp);
    }
    else
    {
        printf("\nList is empty nothing to delete\n");
    }
}

void insertInList(struct node **start_ref, int inputValue)
{
    struct node *itr;
    if (*start_ref != NULL)
    {
        itr = *start_ref;
        while (itr->next != NULL)
            itr = itr->next;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->payload = inputValue;
    newNode->next = NULL;
    if (*start_ref != NULL)
        itr->next = newNode;
    else
        *start_ref = newNode;
}

int main()
{
    struct node *start = NULL;
    int flag = 1;
    int choice;
    while (flag)
    {
        fflush(stdin);
        printf("\nEnter 1 for inserting, 2 for insert at begining, 3 for showing 4 delete from begining, 5 exit: ");
        scanf(" %d", &choice);
        if (choice == 1)//choices
        {
            int val;
            printf("\nEnter value: ");
            scanf("%d", &val);
            insertSorted(&start, val);
        }
        else if (choice == 2)
        {
            int val;
            printf("\nEnter value: ");
            scanf("%d", &val);
            insertAtBegining(&start, val);
        }
        else if (choice == 3)
        {
            printf("\nContents of the list are:\n");
            printList(start);//printing lists
        }
        else if (choice == 4)
        {
            deleteFromBegining(&start);
        }
        else if (choice == 5)
        {
            flag = 0;
        }
    }

    return 0;
}
