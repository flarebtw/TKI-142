#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

/**
* @brief Вычисляет значение первой функции
* @param x Значение переменной x
* @reutrn Возвращает значение первой функции
*/
double getFirst(const double x);

/**
* @brief Вычисляет значение второй функции
* @param x Значение переменной x
* @return Возвращает значение второй функции
*/
double getSecond(const double x);

/**
* @brief Считывает введенное вещественное значение
* @return Возвращает вещественное значение
*/
double input(void);

/**
* @brief точка входа в программу
* @return возвращает 0 в случае успеха
*/
int main(void) {
	puts("Enter x value:");
	double x = input();
	if (x < 2) 
	{
		printf("Function equals: %lf", getFirst(x));
	}
	else
	{
		printf("Function equals: %lf", getSecond(x));
	}
	return 0;
}

double getFirst(const double x) {
	return 1.5 * pow(cos(x), 2);
}

double getSecond(const double x) {
	return pow(x - 2, 2) + 6;
}

double input(void) {
	double value;
	int result = scanf_s("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Input error!\n");
		exit(EXIT_FAILURE);
	}
	return value;
}
