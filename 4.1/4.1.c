#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

/**
* @brief Считывает введеное значение 
* @return Возвращает введенное значение
*/
size_t input(void);

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
* @return возвращает массив, заполненный случайными числами
*/
void fillArrayRandom(int* array, const size_t n);

/**
 * @brief выводит массив, заполненный случайными числами
 * @param n количество элементов в массиве
 * @param array массив
 * @return выводит массив
*/
void printRandomArray(const size_t n, int* array);

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
void printSourceArray(int* array, const size_t n);

/**
* @brief Меняет знак на противоположный у k элементов с конца массива
* @param arrayInverted массив с инвертированными k элементами в массиве
* @param array массив
* @param n количество элементов в массиве
* @param k количество элементов с конца массива, которые нужно инвертировать
* @return Возвращает массив, с инвертированными элементами
*/
void invertLastKElements(int* arrayInverted, int* array, const size_t n, const size_t k);

/**
* @brief Выводит индексы элементов массива, кратных 3
* @param array массив
* @param n количество элементов в массиве
* @return Возвращает индексы элементов кратных 3
*/
void printIndicesDivisibleBy3(int* array, size_t n);

/**
* @brief Ищет пару соседних элементов с искомой суммой в массиве
* @param array массив
* @param n количество элементов в массиве
* @param targetSum Искомая сумма 
* @return Вощвращает элементы с искомой суммой, а также их индексы
*/
int hasAdjacentPairWithSum(int* array, size_t n, int targetSum);

/**
* @brief Проверяет массив
* @param array массив
* @return возвращает ошибку, в случае нулевого массива
*/
void checkArray(int* array);

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
    size_t n = input();
    if (n <= 0)
    {
        errno = EIO;
        perror("Array size must be positive!");
        exit(EXIT_FAILURE);
    }
    int* array = (int*)malloc(n * sizeof(int));
    checkArray(array);

    printf("Random - %d\n", random);
    printf("Manual - %d\n", manual);
    
    int choice = input();
    switch (choice)
    {
    case random:
        srand(time(0));  // Инициализация генератора случайных чисел
        fillArrayRandom(array, n);
        printRandomArray(n, array);
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

    printSourceArray(array, n);

    printf("Enter amount of last elements to be inverted: ");
    size_t k = input();
    checkK(k, n);

    int* arrayInverted = (int*)malloc(n * sizeof(int));
    invertLastKElements(arrayInverted, array, n, k);

    printf("Array after inverting last %zu elements: ", k);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arrayInverted[i]);
    }
    printf("\n");

    free(arrayInverted);

    printIndicesDivisibleBy3(array, n);

    printf("Enter the required sum: ");
    int targetSum = input() ;
    hasAdjacentPairWithSum(array, n, targetSum);

    free(array);
    return 0;
}

size_t input(void)
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

void checkArray(int* array)
{
    if (array == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void checkK(size_t k, const size_t n)
{
    if (k > n)
    {
        errno = ERANGE;
        perror("Value cannot be higher than amount of elements");
        exit(EXIT_FAILURE);
    }
}

void fillArrayRandom(int* array, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        array[i] = (rand() % 201) - 100;
    }
}

void printRandomArray(const size_t n, int* array)
{
    printf("Array of random numbers:");
        for (size_t i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
}

void fillArrayManual(int* array, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        array[i] = input();
    }
}

void printSourceArray(int* array, const size_t n)
{
    printf("Source array: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void invertLastKElements(int* arrayInverted ,int* array, const size_t n, const size_t k)
{
    for (size_t i = 0; i < n; i++)
    {
        arrayInverted [i] = array[i];
    }
    for (size_t i = n - k; i < n; i++)
    {
        arrayInverted[i] = -array[i];
    }
}

void printIndicesDivisibleBy3(int* array, const size_t n)
{
    printf("Indices divisible by 3: ");
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] % 3 == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int hasAdjacentPairWithSum(int* array, size_t n, int targetSum)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (array[i] + array[i + 1] == targetSum)
        {
            printf("Pair with required sum: %d found: Elements %d and %d (indices %d and %d)\n", targetSum, array[i], array[i + 1], i, i + 1);
            return 1;
        }
    }
    printf("Pair with required sum: %d is not found.\n", targetSum);
    return 0;
}