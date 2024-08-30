


#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i, j, len1, len2;

    printf("Enter the first string: ");
    scanf("%s", str1); 

    printf("Enter the second string: ");
    scanf("%s", str2);

    
    for (len1 = 0; str1[len1]!= '\0'; len1++) {}

    
    for (len2 = 0; str2[len2]!= '\0'; len2++) {}

    
    for (i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }

    
    str1[len1 + len2] = '\0';

    printf("Concatenated string: %s\n", str1);

    return 0;
}