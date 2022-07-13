#include "main.h"

/**
 * get_flag - truns on flags if _printf finds
 * a flag mod in the format str
 * @s: char that holds flag specifier
 * @f: pointer to struct flags in which we turn the flags on
 * Ret: 1 if a flag has been turned on, 0 if otherwise
 */

int get_flag(char s, flags_t *f)
{
int i = 0;

switch (s)
{
	case '+':
		f->plus = 1;
		i = 1;
		break;
	case ' ':
		f->space = 1;
		i = 1;
		break;
	case '#':
		f->hash = 1;
		i = 1;
	
		break;

}
return (i);
}
