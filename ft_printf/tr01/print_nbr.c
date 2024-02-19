#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int print_digit(long long nbr, char *c, int *i)
{
    if(nbr >= 10)
        print_digit(nbr/ 10, c, i);
    *i += write(1, &c[nbr % 10], 1);
    return(*i);
}

int	put_nbr(long long nbr)
{
	int		i;
	char	*c;

	i = 0;
	c = "0123456789";
	if (nbr < 0)
	{
		i += write(1, "-", 1);
		nbr = -nbr;
	}
    return (print_digit(nbr, c, &i));
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd'))
		{
			format++;
			len += put_nbr(va_arg(args, long long));
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (len);
}

int	main(void)
{
	ft_printf("O:%d\n", ft_printf("%d\n", 42));
	printf("R:%d\n", printf("%d\n", 42));
	return (0);
}