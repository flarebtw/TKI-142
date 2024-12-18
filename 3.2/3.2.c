#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <float.h>

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
 * @brief Проверяет неотрицательность вещественного значения
 * @param value введеное значение 
 * @return Возвращает ошибку, если введеное значение не положительно
 */
void checkValue(const double value);

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
	checkValue(value);
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

void checkQuantity(const int quantity)
{
	if (quantity < 0)
	{
		errno = EIO;
		perror("Value cannot be lower than zero!");
		exit(EXIT_FAILURE);
	}
}

void checkValue(const double value)
{
	if(value < 0)
	{
		errno = EIO;
		perror("Value cannot be lower than zero!");
		exit(EXIT_FAILURE);
	}
}

double nextElement(const double previousElement, const int k)
{
	return  previousElement * -1 * (pow((k + 1), 4) / ((k + 1) * pow(k, 4)));
}

double getNSum(const int n)
{
	double element = 1.0; // Первый член последовательности равен 1^4/1! = 1
	double sum = element;
	for (int k = 1; k < n; ++k)
	{
		element = nextElement(element, k);
		sum += element;
	}
	return sum;
}

double getSumNotLessThanE(const double e)
{
	double element = 1.0; // Первый член последовательности равен 1^4/1! = 1
	double sum = 0;
	int k = 1;
	while (fabs(element) >= e+DBL_EPSILON) 
	{
		sum += element;
		element = nextElement(element, k);
		k++;
	}
	return sum;
}