#include "main.h"

/**
 * prints_bigS - non printable chars
 * (0 < ASCII val < 32 or >= 127) are
 * printed this way: \x, followed by ASCII val
 * in hexadec (uppercase - always 2 chars)
 * @l: va_list of args from _printf
 * @f: poinater to the struct flags that dets if a
 * flag is passed to _printf
 * Return: number of chars printed
 */
int print_bigS(va_list l, flags_t *f)
{
int i, count = 0;
char *res;
char *s = va_arg(l, char *);

(void)f;
if (!s)
	return (_puts("(null)"));

for (i = 0; s[i]; i++)
{
	if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
	{
		_puts("\\x");
		count += 2;
		res = convert(s[i], 16, 0);
		if (!res[1])
			count += _putchar('0');
		count += _puts(res);
	}
	else
		count += _putchar(s[i]);
}
return (count);
}

/**
 * print_rot13 - prints a str using rot13
 * @l: list of args from _printf
 * @f: pointer to the struct flags that dets if a flag is passed to _printf
 * Return: length of the printed str
 */
int print_rot13(va_list l, flags_t *f)
{
int i, j;
char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
char *s = va_arg(l, char *);

(void)f;
for (j = 0; s[j]; j++)
{
	if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
		_putchar(s[j]);
	else
	{
		for (i = 0; i <= 52; i++)
		{
			if (s[j] == rot13[i])
				_putchar(ROT13[i]);
		}
	}
}
return (j);
}

/**
 * print_percent - prints a percent
 * @l: va_list args from _printf
 * @f: pointer to struct flags in which we turn flags on
 * Return: num of chars printed
 */
int print_percent(va_list l, flags_t *f)
{
(void)l;
(void)f;
return (_putchar('%'));
}
