#include <conio.h>
#include <stdio.h>
#include <alloc.h>
typedef struct lklist
{
int info;
struct lklist *next;
}node;

void main()
{
node *head = NULL;
int ch;
void Insertion_at_beg(node **);
void Insertion_at_end(node **);
void search_insertion(node **);
// void count_insertion(node **);
void deletion_at_end(node *);
void deletion_at_beg(node **);
void traverse(node *);
while (1)
{
clrscr();
printf("Enter 1 for Insertion_at_beg,2 for Insertion_at_end,3 for Insertion before an element in the node,4 insertion before a node and 5 for traverse,6 for deletion at end,7 for deletion at beg\n");
scanf("%d", &ch);
switch (ch)
{
case 1:
Insertion_at_beg(&head);
traverse(head);
break;
case 2:
Insertion_at_end(&head);
traverse(head);
break;
case 3:
search_insertion(&head);
traverse(head);
break;
//case 4:insert_after(&head);
//traverse(head);
//break;
case 5:
traverse(head);
break;
case 6:
if(head->next==NULL)
{
free(head);
printf("DELETED SUCCESSFULLY\n");
}
deletion_at_end(head);
traverse(head);
break;
case 7:
deletion_at_beg(&head);
traverse(head);
break;
default:
printf("Wrong choice entered\n");
}
printf("Do you want to continue, press 1 else 0\n");
scanf("%d", &ch);
if(ch == 0)
exit(1);
}
}

void Insertion_at_beg(node **start)
{
node *temp;
node *oldhead = *start;
temp = (node *)malloc(sizeof(node));
printf("Enter the info of new node\n");
scanf("%d", &temp->info);
if(*start == NULL)
{
*start = temp;
temp->next = NULL;
}
else
{
*start = temp;
temp->next = oldhead;
}
}

void Insertion_at_end(node **start)
{
node *temp;
node *loc = *start;
temp = (node *)malloc(sizeof(node));
printf("Enter the info of new node\n");
scanf("%d", &temp->info);
temp->next = NULL;
if(*start == NULL)
{
*start = temp;
}
else
{
while (loc->next != NULL)
{
loc= loc->next;
}
loc->next = temp;
}
}

void search_insertion(node **start)
{
int item;
int flag = 0;
node *temp;
node *traverse = *start;   // copy of head's address is created.
node *backfoot = traverse; // backpointer is pointing to head currently.
temp = (node *)malloc(sizeof(node));
if(*start==NULL)
{
printf("Empty list\n");
}
else
{
printf("Enter the new node's info\n");
scanf("%d", &temp->info);
printf("Enter the item in the node to add new node before it\n");
scanf("%d", &item);
// Searching the linked list.
if(traverse->info == item) // if first node is matched
{
*start=temp;
temp->next = traverse;   //correct hai
}
else // node may be after 1st node
{
while(traverse!=NULL)  //jbtk isko null na mille
{
traverse=traverse->next;      //pointing to next address.
if((traverse->info)==item)     //comparing
{
flag = 1;
temp->next=backfoot->next;
backfoot->next=temp;
}
backfoot=traverse;              //shifting backpointer.
}
if (flag == 1)
printf("Node successfully added \n");
else
printf("searched item not found\n");
}
}
}

void deletion_at_end(node *start)
{
node *temp=NULL;
if(start==NULL)
{
printf("List is already empty\n");
}
else
{
while((start->next)->next!=NULL)
{
start=start->next;
}
temp=start->next;
start->next=NULL;
free(temp);
}
}

void deletion_at_beg(node **start)
{
node *temp;
if(*start==NULL)
{
 printf("List is already empty\n");
}
else
{
if((*start)->next==NULL)
{
temp=*start;
*start=NULL;
free(temp);
}
else
{
temp=*start;
(*start)=(*(*start)).next;
free(temp);
}
printf("Deletion successful\n");
}
}

void traverse(node *loc)
{
if(loc==NULL)
printf("Empty list\n");
while (loc != NULL)
{
printf("------------------------------------------------------------------\n");
printf("%d\n", loc->info);
loc = loc->next;
}
}
