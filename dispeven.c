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
        scanf("%d",&temp->data );

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
 struct node *trav ;
 trav=head;
 while (trav != NULL)
 {
    if (trav->data %2 == 0)
   { printf("%d \t", trav->data );
   }
    trav= trav->next;
 }
}
int main ()
{
create();
view();

return 0;
}