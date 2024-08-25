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
void delete ()
{
    int itm;
    printf("\n");
    printf("enter the item you want to delete :");
    scanf("%d", &itm);

    if(head ->data == itm)     //to delete the item if it exists at the head 
    {
    head = head ->next;
    return;
    }
    if(tail->data == itm)                               //to delete the item if it exists at the tail
    {
        struct node* trav = head ;
        while (trav ->next ->data != itm)
        {
            trav = trav->next;
        }
        trav->next ->next = NULL;
    }
    struct node * trav = head;
    while (trav ->next ->data != itm)  // as we have already checked head we start the condition 
    {                                   //from the second itm of the linked list
        trav= trav ->next;
    }                                 
    
    trav ->next= trav->next ->next;   // as trav is one step behind the node that we want to delete 
}
int main ()
{
create();
view();
delete();
view();

return 0;
}