#include<stdio.h>
struct node{
int data ;
struct node * next ;
};
int main (){
struct node n1 , n2 , n3;
n1.data = 10 ;
n2.data = 20 ;
n3.data = 30 ;

n1.next= &n2;
n2.next= &n3;
n3.next= NULL;
printf("the liked list so formed is as follows : %d %d %d",n1.data, n1.next->data , n1.next->next->data);
return 0 ;
}