#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <float.h>

double input(void);

void checkInterval(const double a, const double b);

void checkStep(const double step);

double getFunction(double x);

double getElement(double x, int n);

double getSum(double x, const double epsilon);

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
	if (fabs(x) >= 1)
	{
		errno = EDOM;
		perror("Invalid input for log function!");
		exit(EXIT_FAILURE);
	}
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
		n++;
		element = getElement(x, n);
	}
	return sum;
}