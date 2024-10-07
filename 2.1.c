#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
 * @brief Определяет константы
 * @return Возвращает их значения
 */
void determinant(void);

/**
 * @brief Проверка полученного вещественного значения
 * @return Возвращает проверенное вещественное число
 */
double inputDouble(void);

/**
 * @brief Проверка полученного целого значения
 * @return Возвращает полученное целое значение
 */
int inputInt(void);

/**
* @brief Рассчитывает значение периметра по данным сторонам
* @param x значение ширины
* @param y значение длины
* @return Возвращает значение периметра
*/
double getPer(double const x, double const y);

/**
* @brief Рассчитывает значение площади по данным сторонам
* @param x значение ширины
* @param y значение длины
* @return Возвращает значение площади
*/
double getArea(double const x, double const y);

/**
* @brief Рассчитвает значение диагонали по данным сторонам
* @param x значение ширины 
* @param y значение длины
* @return Возвращает значение диагонали
*/
double getDiagonal(double const x, double const y);

/**
* @param perimeter периметр прямоугольника
* @param area площадь прямоугольника
* @param diagonal диагональ прямоугольника
*/
enum request{perimeter, area, diagonal};

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void)
{
	double const x = inputDouble();
	double const y = inputDouble();
	determinant();
	int re = inputInt();
	switch (re)
	{
	case perimeter:
		printf("Perimeter of rectangle = %.2lf\n", getPer(x, y));
		break;
	case area:
		printf("Area of the rectangle = %.2lf\n", getArea(x, y));
		break;
	case diagonal:
		printf("Diagonal of the rectangle = %.2lf\n", getDiagonal(x, y));
		break;
	default:
		errno = ERANGE;
		perror("Function does not exist\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}

void determinant(void)
{
	printf("Perimeter - %d\n", perimeter);
	printf("Area - %d\n", area);
	printf("Diagonal - %d\n", diagonal);
}

double inputDouble(void)
{
	double value = 0.0;
	int result = scanf_s("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Input error\n");
		exit(EXIT_FAILURE);
	}
	return value;
}

int inputInt(void)
{
	int c = 0;
	int check = scanf_s("%d", &c);
	if (check != 1)
	{
		errno = EIO;
		perror("Input error\n");
		exit(EXIT_FAILURE);
	}
	return c;
}

double getPer(double const x, double const y)
{
	return 2 * (x + y);
}

double getArea(double const x, double const y)
{
	return x * y;
}

double getDiagonal(double const x, double const y)
{
	return sqrt(x * x + y * y);
}