#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculate.h"

double stack[MAX_SIZE];
int top = 0;

double make_calculate(double param, char *ch) {
    int i = 0;
    while (ch[i] != '\0') {
        if (ch[i] >= 48 && ch[i] <= 57) {
            char *num;
            num = malloc(15 * sizeof(char));
            fill_zero(num);
            int k = i;
            while ((ch[i] >= 48 && ch[i] <= 57) || ch[i] == '.') {
                num[i - k] = ch[i];
                i += 1;
            }
            num[i - k] = '.';
            pushs(atof(num));
            free(num);
        }
        if (ch[i] == 'x') {
            pushs(param);
        }
        for_math(ch[i]);
        i++;
    }
    return pops();
}

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double sinus(double a) {
    return sin(a);
}

double cosinus(double a) {
    return cos(a);
}

double tangens(double a) {
    return tan(a);
}

double cotangens(double a) {
    return cosinus(a) / sinus(a);
}

double sqr(double a) {
    double res;
    if (a > 0) {
        res = sqrt(a);
    } else {
        res = 999;
    }
    return res;
}

double lan(double a) {
    double res;
    if (a > 0) {
        res = log(a);
    } else {
        res = 999;
    }
    return res;
}

double pows(double a, double b) {
    return pow(a, b);
}

void pushs(double value) {
    stack[top++] = value;
}

double pops() {
    return stack[--top];
}

double uno(double a) {
    return a * (-1);
}

void fill_zero(char *arr) {
    for (int i = 0; i < 10; i++) {
        arr[i] = '0';
    }
}

void for_math(char a) {
    double n;
    double m;
    switch (a) {
        case '+':
            pushs(add(pops(), pops()));
            break;
        case '-':
            pushs(sub(pops(), pops()));
            break;
        case '*':
            pushs(mul(pops(), pops()));
            break;
        case '/':
            pushs(divide(pops(), pops()));
            break;
        case '^':
            n = pops();
            m = pops();
            pushs(pows(m, n));
            break;
        case 's':
            pushs(sinus(pops()));
            break;
        case 'c':
            pushs(cosinus(pops()));
            break;
        case 't':
            pushs(tangens(pops()));
            break;
        case 'g':
            pushs(cotangens(pops()));
            break;
        case 'q':
            pushs(sqr(pops()));
            break;
        case 'l':
            pushs(lan(pops()));
            break;
        case '~':
            pushs(uno(pops()));
            break;
    }
}
