#include <stdio.h>

/**
* @brief Переводит значения массы из килограмм в унции
* @param x значение массы в кг
* @return возвращает рассчитаное значение
*/
double result(const double x);

/**
* @brief считывает вещесвтенное число
* @return возвращает вещественное число
*/
double input(void);

/**
* @brief точка входа в программу
* @return 0 в случае успеха
*/ 
int main(void)
{
	puts("Введите вес в килограммах");
	double x = input();
	printf("%lf", result(x));
	return 0;
}

double result(double x)
{
	const double ounce = 28.3;
	return x / ounce;
}

double input(void)
{
	double value = 0.0;
	scanf_s("%lf", &value);
	return value;
}
