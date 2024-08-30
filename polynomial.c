#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

Node* createNode(int coefficient, int exponent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->coefficient = coefficient;
    node->exponent = exponent;
    node->next = NULL;
    return node;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node** current = &result;

    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            *current = createNode(poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            *current = createNode(poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int coefficient = poly1->coefficient + poly2->coefficient;
            if (coefficient != 0) {
                *current = createNode(coefficient, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        current = &((*current)->next);
    }

    *current = poly1 ? poly1 : poly2;

    return result;
}

void printPolynomial(Node* poly) {
    while (poly) {
        printf("%dx^%d + ", poly->coefficient, poly->exponent);
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Node* poly1 = createNode(3, 2);
    poly1->next = createNode(2, 1);
    poly1->next->next = createNode(1, 0);

    Node* poly2 = createNode(2, 2);
    poly2->next = createNode(3, 1);
    poly2->next->next = createNode(4, 0);

    printf("Poly 1: ");
    printPolynomial(poly1);
    printf("Poly 2: ");
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);

    printf("Result: ");
    printPolynomial(result);

    return 0;
}