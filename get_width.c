#include "main.h"

/**
 * get_width - Calc the width for printing
 * @format: Formatted str to print the args.
 * @i: args to be printed.
 * @list: list of args.
 *
 * Return: w.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_index;
	int width = 0;

for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
{
if (is_digit(format[curr_index]))
{
width *= 10;
width += format[curr_index] - '0';
}
else if (format[curr_index] == '*')
{
curr_index++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = curr_index - 1;
return (width);
}
