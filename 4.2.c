#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

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
int* copy(const int* array, const size_t n);

/**
 * @brief Проверяет введенное число на неотрицательность
 * @param value вводимое число
 * @return Возвращает ошибку, если число отрицательно
 */
void checkPositive(int value);

/**
* @brief Заполняет массив случайными числами
* @param array массив
* @param n количество элементов в массиве
* @param a начало диапазона
* @param b конец диапазона
* @return возвращает массив, заполненный случайными числами
*/
void fillArrayRandom(int* array, const size_t n, const int a, const int b);

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
 * @brief Заменяет первый отрицательный элемент нулем
 * @param array исходный массив
 * @param n число элементов в массиве
 * @return Возвращает измененный массив
 */
void replaceFirstNegativeWithZero(int* array, const size_t n);

/**
 * @brief Вставляет число k после каждого элемента, кратного своему индексу
 * @param array массив
 * @param n число элементов массива
 * @param k число, вводимое пользователем
 * @return Возвращает измененный массив
 */
void insertKIntoArray(int** array, size_t* n, const int k);

/**
 * @brief Создает массив A из D по правилам
 * @param array иссходный массив, он же массив D
 * @param A новый массив
 * @param n число элементов в массиве
 * @return Возвращает новый массив
 */
void createArrayAFromD(const int* array, int* A, const size_t n);

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
    checkPositive(n);
    if (n == 0)
    {
        errno = EIO;
        perror("Array size must be higher than zero!");
        exit(EXIT_FAILURE);
    }
    int* array = getArray(n);
    
    printf("Random - %d\n", random);
    printf("Manual - %d\n", manual);
    
    int choice = input();
    switch (choice)
    {
    case random:
        srand(time(0));
        printf("Enter minimal interval value \n");
        const int a = input();
        printf("Enter maximum interval value \n");
        const int b = input();
        fillArrayRandom(array, n, a, b);
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

    int* clonnedArray = copy(array, n);
    replaceFirstNegativeWithZero(clonnedArray, n);
    free(array);

    printf("Array after replacing first negative element with zero:\n");
    printArray(clonnedArray, n);

    printf("Enter k value:");
    const int k = input();
    insertKIntoArray(&clonnedArray, &n, k);
    printf("Array after inserting K after multiples of index:\n");
    printArray(clonnedArray, n);

    int* A = getArray(n);
    createArrayAFromD(clonnedArray, A, n);
    printf("Array A formed from source:\n");
    printArray(A, n);

    free(clonnedArray);
    free(A);

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

void checkPositive(int value)
{
    if (value < 0)
    {
        errno = EINVAL;
        perror("Value must be non-negative");
        exit(EXIT_FAILURE);
    }
}

void checkArray(int* array)
{
    if (array == NULL)
    {
        errno = ENOMEM;
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void fillArrayRandom(int* array, const size_t n, const int a, const int b)
{
    if (a > b)
    {
        errno = EINVAL;
        perror("Invalid range: min cannot be greater than max");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; i++)
    {
        array[i] = (rand() % (b-a+1)) - b;
    }
}

void fillArrayManual(int* array, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("Enter element %zu: ", i);
        array[i] = input();
    }
}

void printArray(const int* array, const size_t n)
{
    printf("{ ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d", array[i]);
        if (i < n - 1)  
        {
            printf(", ");
        }
    }
    printf(" }\n");
}

void replaceFirstNegativeWithZero(int* array, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            array[i] = 0;
            break;
        }
    }
}

void insertKIntoArray(int** array, size_t* n, const int k)
{
    size_t count = 0;

    if ((*array)[0] == 0)

        {
            count++;
        }
    
    for (size_t i = 1; i < *n; i++)
    {
        if ((*array)[i] % i == 0)
        {
            count++;
        }
    }

    size_t newSize = *n + count;
    int* newArray = getArray(newSize);

    size_t j = 0;
    for (size_t i = 0; i < *n; i++)
    {
        newArray[j++] = (*array)[i];

        if (i == 0 && (*array)[i] == 0)
        {
            newArray[j++] = k;
        }


        if (i > 0 && (*array)[i] % i == 0)
        {
            newArray[j++] = k;
        }
    }

    free(*array);
    *array = newArray;
    *n = newSize;
}

void createArrayAFromD(const int* array, int* A, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            A[i] = (i) * array[i];  
        } else
        {
            A[i] = array[i] * (i + 1) * 2; 
        }
    }
}