#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <float.h>

/**
* @brief Считывает введенное значение
* @return Возвращает введенное значение
*/
double input(void);

/**
* @brief Проверяет правильность введенных значений интервала
* @param a начало интервала
* @param b конец интервала
* @return Возвращает ошибку, если введен некорректный интервал
*/
void checkInterval(const double a, const double b);

/**
* @brief Проверяет правильность введенного значения шага
* @param step величина шага
* @return Возвращает ошибку, если введен некорректный шаг
*/
void checkStep(const double step);

/**
* @brief Вызвает функцию
* @param x значение переменной x
* @return Возвращает значение функции если нет деления на нуль, в ином случае вызывает ошибку
*/
double getFunction(const double x);

/**
* @brief Рассчитывает значение следующего элемента последовательности
* @param x значение переменной
* @param n текущий индекс элемента последовательности
* @return Возвращает значение следующего элемента последовательности
*/
double getElement(const double x, int n);

/**
* @brief Рассчитывает значение суммы n членов
* @param x значение переменной
* @param epsilon значение величины с точностью которой следует вычислить значение суммы членов последовательности
* @return Возвращает значение суммы n членов последовательности
*/
double getSum(double x, const double epsilon);

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void)
{
	const double epsilon = pow(30, -5);
	puts("Enter interval value:");
	const double a = input();
	const double b = input();
	checkInterval(a, b);
	puts("Enter step value:");
	const double step = input();
	checkStep(step);
	for (double x = a; x <= b + DBL_EPSILON; x += step)
	{
		if ((x) >= 1)
		{
			errno = EDOM;
			perror("Invalid input for log function!");
		}
		printf("\nx = %.2f\tf(x) = %.6f\t\tS(x) = %.6f\n", x, getFunction(x), getSum(x, epsilon));
	}
	return 0;
}

double input(void)
{
	double value = 0.0;
	int result = scanf_s("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Input error!");
		exit(EXIT_FAILURE);
	}
	return value;
}

void checkInterval(const double a, const double b)
{
	if (b - a < DBL_EPSILON)
	{
		errno = EINVAL;
		perror("Interval input error!");
		exit(EXIT_FAILURE);
	}
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		errno = EINVAL;
		perror("Step input error!");
		exit(EXIT_FAILURE);
	}
}

double getFunction(double x)
{
	return (0.25 * log((1 + x) / (1 - x))) + (0.5 * atan(x));
}

double getElement(double x, int n)
{
	return (pow(x, (4 * n + 1)) / (4 * n + 1));
}

double getSum(double x, const double epsilon)
{
	double element = getElement(x, 0);
	double sum = 0.0;
	int n = 0;
	while (fabs(element) > epsilon)
	{
		sum += element;
		element = getElement(x, n);
		n++;
	}
	return sum;
}