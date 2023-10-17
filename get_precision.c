#include "main.h"
/**
 * get_precision - Calculates the precision
 * @format: print the arguments
 * @i: arguments
 * @arg_list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list arg_list)
{
int curr_i = *i + 1;
int precision = -1;
if (format[curr_i] != '.')
return (precision);
precision = 0;
for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(arg_list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (precision);
}
