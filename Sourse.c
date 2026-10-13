#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h> 

void printInitialValues(char c, int i, float f, double d);
void inputValues(char* c, int* i, float* f, double* d);
void task1a_splitFloat(float f);
void task1b_charCodes(char c);
void task1v_inverseInt(int i);

void task2_implicitConversion(int a, int b);
void task2_explicitConversion(int a, int b);

void inputNumber(int* n);
void processNumberDigits(int n);

int main()

{
	system("chcp 1251");
	setlocale(LC_CTYPE, "RUS");

	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;
	
	inputValues(&c, &i, &f, &d);
	printInitialValues(c, i, f, d);
    task1a_splitFloat(f);
    task1b_charCodes(c);
    task1v_inverseInt(i);

    int a = 11;
    int b = 3;
    task2_implicitConversion(a, b);
    task2_explicitConversion(a, b);

    int n = 0;
    inputNumber(&n);
    processNumberDigits(n);

	return 0;

}

void printInitialValues(char c, int i, float f, double d)
{
	printf("char c   = %c\n", c);
	printf("int i    = %d\n", i);
	printf("float f  = %f\n", f);
	printf("double d = %e\n\n", d);
}

void inputValues(char* c, int* i, float* f, double* d) {
    printf("Введите символ char: ");
    scanf(" %c", c);
    printf("Введите целое число int: ");
    scanf("%d", i);
    printf("Введите вещественное число float: ");
    scanf("%f", f);
    printf("Введите вещественное число double: ");
    scanf("%lf", d);
}

void task1a_splitFloat(float f) {
    int int_part = (int)f;
    float float_part = f - int_part;
    printf("Целая часть = %d, дробная часть = %f\n", int_part, float_part);
}

void task1b_charCodes(char c) {
    printf("Десятичное число = %d, шестнадцатиричное число = 0x%X\n", c, c);
}

void task1v_inverseInt(int i) {
    if (i != 0) {
        double result = 1.0 / i;
        printf("%f\n", result);
    }
    else {
        printf("Ошибка\n");
    }
}

void task2_implicitConversion(int a, int b) {
    int x;
    float y;
    double z;
    x = a / b;
    y = a / b;
    z = a / b;
    printf("x = %d\n", x);
    printf("%f\n", y);
    printf("z = %lf\n\n", z);
}

void task2_explicitConversion(int a, int b) {
    printf("%f\n", (float)a / b);
    printf("%lf\n", (double)a / b);
}

void inputNumber(int* n) {
    printf("Введите целое трехзначное число: ");
    scanf("%d", n);
}

void processNumberDigits(int n) {
    int abs_n = abs(n);
    int last_digit = abs_n % 10;
    int middle_digit = (abs_n / 10) % 10;
    int first_digit = abs_n / 100;
    int sum = first_digit + middle_digit + last_digit;
    int reversed = last_digit * 100 + middle_digit * 10 + first_digit;
    if (n < 0) {
        reversed = -reversed;
    }
    printf("Последняя цифра %d, первая - %d, сумма цифр %d, перевернутое число %d\n",
        last_digit, first_digit, sum, reversed);
}