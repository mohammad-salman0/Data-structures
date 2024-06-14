#include<stdio.h>
void convert(int num );
int main ()
{
    int num ;
    printf("enter a number ");
    scanf("%d", &num);
    convert(num);
}
void convert(int num ){
    int r ;
    if(num<16)
    return ;
    else 
     r= num %16;
     convert(num /16);
     printf("%d", r); 
}