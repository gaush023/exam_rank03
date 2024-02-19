#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return i;
}

int print_string(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int ft_printf(const char *format, ...)
{
	int i;	
	va_list args;

	i = 0;
	va_start(args, format);
	while(*format)
	{
		if(*format == '%')
		{
			format++;
			if(*format == 's')
				i += print_string(va_arg(args, char *));
			if(*format == 'd')	
				i += print_string(ft_itoa(va_arg(args, int)));
					
		}
	}

}
