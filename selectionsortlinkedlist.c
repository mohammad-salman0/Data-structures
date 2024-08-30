#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertNode(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void selectionSort() {
    Node* current = head;
    Node* minNode;
    int temp;

    while (current != NULL) {
        minNode = current;
        Node* nextNode = current->next;

        while (nextNode != NULL) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        if (minNode != current) {
            temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }

        current = current->next;
    }
}


void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    
    insertNode(5);
    insertNode(2);
    insertNode(8);
    insertNode(3);
    insertNode(1);
    insertNode(6);
    insertNode(4);

    printf("Original list: ");
    printList();

    selectionSort();

    printf("Sorted list: ");
    printList();

    return 0;
}