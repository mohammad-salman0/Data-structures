#include<stdio.h>
#include<stdlib.h>
struct node{

int data ;
struct node * next ;

};

struct node *head = NULL;
struct node *tail = NULL;

void create()
{
    int n ;
    struct node * temp ;
    printf ("enter the size of linked list ");
    scanf("%d", &n);

    for (int i =1 ; i <= n ; i++)
    {
        temp = (struct node *) malloc(sizeof(struct node));

        printf("enter data :");
        scanf("%d", &temp->data );

        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else 
        {
            tail->next = temp;
            tail = temp;
        }
    }
}
void view ()
{
 struct node *trav;
 trav = head;
 while(trav != NULL)
 {
 printf("%d \t",trav->data );
 trav= trav->next;
 }
}
void insert()
{
    struct node* trav = head;
    struct node* temp;

    temp = (struct node *)malloc(sizeof(struct node));
    int item ; 
    int node;

    printf("\n");

    printf("enter the element you want to insert :\n");
    scanf("%d", &temp->data);

    printf("enter the node after which you want to insert the element :\n");
    scanf("%d", &node);

    while ( trav != NULL && trav->data != node  )     //alt condition (trav ->data ! = node)
    {
        trav= trav->next;
    }

    if ( trav == NULL)    //corner condition if the node after which the user wants to add the node is not found
    {
        printf("no node with the same value has been found in the linked list\n");
        
        return ;
    }

    temp->next = trav->next;   // main insertion code
    trav->next = temp;
}
int main ()
{
create();
view();
insert();
view();

return 0;
}