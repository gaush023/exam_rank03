#include "gnl.h" 

size_t ft_strlen(const char *s)
{
	ssize_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
	size_t len;
	size_t i;
	char *new;

	len = ft_strlen(s);	
	new = malloc((sizeof(char) * len) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char *ft_strchr(char *s, int c)
{
	while(*s)
	{
		if(*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t s1_len;	
	size_t s2_len;	
	size_t i;
	size_t j;
	char *new;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char)* (s1_len + s2_len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}	
	dst[i] = '\0';
	return (ft_strlen(src));
}

char *get_next_line(int fd)
{
	static char str[BUFFER_SIZE + 1];
        
	char *line;
	char *new;
	int cnt;
	int copy;

	line = ft_strdup(str);
	while(!(ft_strchr(line, '\n')) && (cnt = read(fd, str, BUFFER_SIZE))> 0)
	{
		str[cnt] = '\0';
		line = ft_strjoin(line, str);		
	}
	if(ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	new = ft_strchr(line, '\n');
        if(new != NULL)
	{
		copy = new - line + 1;
		ft_strlcpy(str, new + 1, BUFFER_SIZE + 1);
	}
	else
	{
		copy = ft_strlen(line);
		ft_strlcpy(str, "", BUFFER_SIZE + 1);
	}
	line[copy] = '\0';
	return (line);

}



int main(int ac, char **av)
{
	int fd;
	char *s;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((s = get_next_line(fd)) != NULL)
		{
			printf("%s", s);
			free(s);
		}
		close(fd);
	}
	return (0);
}


