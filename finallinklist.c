#include<stdio.h>
#include<stdlib.h>
struct node {
 int data ;
 struct node* next;
};
struct node * head = NULL;
struct node * tail =NULL;
void create()
{
    int size;
    struct node * temp;
    printf("enter the size of the linked list you want to create :\n");
    scanf("%d", &size);
    for (int i = 1 ; i <= size ; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("enter data :\n");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail= temp;
        }
        tail->next = temp;
        tail=temp;
    }
}
 void insert(){

    int item, element;
    printf("enter the item you want to add to the linked  list :\n");
    scanf("%d", &item );
    struct node * temp ;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item ;
    printf("enter the node after which you want to add the element: \n");
    scanf("%d", &element);

    struct node * trav = head ;
    
    while ( trav->data != element )
    {
        trav= trav->next;
    }
    temp->next= trav->next;
    trav->next = temp;
    if(trav== tail)
    {
        tail = temp;
    }
 }
 void view()
 {
    struct node * trav = head;
    while ( trav != NULL)
    {
        printf("%d\t", trav->data);
        trav= trav->next;
    }
    

 }
 void delete()
 {
    printf("enter the node you want to delete : \n");
    int node ;
    scanf("%d", &node);
    struct node *trav= head;
    struct node* prev = NULL;
    while (trav !=  NULL && trav->data == node)
    {
        head = trav->next;
        trav = head ;
    }
    trav = head ;
    prev = head ;
    

    while ( trav != NULL )
    {
        if ( trav->data == node)
        {
            if(trav== tail)
            {
                tail= prev;
            }
            prev->next= trav->next;
            trav=trav->next;
        }
        prev= trav;
        trav=trav->next;
    }
 }
 void insertbefore()
 {
    int  element, nd ;
    struct node * trav = head;
    struct node * prev;
    struct node * temp ;

    printf("enter the element you want to add :\n");
    scanf("%d", &element);
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;

    printf("enter the node before which you want to insert the element : \n");
    scanf("%d", &nd);
     
     if (head->data == nd)
     {
        temp->next = head;
        head= temp;
        return;
     }
     prev= head;
     trav = head->next;
     while(trav->data  != nd)
     {
        prev= trav;
        trav= trav->next;

     }
     temp->next= trav;
     prev->next= temp;
     

 }
int main ()
{
    int n ;
    while (1)
    {
        printf("\nfor creation of linked list press 1\nfor insertion of a node press 2 \nfor viewing the node press 3 \nfor deletion of the node press 4 \nto exit the loop press 5\nto insert an element before an node press 6\n");
        scanf("%d", &n);

        if(n ==1 )
        create();

        if (n==2)
        insert();

        if(n==3)
        view();
        
        if(n==4)
        delete();
        
        if(n==5)
        break;

        if(n==6)
        insertbefore();
    }
}