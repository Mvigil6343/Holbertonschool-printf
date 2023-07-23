#include "main.h"
/**
 * printc - a function that prints a unique char
 * @c: - the char to be printed
 * Return: 1
 */
int printc(va_list c)
{
	char character = va_arg(c, int);

	write(1, &character, 1);
	return (1);
}
/**
 * prints - a function that prints a String
 * @s: - a string
 * Return: the length of the string
 */
int prints(va_list s)
{
	char *string;
	int counter;

	string = va_arg(s, char *);
	if (string == NULL)
	{
		counter = write(1, "(null)", 6);
		return (counter);
	}
	for (counter = 0; string[counter] != '\0'; counter++)
	{
		_putchar(string[counter]);
	}
	return (counter);
}

/**
 * printmod - a function that prints a % character
 * @m: the % character
 * Return: 1
 */
int printmod(va_list m)
{
	(void)m;
	_putchar('%');
	return (1);
}
/**
 * auxlist - calls the struct
 * @x: character inside the va_list
 * @list: the thing i want to print
 * Return: an int
 */
int auxlist(char x, va_list list)
{
	int j = 0, count = 0;
	ope op[] = {
	{'c', printc},
	{'s', prints},
	{'%', printmod},
	{'d', printd},
	{'i', printd},
	{0, NULL},
	};

	while (op[j].fr != 0)
	{
		if (op[j].fr == x)
		{
			count = op[j].func(list);
		}

		j++;
	}
return (count);
}

/**
 * _printf - works like printf function
 * @format: the thing we want to print
 * Return: the number of printed chars
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, count = 0, aux = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			count += _putchar(format[i]);


		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			aux = auxlist(format[i + 1], list);
			if (aux == 0)
			{
				i--;
				aux += _putchar(format[i + 1]);
			}
			count += aux;
			i++;
		}
		i++;
	}
	va_end(list);
	return (count);
}
