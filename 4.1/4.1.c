#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

/**
* @brief Считывает введеное значение 
* @return Возвращает введенное значение
*/
int Input(void);

/**
 * @brief Вызывает меню
 * @return Возвращает значение выбранный параметр
 */
void printMenu(void);

/**
* @brief Проверяет значение k
* @param k количество элементов с конца массива, которые нужно инвертировать
* @param n количество элементов в массиве
* @return возвращает ошибку если введено число больше количества элементов в массиве, либо если введено число меньше 0
*/
void checkK(int k, int n);

/**
* @brief Заполняет массив случайными числами
* @param array массив
* @param n количество элементов в массиве
* @return возвращает массив, заполненный случайными числами
*/
void fillArrayRandom(int* array, int n);

/**
* @brief Заполнение массива при помощи ввода элементов с клавиатуры
* @param array массив
* @param n количество элементов в массиве
* @return возвращает массив, заполненный числами, введеными вручную
*/
void fillArrayManual(int* array, int n);

/**
* @brief Меняет знак на противоположный у k элементов с конца массива
* @param array массив
* @param n количество элементов в массиве
* @param k количество элементов с конца массива, которые нужно инвертировать
* @return Возвращает массив, с инвертированными элементами
*/
void invertLastKElements(int* array, int n, int k);

/**
* @brief Выводит индексы элементов массива, кратных 3
* @param array массив
* @param n количество элементов в массиве
* @return Возвращает индексы элементов кратных 3
*/
void printIndicesDivisibleBy3(int* array, int n);

/**
* @brief Ищет пару соседних элементов с искомой суммой в массиве
* @param array массив
* @param n количество элементов в массиве
* @param targetSum Искомая сумма 
* @return Вощвращает элементы с искомой суммой, а также их индексы
*/
int hasAdjacentPairWithSum(int* array, int n, int targetSum);

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
    int n = Input();
    if (n <= 0)
    {
        errno = EIO;
        perror("Array size must be positive!");
        exit(EXIT_FAILURE);
    }
    int* array = (int*)malloc(n * sizeof(int));
    checkArray(array);

    printMenu();
    
    int choice = Input();
    switch (choice)
    {
    case random:
        srand(time(0));  // Инициализация генератора случайных чисел
        fillArrayRandom(array, n);
        printf("Array of random numbers:");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
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

    printf("Source array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter amount of last elements to be inverted: ");
    int k = Input();
    checkK(k, n);
    invertLastKElements(array, n, k);

    printf("Array after inverting last %d elements: ", k);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printIndicesDivisibleBy3(array, n);

    printf("Enter the required sum: ");
    int targetSum = Input() ;
    hasAdjacentPairWithSum(array, n, targetSum);

    free(array);
    return 0;
}

int Input(void)
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

void printMenu(void)
{
    printf("Random - %d\n", random);
    printf("Manual - %d\n", manual);
}

void checkK(int k, int n)
{
    if (k > n || k < 0)
    {
        errno = ERANGE;
        perror("Value cannot be higher than amount of elements or negative!");
        exit(EXIT_FAILURE);
    }
}

void fillArrayRandom(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = (rand() % 201) - 100;
    }
}

void fillArrayManual(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        array[i] = Input();
    }
}

void invertLastKElements(int* array, int n, int k)
{
    for (int i = n - k; i < n; i++)
    {
        array[i] = -array[i];
    }
}

void printIndicesDivisibleBy3(int* array, int n)
{
    printf("Indices divisible by 3: ");
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 3 == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int hasAdjacentPairWithSum(int* array, int n, int targetSum)
{
    for (int i = 0; i < n - 1; i++)
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
