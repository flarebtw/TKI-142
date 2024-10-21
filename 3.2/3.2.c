#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

/**
* @brief Считывает введенное значение
* @return Возвращает считанное значение
*/
double input(void);

/**
* @brief Считывает введеное целое значение
* @return Возвращает считанное значение
*/
int inputInt(void);

/**
* @brief Прооверяет неотрицательность введенного значения
* @param quantity введенное значение
* @return Возвращает ошибку, если значение меньше нуля
*/
void checkQuantity(const int quantity);

/**
* @brief Рассчитывает значение следующего элемента последовательности
* @param previousElement значение предыдущего элемента последовательности
* @param k текущий индекс последовательности
* @return Возвращает значение следующего элемента последовательности
*/
double nextElement(const double previousElement, const int k);

/**
* @brief Рассчитывает значение суммы n членов
* @param n Количество членов последовательности
* @return Возвращает значение суммы n членов последовательности
*/
double getNSum(const int n);

/**
* @brief Рассчитывает значение суммы всех членов последовательности, не меньших заданного числа e
* @param n Количество членов последовательности
* @param e Заданное число
* @return Возвращает значение суммы всех членов последовательности
*/
double getSumNotLessThanE(const double e);

/**
* @brief Точка входа в программу
* @return В случае успеха, возвращает 0
*/
int main(void)
{
	puts("Enter number of sequence elements:");
	const int n = inputInt();
	puts("Enter e value:");
	const double e = input();
	printf("Sum of N elements = %.3lf\n", getNSum(n));
	printf("Sum of all elements not less than e = %.3lf\n", getSumNotLessThanE(e));
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

int inputInt(void)
{
	int quantity = 0;
	int result = scanf_s("%d", &quantity);
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

double nextElement(const double previousElement, const int k)
{
	return  previousElement * (pow(k, 4) / k);
}

double getNSum(const int n)
{
	double sum = 0.0;
	double Element = 1.0; // Первый член последовательности равен 1^4/1! = 1
	for (int k = 1; k <= n; ++k)
	{
		Element = nextElement(Element, k);
		sum += Element;
	}
	return sum;
}

double getSumNotLessThanE(const double e)
{
	double sum = 0.0;
	double Element = 1.0; // Первый член последовательности равен 1^4/1! = 1
	int k = 1;
	while (Element >= e) 
	{
		sum += Element;
		k++;
		Element = nextElement(Element, k);
	}
	return sum;
}
