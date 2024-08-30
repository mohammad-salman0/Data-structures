#include <stdio.h>

int main() {
    char str[100];
    int i, j, len;
    char temp;

    printf("Enter a string: ");
    scanf("%s", str); 

   
    for (len = 0; str[len] != '\0'; len++) {}

   
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}