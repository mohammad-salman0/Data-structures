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
    char str4[500];
    int i =0 ;
    while (str1 [i] != '\0')
    {
        str4[i]=str1[i];
        i++; 
    }
    
    int j =0 ;
    while (str2[j] !='\0')
    {
        str4[i]= str2[j];
        i++;
        j++;
    }
    printf("the resulting string is ");
    puts(str4);

    }