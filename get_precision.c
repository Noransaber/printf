#include "main.h"

/**
 * get_precision - Calc the pre for printing
 * @format: Formatted string  to print the arguments
 * @i: List of args to be printed.
 * @list: list of args.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_index = *i + 1;
int precision = -1;
if (format[curr_index] != '.')
return (precision);
precision = 0;
for (curr_index += 1; format[curr_index] != '\0'; curr_index++)
{
if (is_digit(format[curr_index]))
{
precision *= 10;
precision += format[curr_index] - '0';
}
else if (format[curr_index] == '*')
{
curr_index++;
precision = va_arg(list, int);
break;
}
else
break;
}
*i = curr_index - 1;
return (precision);
}
