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
int* copy(const int* const array, const size_t n);

/**
 * @brief Проверяет введенное число на неотрицательность
 * @param value вводимое число
 * @return Возвращает ошибку, если число отрицательно
 */
void checkPositive(int value);