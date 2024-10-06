#include <stdio.h>

/**
* @brief Переводит значения массы из килограмм в унции
* @param x значение массы в кг
* @return возвращает рассчитаное значение
*/
double result(double x);

/**
* @brief точка входа в программу
* @return 0 в случае успеха
*/
int main(void)
{
	double x;
	puts("Введите вес в килограммах");
	scanf_s("%lf", &x);
	printf("%lf", result(x));
	return 0;
}

double result(double x)
{
	const double ounce = 28.3;
	return x / ounce;
}