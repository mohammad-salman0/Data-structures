#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

double stack[MAX_SIZE];
int top = -1;

void push(double value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push %f.\n", value);
        return;
    }
    stack[++top] = value;
}

double pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return 0.0;
    }
    return stack[top--];
}

double evaluatePostfix(char* expression) {
    char* token = strtok(expression, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            double operand2 = pop();
            double operand1 = pop();
            push(operand1 + operand2);
        } else if (strcmp(token, "-") == 0) {
            double operand2 = pop();
            double operand1 = pop();
            push(operand1 - operand2);
        } else if (strcmp(token, "*") == 0) {
            double operand2 = pop();
            double operand1 = pop();
            push(operand1 * operand2);
        } else if (strcmp(token, "^") == 0) {
            double operand2 = pop();
            double operand1 = pop();
            push(pow(operand1, operand2));
        } else {
            push(atof(token));
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char expression[] = "3 2 5 2 ^ * -";
    double result = evaluatePostfix(expression);
    printf("Result: %f\n", result);
    return 0;
}