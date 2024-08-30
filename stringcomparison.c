#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i, len1, len2;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    
    for (len1 = 0; str1[len1] != '\0'; len1++) {}

    for (len2 = 0; str2[len2] != '\0'; len2++) {}

    
    if (len1 != len2) {
        printf("The strings are not equal");
        return 0;
    }

   
    int are_equal = 1;
    for (i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            are_equal = 0;
            break;
        }
    }

    if (are_equal) {
        printf("The strings are equal");
    } else {
        printf("The strings are not equal");
    }

    return 0;
}