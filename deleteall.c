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

    struct node* trav = head;
    struct node* prev= NULL;

    while( trav  != NULL && trav->data == itm)         //code to delete an item present at head 
    { head = trav->next;          //main deletion code
    free(trav);  //optional 
    trav = head;                    //to check wether the element to be deleted is again present at the head or not 
    }
      
    trav= head ;    //initialisation for  the nxt loop which helps us to delete elements present elsewhere inside
    prev= head ;    //the list 

    while (trav != NULL)
    {
        if ( trav->data == itm)
        {
            if (trav == tail)
            {
                tail = prev;            
            }

         prev -> next = trav->next ;     //to delete the element which is currently present in trav
         trav= trav-> next ;           //to check the next element 
                                        //we update trav to move further inside the ll
        
        }
        else
        {
        prev= trav;                 //if the present configuration of prev and trav dosen't contain the element we
        trav= trav->next ;          //we want to delete we move further inside the ll
        }
    
   
    }
}  
int main ()
{
create();
view();
delete();
view();

return 0;
}