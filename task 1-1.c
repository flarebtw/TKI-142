#include <stdio.h>
#include <math.h>

/**
* @brief рассчитывает выражение а по формуле
* @param x - значение константы х
* @param y - значение константы y
* @param z - значение константы z
* @return рассчитанное значение
*/
double getA(const double x, const double y, const double z);

/**
* @brief рассчитывает выражение b по формуле
* @param x - значение константы x
* @param y - значение константы y
* @param z - значение константы z
* @return рассчитанное значение
*/
double getB(const double x, const double y, const double z);

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main(void)
{
	const double x = -0.5;
	const double y = 1.7;
	const double z = 0.44;
	printf("a = %f\n", getA(x, y, z));
	printf("b = %f\n", getB(x, y, z));
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return exp(- y * z)* sin(x * z - y) - sqrt(fabs(y * z + x));
}

double getB(const double x, const double y, const double z)
{
	return y * sin(getA(x, y, z) * pow(z, 2) * cos(2 * z)) - 1;
}