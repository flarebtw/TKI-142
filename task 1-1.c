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
* @param y - значение константы y
* @param z - значение константы z
* @param a - значение константы a
* @return рассчитанное значение
*/
double getB(const double y, const z, const double a);

/**
* @brief Точка входа в программу.
* @return 0, в случае успеха.
*/
int main()
{
	const double x = -0.5;
	const double y = 1.7;
	const double z = 0.44;
	const double a = getA(x, y, z);
	const double b = getB(y, z, a);
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return pow(exp(1), -y * z) * sin(x * z - y) - sqrt(abs(y * z + x));
}

double getB(const double y, const double z, const double a)
{
	return y * sin(a * pow(z, 2) * cos(2 * z)) - 1;
}