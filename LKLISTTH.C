#include <stdio.h>
#include <conio.h>
#include <alloc.h>
typedef struct lklist
{
    int info;
    struct lklist *next;
} node;

void main()
{
    node *head = NULL;
    int ch;
    void insert_at_beg(node **);
    void insert_at_end(node **);
    void traverse(node *);
    clrscr();
    while (1)
    {
	printf("Enter 1 for Insertion at begining,2 for inserting at the end, 3 for travesing,4 for deletion\n");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
	{
	    insert_at_beg(&head);
	    traverse(head);
	    break;
	}
	case 2:
	{
	    insert_at_end(&head);
	    traverse(head);
	    break;
	}
	case 3:
	{
	    traverse(head);
	    break;
	}
	default:
	    printf("Wrong choice Entered\n");
	}

	printf("Do you want to continue press 1 else 0\n");
	scanf("%d", &ch);
	if (ch == 1)
	{
	    continue;
	}
	else
	{
	    exit();
	}
    }
}

void insert_at_beg(node **oldhead)
{
    int item;
    node *temp;
    node *tempfor_oldhead;
    temp = (node *)malloc(sizeof(node));
    printf("Enter new node's info\n");
    scanf("%d", &item);
    temp->info = item;
    if ((*oldhead) == NULL)
    {
	*oldhead = temp;
	temp->next = NULL;
    }
    else
    {
	tempfor_oldhead = (*oldhead);
	temp->next = tempfor_oldhead;
	tempfor_oldhead = temp;
    }
}

void insert_at_end(node **head)
{
    node *traverse = *head;
    int item;
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter new node's info\n");
    scanf("%d", &item);
    temp->next = NULL;
    temp->info = item;
    if (*head == NULL)
    {
	*head = temp;
    }
    else
    {
	while (traverse->next != NULL)
	{
	    traverse = traverse->next;
	}
	traverse->next = temp;
    }
}

void traverse(node *head)
{
    if (head == NULL)
    {
	printf("Empty linked list\n");
    }
    else
    {
	while (head != NULL)
	{
	    printf(" %d\n ", head->info);
	    head = head->next;
	}
    }
}
