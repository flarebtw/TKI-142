#include <stdio.h>
#include <math.h>

/**
* @brief ������������ ��������� � �� �������
* @param x - �������� ��������� �
* @param y - �������� ��������� y
* @param z - �������� ��������� z
* @return ������������ ��������
*/
double getA(const double x, const double y, const double z);

/**
* @brief ������������ ��������� b �� �������
* @param y - �������� ��������� y
* @param z - �������� ��������� z
* @param a - �������� ��������� a
* @return ������������ ��������
*/
double getB(const double y, const z, const double a);

/**
* @brief ����� ����� � ���������.
* @return 0, � ������ ������.
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