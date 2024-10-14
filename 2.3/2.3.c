#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
* @brief Считывает вещественное значение
* @return Возвращает вещественное значение
*/
double input(void);

/**
* @brief Рассчитывает время до привала
* @param v1 t1 скорость и время на первом участке пути
* @param v2 t2 скорость и время на втором участке пути
* @param v3 t3 скорость и время на третьем участке пути
* @return Возвращает время затраченное на половину пути
*/
double getTime(const double v1, const double v2, const double v3, const double t1, const double t2, const double t3);

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void)
{
	puts("Enter speed and time for first part");
	const double v1 = input();
	const double t1 = input();
	puts("Enter speed and time for second part");
	const double v2 = input();
	const double t2 = input();
	puts("Enter speed and time for third part");
	const double v3 = input();
	const double t3 = input();
	printf("Time before break %lf", getTime(v1, v2, v3, t1, t2, t3));
	return 0;
}

double input(void)
{
	double value = 0.0;
	int result = scanf_s("%lf", &value);
	if (result != 1 || value < 0)
	{
		errno = EIO;
		perror("Input error!");
		exit(EXIT_FAILURE);
	}
	return value;
}

double getTime(const double v1, const double v2, const double v3, const double t1, const double t2, const double t3)
{
	double s1 = v1 * t1;
	double s2 = v2 * t2;
	double s3 = v3 * t3;
	double wholepath = s1 + s2 + s3;
	double halfpath = wholepath / 2;
	if (halfpath < s1)
	{
		return halfpath / v1;
	}
	halfpath = halfpath - s1;
	if (halfpath < s2)
	{
		return t1 + (halfpath / v2);
	}
	halfpath = halfpath - s2;
	if (halfpath < s3)
	{
		return t1 + t2 + (halfpath / v3);
	}
	return t1 + t2 + t3;
}