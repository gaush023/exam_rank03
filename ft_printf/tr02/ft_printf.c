#include <stdio.h>
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

void print_hex(unsigned int n, size_t *i)
{
	char *base;

	base = "0123456789abcdef";
	if(n >= 16)
	{
		print_hex(n / 16, i);
		print_hex(n % 16, i);
	}
	else
	{
		write(1, &base[n], 1);
		(*i)++;
	}
}

int print_nbr(long long n)
{
	char *nbr;

	nbr = "0123456789";
	
	if(n < 0)
	{
		write(1, "-", 1);
		if(n <= -10)
			print_nbr(n/ 10);
		return(write(1, &nbr[-(n % 10)], 1) + 1);
	}
	else if(n >= 10)
		print_nbr(n/ 10);
	return(write(1, &nbr[n % 10], 1));
}


int ft_printf(const char *format, ...)
{
	size_t  i;	
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
				i += print_nbr (va_arg(args, long long));
			if(*format == 'x')
				 print_hex(va_arg(args, unsigned int), &i);
		}
		else
		{
			write(1, format, 1);
			i++;
		}
		format++;
	}
	va_end(args);
	return(i);
}


int main(void)
{
	printf("Hello %s\n%d\n%x\n%d\n", "world", 42, 42, printf("%x", 42));	
	ft_printf("Hello %s\n%d\n%x\n%d\n", "world", 42, 42,ft_printf("%x", 42));	
	return (0);
}


