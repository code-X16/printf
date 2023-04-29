#include "main.h"

/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * @f_list: A list of all the posible functions
 * @arg_list: A list containing all the argumentents passed to the program
 *
 * Return: total count of the characters printed
 */

int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int k, l, r_val, printed_chars;

	printed_chars = 0;
	for (k = 0; format[k] != '\0'; k++)
	{
		if (format[k] == '%')
		{
			for (l = 0; f_list[l].sym != NULL; l++)
			{
				if (format[k + 1] == f_list[l].sym[0])
				{
					r_val = f_list[l].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[l].sym == NULL && format[k + 1] != ' ')
			{
				if (format[k + 1] != '\0')
				{
					_write_char(format[k]);
					_write_char(format[k + 1]);
					printed_chars += 2;
				}
				else
					return (-1);
			}
			k += 1;
		}
		else
		{
			_write_char(format[k]);
			printed_chars++;
		}
	}
	return (printed_chars);
}
