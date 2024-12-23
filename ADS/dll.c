
#include<stdio.h>
#include<stdlib.h>

int count = 0;

struct node {
    int data;
    struct node* prev;  // New: previous pointer
    struct node* next;
};

struct node* start = NULL;

void create();
void insb();
void inse();
void insp();
void delb();
void dele();
void delp();
void display();
void displayReverse();  // New: display in reverse order

int main()
{
    int ch;
    while (1)
    {
        printf("\n1. Creation\n2. Insert at beginning \n3. Insert at end \n4. Insert at position \n");
        printf("5. Delete from beginning \n6. Delete from end \n7. Delete from position \n8. Display \n9. Display Reverse \n10. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                create();
                break;
            case 2:
                insb();
                break;
            case 3:
                inse();
                break;
            case 4:
                insp();
                break;
            case 5:
                delb();
                break;
            case 6:
                dele();
                break;
            case 7:
                delp();
                break;
            case 8:
                display();
                break;
            case 9:
                displayReverse();
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}

void create() 
{
    int n, item, i = 0;
    struct node *ptr, *temp;

    if (count == 0) 
    {
        printf("\nEnter the number of nodes to be inserted: ");
        scanf("%d", &n);

        if (n == 0)
        {
            printf("\nNo nodes to create.");
            return;
        }

        while (i < n)
        {
            printf("\nEnter value to insert: ");
            scanf("%d", &item);

            ptr = (struct node*) malloc(sizeof(struct node));
            ptr->data = item;
            ptr->prev = NULL;  // New
            ptr->next = NULL;

            if (count == 0) 
            {
                start = ptr;
                temp = start;
            }
            else 
            {
                temp->next = ptr;
                ptr->prev = temp;  // New
                temp = temp->next;
            }

            count++;
            i++;
        }
    } 
    else 
    {
        printf("\nList already created.");
    }
}

void insb()
{
    int data;
    struct node* ptr;

    printf("\nEnter value to insert: ");
    scanf("%d", &data);

    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;  // New

    if (start == NULL) 
    {
        start = ptr;
        start->next = NULL;
    } 
    else 
    {
        ptr->next = start;
        start->prev = ptr;  // New
        start = ptr;
    }
    count++;
}

void inse() 
{
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node));

    printf("\nEnter value: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = NULL;

    if (start == NULL) 
    {
        ptr->prev = NULL;  // New
        start = ptr;
    } 
    else 
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;  // New
    }
    count++;
    printf("\nNode inserted.");
}

void insp() {
    int item, pos, i;
    struct node *ptr, *temp;

    printf("\nEnter value: ");
    scanf("%d", &item);
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) 
    {
        printf("\nInvalid position!");
        return;
    }

    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = item;

    if (pos == 1) 
    {
        ptr->prev = NULL;  // New
        ptr->next = start;
        if (start != NULL)
            start->prev = ptr;  // New
        start = ptr;
    } 
    else 
    {
        temp = start;
        for (i = 1; i < pos - 1; i++) 
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        ptr->prev = temp;  // New
        if (temp->next != NULL)
            temp->next->prev = ptr;  // New
        temp->next = ptr;
    }
    count++;
    printf("\nNode inserted.");
}

void delb() {
    struct node* temp;

    if (start == NULL) 
    {
        printf("\nList is empty.");
    } 
    else
    {
        temp = start;
        start = temp->next;
        if (start != NULL)
            start->prev = NULL;  // New
        free(temp);
        count--;
        printf("\nNode deleted.");
    }
}

void dele() {
    struct node *temp;

    if (start == NULL) 
    {
        printf("\nList is empty.");
    } 
    else if (start->next == NULL)
    {
        temp = start;
        start = NULL;
        free(temp);
        count--;
        printf("\nNode deleted.");
    } 
    else 
    {
        temp = start;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;  // New
        free(temp);
        count--;
        printf("\nNode deleted.");
    }
}

void delp() 
{
    struct node *temp;
    int pos, i;

    if (start == NULL) 
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
    {
        printf("\nInvalid position!");
        return;
    }

    if (pos == 1) 
    {
        temp = start;
        start = temp->next;
        if (start != NULL)
            start->prev = NULL;  // New
        free(temp);
    } 
    else 
    {
        temp = start;
        for (i = 1; i < pos; i++) 
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;  // New
        if (temp->next != NULL)
            temp->next->prev = temp->prev;  // New
        free(temp);
    }
    count--;
    printf("\nNode deleted.");
}

void display() 
{
    struct node* ptr;

    if (start == NULL) 
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nList: ");
    ptr = start;
    while (ptr != NULL) 
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void displayReverse() 
{
    struct node* ptr;

    if (start == NULL) 
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nReverse List: ");
    ptr = start;
    while (ptr->next != NULL) 
    {
        ptr = ptr->next;
    }
    while (ptr != NULL) 
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}
