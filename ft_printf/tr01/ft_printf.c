#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	put_str(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	put_nbr(long long int number)
{
	if (number < 0)
	{
		write(1, "-", 1);
		if (number <= -10)
			put_nbr(number / -10);
		return (write(1, &"0123456789"[-(number % 10)], 1) + 1);
	}
	else if (number >= 10)
	{
		put_nbr(number / 10);
	}
	return (write(1, &"0123456789"[number % 10], 1));
}

void	print_hex(unsigned int nbr, int *printed)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		print_hex(nbr / 16, printed);
		print_hex(nbr % 16, printed);
	}
	else
	{
		write(1, &base[nbr], 1);
		(*printed)++;
	}
}

int	put_hex(unsigned int nbr)
{
	int	printed;

	printed = 0;
	print_hex(nbr, &printed);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 's' || *(format + 1) == 'd'
				|| *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				length += put_str(va_arg(args, char *));
			else if (*format == 'd')
				length += put_nbr(va_arg(args, long long));
			else if (*format == 'x')
				length += put_hex(va_arg(args, unsigned int));
		}
		else
		{
			write(1, format, 1);
			length++;
		}
		format++;
	}
	va_end(args);
	return (length);
}

int	main(void)
{
	ft_printf("Hello %s, %d, %x\n", "world", 42, 42);
	printf("Hello %s, %d, %x\n", "world", 42, 42);
	return (0);
}
