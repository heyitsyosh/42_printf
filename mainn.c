#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	print_str(char *input, size_t len)
{
	if (len < INT_MAX)
		write(1, input, len);
	else
		len = INT_MAX;
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*(s + len) != '\0')
		len++;
	return (len);
}

int main()
{
	char *test = NULL;
	
	int len = ft_strlen(test);
	print_str(test, len);
}

