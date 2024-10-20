#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

double input(void);

double inputInt(void);

double next_element(double previous_element, int k);

double getNSum(int n);

double getSumNotLessThanE(int n, const double e);

int main(void)
{
	puts("Enter number of sequence elements:");
	const int n = inputInt();
	puts("Enter e value:");
	const double e = input();
	printf("")
}