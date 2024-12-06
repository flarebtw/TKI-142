#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

/**
* @brief Считывает введеное значение 
* @return Возвращает введенное значение
*/
int input(void);

/**
 * @brief Создает массив
 * @param n размер массива
 * @return Возвращает массив с n элементами
 */
int* getArray(const size_t n);

/**
 * @brief Копирует исходный массив
 * @param array исходный массив
 * @param n число элементов массива
 * @return Возвращает скопированный массив
 */
int* copy(const int* const array, const size_t n);

/**
 * @brief Проверяет введенное число на неотрицательность
 * @param value вводимое число
 * @return Возвращает ошибку, если число отрицательно
 */
int positiveInput(void);

/**
* @brief Проверяет значение k
* @param k количество элементов с конца массива, которые нужно инвертировать
* @param n количество элементов в массиве
* @return возвращает ошибку если введено число больше количества элементов в массиве, либо если введено число меньше 0
*/
void checkK(const size_t k,const size_t n);

/**
* @brief Заполняет массив случайными числами
* @param array массив
* @param n количество элементов в массиве
* @param min начало диапазона
* @param max конец диапазона
* @return возвращает массив, заполненный случайными числами
*/
void fillArrayRandom(int* array, const size_t n, const int min, const int max);

/**
* @brief Заполнение массива при помощи ввода элементов с клавиатуры
* @param array массив
* @param n количество элементов в массиве
* @return возвращает массив, заполненный числами, введеными вручную
*/
void fillArrayManual(int* array, const size_t n);

/**
 * @brief Выводит исходный массив
 * @param array массив
 * @param n количество элементов в массиве
 * @return Возвращает вывод исходного массива
*/
void printArray(const int* array, const size_t n);

/**
* @brief Меняет знак на противоположный у k элементов с конца массива
* @param arrayInverted массив с инвертированными k элементами в массиве
* @param n количество элементов в массиве
* @param k количество элементов с конца массива, которые нужно инвертировать
* @return Возвращает массив, с инвертированными элементами
*/
void invertLastKElements(int* arrayInverted, const size_t n, const size_t k);

/**
* @brief Выводит индексы элементов массива, кратных 3
* @param array массив
* @param n количество элементов в массиве
* @return Возвращает индексы элементов кратных 3
*/
void printIndicesDivisibleBy3(const int* array, const size_t n);

/**
* @brief Ищет пару соседних элементов с искомой суммой в массиве
* @param array массив
* @param n количество элементов в массиве
* @param targetSum Искомая сумма 
* @return Вощвращает элементы с искомой суммой, а также их индексы
*/
bool hasAdjacentPairWithSum(const int* array, const size_t n,const int targetSum);

/**
* @brief Проверяет массив
* @param array массив
* @return возвращает ошибку, в случае нулевого массива
*/
void checkArray(const int* array);

/**
* @param random заполнение массива случайными числами
* @param manual заполнение массива пользователем
*/
enum request
{
    random, manual
};

/**
* @brief Точка входа в программу
* @return Возвращает 0 в случае успеха
*/
int main(void) 
{
    printf("Enter array size: ");
    size_t n = positiveInput();
    int* array = getArray(n);

    printf("Random - %d\n", random);
    printf("Manual - %d\n", manual);
    
    int choice = input();
    switch (choice)
    {
    case random:
        srand(time(0));  // Инициализация генератора случайных чисел
        printf("Enter minimal interval value \n");
        const int min = input();
        printf("Enter maximum interval value \n");
        const int max = input();
        fillArrayRandom(array, n, min, max);
        break;
    case manual:
        fillArrayManual(array, n);
        break;
    default:
        errno = ERANGE;
        perror("Function does not exist\n");
        exit(EXIT_FAILURE);
        break;
    } 

    printf("Source array: \n");
    printArray(array, n);

    printf("Enter amount of last elements to be inverted: ");
    size_t k = positiveInput();
    checkK(k, n);

    int* arrayInverted = copy(array, n);
    invertLastKElements(arrayInverted, n, k);

    printf("Array after inverting last %zu elements: ", k);
    printArray(arrayInverted,  n);
    free(arrayInverted);

    printf("Indices divisible by 3: ");
    printIndicesDivisibleBy3(array, n);

    printf("Enter the required sum: ");
    int targetSum = input();
    if (hasAdjacentPairWithSum(array, n, targetSum))
    {
        printf("Pair with required sum: %d found\n", targetSum);
    }
    else
    {
        printf("Pair with required sum: %d is not found.\n", targetSum);
    }

    free(array);

    return 0;
}

int input(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1)
    {
        errno = EIO;
        perror("Input error!");
        exit(EXIT_FAILURE);
    }
    return value;
}           

int* getArray(const size_t n)
{
	int* array = (int*)malloc(n * sizeof(int));
	checkArray(array);
	return array;
}

int* copy(const int* array, const size_t n)
{
	checkArray(array);
	int* copiedArray = getArray(n);

	for (size_t i = 0; i < n; ++i)
	{
		copiedArray[i] = array[i];
	}

	return copiedArray;
}

int positiveInput(void)
{
    int value = input();
    if (value <= 0)
    {
        errno = EINVAL;
        perror("Value must be higher than zero");
        exit(EXIT_FAILURE);
    }
    return value;
}

void checkArray(const int* array)
{
    if (array == NULL)
    {
        errno = ENOMEM;
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void checkK(size_t k, const size_t n)
{
    if (k >= n)
    {
        errno = ERANGE;
        perror("Value cannot be higher than amount of elements");
        exit(EXIT_FAILURE);
    }
}

void fillArrayRandom(int* array, const size_t n, const int min, const int max)
{
    checkArray(array);
    if (min > max)
    {
        errno = EINVAL;
        perror("Invalid range: min cannot be greater than max");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++)
    {
        array[i] = (rand() % (max-min+1)) + min;
    }
}

void fillArrayManual(int* array, const size_t n)
{
    checkArray(array);
    for (size_t i = 0; i < n; i++)
    {
        printf("Enter element %zu: ", i);
        array[i] = input();
    }
}

void printArray(const int* array, const size_t n)
{
    checkArray(array);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void invertLastKElements(int* arrayInverted, const size_t n, const size_t k)
{
    checkArray(arrayInverted);
    for (size_t i = n - k; i < n; i++)
    {
        arrayInverted[i] = -arrayInverted[i];
    }
}

void printIndicesDivisibleBy3(const int* array, const size_t n)
{
    checkArray(array);
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] % 3 == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

bool hasAdjacentPairWithSum(const int* array, const size_t n, const int targetSum)
{

    for (size_t i = 0; i < n - 1; i++)
    {
        if (array[i] + array[i + 1] == targetSum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}