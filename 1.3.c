#include <stdio.h>

/**
* @brief Рассчитвает значение работы силы тока
* @param I числовое значение силы тока
* @param U числовое значение напряжения 
* @param t числовое значение времени
* @return Возвращает рассчитаное значение работы силы тока
*/
double getA(const double I, const double U, const double t);

/**
* @brief считывает вещественное число
* @return возвращает вещественное число
*/
double input(void);

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void)
{
	puts("Enter I");
	double I = input();
	puts("Enter U");
	double U = input();
	const double t = 1200;
	printf("A = %lf", getA(I, U, t));
	return 0;
}

double getA(const double I, const double U, const double t)
{
	return I * U * t;
}

double input(void)
{
	double value = 0.0;
	scanf_s("%lf", &value);
	return value;
}