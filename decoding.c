#include <stdio.h>
#include <stdlib.h>
#include "decoding.h"


char *make_rpn() {
    Stack *root = NULL;
    char input[100];
    char *result;
    result = malloc(200 * sizeof(char));
    int k = 0, point = 0;
    printf("Input formul at infix form: ");
    scanf("%99s", input);
    while (input[k] != '\0') {
        if (input[k] == ')') {
            while ((root -> symbol) != '(')
                result[point++] = pop(&root);
            pop(&root);
        }
        if ((input[k] >= 48 && input[k] <= 57) || input[k] == '.' || input[k] == 'x') {
            result[point++] = input[k];
            if ((input[k + 1] < 48 || input[k+1] > 57) && input[k + 1] != '.') {
                result[point++] = ' ';
            }
        }
        if (input[k] == '(') {
            root = push(root, '(');
        }
        checkOp(input, result, &root, k, &point);
        k++;
    }
    while (root != NULL) {
        char a = pop(&root);
        result[point++] = a;
    }
    result[point] = '\0';
    return result;
}

Stack *push(Stack *root, char a) {
    Stack *tmp;
    tmp = malloc(sizeof(Stack));
    tmp -> symbol = a;
    tmp -> next = root;
    return tmp;
}

char pop(Stack **root) {
    Stack *tmp;
    char a;
    if (*root == NULL) {
        a = '\0';
    } else {
        tmp = *root;
        a = tmp -> symbol;
        *root = tmp -> next;
        free(tmp);
    }
    return a;
}

int priority(char a) {
    int flag;
    switch (a) {
        case '*':
        case '/':
            flag = 3;
            break;
        case '-':
        case '+':
            flag = 2;
            break;
        case '(':
            flag = 1;
            break;
        case 's':
        case 'c':
        case 't':
        case 'q':
        case 'l':
        case ' ':
        case 'g':
            flag = 4;
            break;
        case '~':
            flag = 5;
            break;
        case '^':
            flag = 6;
            break;
    }
    return flag;
}

int check_uno(const char *arr, int k) {
    int flag = 0;
    if (arr[k] == '-' && arr[k - 1] != 'x' && arr[k - 1] != ')' &&
    (arr[k - 1] < 48 || arr[k - 1] > 57) &&
    (arr[k + 1] == '(' || (arr[k + 1] >= 48 && arr[k + 1] <= 57) ||
     arr[k + 1] == 'x' || arr[k + 1] == 's' || arr[k + 1] == 't' ||
     arr[k + 1] == 'c' || arr[k + 1] == 'l')) {
        flag = 1;
    }
    return flag;
}

void checkOp(char *input, char *result, Stack **root, int k, int *point) {
    if (input[k] == '+' || input[k] == '-' || input[k] == '/' || input[k] == '*' ||
    input[k] == '^' || input[k] == 's' || input[k] == 'c' || input[k] == 't' ||
    input[k] == 'l') {
        char pul = input[k];
        if (input[k] == 'c' && input[k+1] == 't' && input[k+2] == 'g') {
            pul = 'g';
        } else if (input[k] == 's' && input[k+1] == 'q' && input[k+2] == 'r' && input[k+3] == 't') {
            pul = 'q';
        }
        if (*root == NULL) {
            if (check_uno(input, k)) {
                *root = push(*root, ' ');
                *root = push(*root, '~');
            } else {
                *root = push(*root, ' ');
                *root = push(*root, pul);
            }
        } else {
            if (priority((*root) -> symbol) < priority(pul)) {
                if (check_uno(input, k)) {
                    *root = push(*root, ' ');
                    *root = push(*root, '~');
                } else {
                    *root = push(*root, ' ');
                    *root = push(*root, pul);
                }
            } else {
                while (((*root) != NULL) && (priority((*root) -> symbol) >= priority(pul)))
                    result[(*point)++] = pop(root);
                if (check_uno(input, k)) {
                    *root = push(*root, ' ');
                    *root = push(*root, '~');
                } else {
                    *root = push(*root, ' ');
                    *root = push(*root, pul);
                }
            }
        }
    }
}
