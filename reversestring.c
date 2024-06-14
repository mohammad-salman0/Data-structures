#include<stdio.h>
#include<string.h>
int main ()
    {

char str1 [100];
    char str2 [100];
    printf("enter ist string \n");
    gets(str1);
    printf("the 1st string that you entered is as follows \n");
    puts(str1);
    int i= 0; 
    int count = 0;
    while (str1[i] !='\0')
    {
        i++;
        count++;
    }
    int j= 0;
    for(int k = count; k >= 0; k--)
   { str2[j]= str1[k];
    j++;
    
    }
    j--;
    printf("%d",j);
    printf("the reversed string is ");
    puts(str2);
    }