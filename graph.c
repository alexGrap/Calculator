#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculate.h"
#include "decoding.h"

#define ROWS 25
#define COLS 80

char **malloc_matrix(int rows, int cols);
void free_matrix(char **matrix);

void draw(char **matrix);
void change(char **matrix, char *formul);

int main() {
    char **matrix;
    matrix = malloc_matrix(ROWS, COLS);
    char *formul;
    formul = make_rpn();
    change(matrix, formul);
    draw(matrix);
    free_matrix(matrix);
    free(formul);
    return 0;
}

void draw(char **matrix) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void change(char **matrix, char *formul) {
    double step_y = 2.0 / 24;
    double step_x = 4.0 * M_PI / 79;
    double dy = -1;
    for (int i = 0; i < ROWS; i++, dy += step_y) {
        double dx = 0;
        for (int j = 0; j < COLS; j++, dx += step_x) {
            double G = make_calculate(dx, formul);
            if ((G >= (dy - step_y / 2)) && (G <= (dy + step_y / 2))) {
                matrix[i][j] = '*';
            } else {
                matrix[i][j] = '.';
            }
        }
    }
}

char **malloc_matrix(int rows, int cols) {
    char **matrix = NULL;
    matrix = (char **)malloc(rows * sizeof(char *) + rows * cols * sizeof(char));
    char *pmatrix = (char *)(matrix + rows);
    for (int i = 0; i < cols; i++) matrix[i] = pmatrix + cols * i;
    return matrix;
}

void free_matrix(char **matrix) { free(matrix); }
