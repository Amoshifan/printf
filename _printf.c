#include "main.h"

/**
 * _printf - a simulation of the printf function
 * @format: format string
 * Return: the string passed to _printf
 */
int _printf(const char *format, ...)
{
	int count = 0;
	int i, j;
	va_list args;
	char *str;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					for (j = 0; str[j] != '\0'; j++)
					{
						_putchar(str[j]);
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar(format[i]);
					count++;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * _putchar - function to return character to stdout
 * @c: a character
 * Return: @c
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
