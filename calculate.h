#ifndef SRC_CALCULATE_H_
#define SRC_CALCULATE_H_

#define MAX_SIZE 100

void pushs(double value);
double pops();

double sinus(double a);
double cosinus(double a);
double tangens(double a);
double cotangens(double a);
double sqr(double a);
double lan(double a);
void for_math(char a);

double uno(double a);
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divide(double a, double b);
double pows(double a, double b);
double make_calculate(double x, char *string);
void fill_zero(char *arr);

#endif  // SRC_CALCULATE_H_
