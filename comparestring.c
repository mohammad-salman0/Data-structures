#include<stdio.h>
#include<string.h>
int main ()
{
    char str1 [100];
    char str2 [100];
    printf("enter ist string \n");
    gets(str1);
    printf("enter second string \n");
    gets(str2);
    printf("the 1st string that you enteres is as follows \n");
    puts(str1);
    printf("the second string that you enteres is as follows \n");
    puts(str2);
    int i , j, count1, count2 ;
    i = 0;
    j=0;
    count1= 0;
    count2= 0;
   while(str1[i] != '\0'){
    
    count1 ++;
    i++; 
   }
   printf("the length of the ist stirng is %d \n", count1);
   while(str2[j] != '\0'){
    
    count2 ++;
    j++; 
   }
   int flag= 0;
   printf("the length of the second string is %d \n", count2);
   for (int k = 0 ,l= 0 ; k < count1-1 , l <count2-1 ;  k++ , l++)

   { if (str1[k] != str2[l])
   {
    flag++;
   printf("strings are not equal \n");
   break;
   }
   
}
if(flag== 0)
printf("both the strings are equal  \n ");

}