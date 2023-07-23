#include "main.h"

/**
 *converter - a function to convert a number to the selected base
 *@num: the number which i want to change
 *@base: the base I want to change my number
 *Return: a pointer
 */

char *converter(int num, int base)
{
	static char *hex = "0123456789abcdef";
	static char *p;
	static char arr[20];
	int rest = 0, i, neg = 0;

	if (num == 0)
		return ("0");
	if (num < 0 && base == 10)
	{
		num = -num;
		neg = 1;
	}
	for (i = 0; i < 20; i++)
		arr[i] = '0';
	p = &arr[63];
	*p = '\0';
	while (num != 0)
	{
		rest = num % base;
		*--p = hex[rest];
		num = num / base;
	}
	if (neg == 1)
		*--p = '-';
	return (p);
}

/**
 *printd - a function to print a decimal
 *@d: the numbers I want to print
 *Return: the lenght of what the funcion printed
 */

int printd(va_list d)
{
	int counter, num;
	char *result;

	num = va_arg(d, int);
	if (num == INT_MIN)
	{
		result = "-2147483648";
		for (counter = 0; result[counter]; counter++)
			_putchar(result[counter]);
		return (counter);
	}
	result = converter(num, 10);
	for (counter = 0; result[counter]; counter++)
		_putchar(result[counter]);
	return (counter);
}
