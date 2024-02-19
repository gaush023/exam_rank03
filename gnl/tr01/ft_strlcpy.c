#include <stdio.h>

size_t ft_strlen(char *s)
{
	ssize_t i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

size_t ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t i;
	size_t src_len;

	i = 0;
	src_len = ft_strlen(src);
	if(size)
	{
		while(src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		i++;
	}	
	return (src_len);
}


int main(void)
{
	char dst[10];
	char *src = "Apple is magic food?";
	printf("%zu\n%s\n", ft_strlcpy(dst, src, 10), dst);
	return (0);
}



