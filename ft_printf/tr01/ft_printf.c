
#include <unistd.h>
#include <stdrag.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

int put_str(char *str)
{
	return (write(1, str, ft_strlen(str)); 
}

int put_nbr(long long int number)
{
	long long i;
	char c;

	i = 0;
	if(number < 0)
	{
		number *= -1;
		write(1, '-', 1);
		i++;
	}
	while(i >= 10)
	{
		number = number / 10;
		c = number % 10 + '0';
		write(1, c, 1);
		i++;
	}
	write(1, number + '0', 1);
	i++;
	return (i);
}

int put_hex( int nbr)
{
	int i;
	int tmp;

	i = 0;
	while(nbr >= 16)
	{
		tmp = nbr / 16;
		nbr  = nbr % 16;
q		if
		i++;
	}


}


int ft_printf(const char *format, ...)
{
	int length;
	va_list pointer;

	length = 0;
	va_start(pointer, format);

	while(*format)
	{
		if((*format == '%' ) && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x'))
		{
			format++;
			if(*format == 's')
				lenght = put_str(va_arg(pointer, char *))
			else if(*format == 'd')
				length = put_nbr(long long int)va_args(pointer, int);
			else if(*format == 's')
				length = put_hex(long long int)va_args(pointer,  int);

		}
		else
		{
			write(1, format, 1);
			length++;	
		}
		format++;
	}
	return(va_end(pointer), length);	
}

