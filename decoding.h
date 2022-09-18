#ifndef SRC_DECODING_H_
#define SRC_DECODING_H_

typedef struct st {
    char symbol;
    struct st *next;
} Stack;

Stack *push(Stack *root, char a);
char pop(Stack **root);
int priority(char a);
void work_with_math(char *input, char *result, int k, int *point, Stack *root);
char *make_rpn();
int check_uno(const char *arr, int k);
void checkOp(char *input, char *result, Stack **root, int k, int *point);

#endif  // SRC_DECODING_H_
