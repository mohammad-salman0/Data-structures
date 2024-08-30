
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node** current = &mergedList;


    while (list1!= NULL && list2!= NULL) {
        if (list1->data < list2->data) {
            *current = list1;
            list1 = list1->next;
        } else {
            *current = list2;
            list2 = list2->next;
        }
        current = &((*current)->next);
    }

    *current = (list1!= NULL)? list1 : list2;

    return mergedList;
}

void printList(struct Node* head) 
{
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
