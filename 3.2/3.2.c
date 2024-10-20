#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

double input(void);

int inputInt(void);

void checkQuantity(int quantity);

double nextElement(double previousElement, int k);

double getNSum(const int n);

double getSumNotLessThanE(const int n, const double e);

int main(void)
{
	puts("Enter number of sequence elements:");
	const int n = inputInt();
	puts("Enter e value:");
	const double e = input();
	printf("Sum of N elements = %.3lf\n", getNSum(n));
	printf("Sum of all elements not less than e = %.3lf\n", getSumNotLessThanE(n, e));
	return 0;
}

double input(void)
{
	double value = 0.0;
	int result = scanf("%lf", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("Input error!");
		exit(EXIT_FAILURE);
	}
	return value;
}

int inputInt(void)
{
	int quantity = 0;
	int result = scanf("%d", &quantity);
	if (result != 1)
	{
		errno = EIO;
		perror("Input Error!");
		exit(EXIT_FAILURE);
	}
	checkQuantity(quantity);
	return quantity;
}

void checkQuantity(int quantity)
{
	if (quantity < 0)
	{
		errno = EIO;
		perror("Value cannot be lower than zero!");
		exit(EXIT_FAILURE);
	}
}

double nextElement(double previousElement, int k)
{
	return  previousElement * (pow(k, 4) / k);
}

double getNSum(const int n)
{
	double sum = 0.0;
	double Element = 1.0;
	for (int k = 1; k <= n; ++k)
	{
		if (k > 1) {
			Element = nextElement(Element, k);
		}
		sum += Element;
	}
	return sum;
}

double getSumNotLessThanE(const int n, const double e)
{
	double sum = 0.0;
	double Element = 1.0;
	for (int k = 1; k <= n; ++k)
	{
		if (k > 1)
		{
			Element = nextElement(Element, k);
		}
		
		if (Element >= e)
		{
			sum += Element;
		}
	}
	return sum;
}