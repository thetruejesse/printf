#include "main.h"

/*
 * get_print - selects the right printing func dep on the
 * conversion specifier passed to _printf
 * @s: char that holds the specifier
 * Description: funcition loops through structs arr
 * func_arr[] to find a match btn spec passed to _printf
 * and first element of struct, and then appropriate printing func
 * Return: pointer to matching printing func
 */

int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
	};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
