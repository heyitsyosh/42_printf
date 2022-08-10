#include <stdio.h>

int main()
{
	 int a;
	const char	specifiers[10] = "cspdiuxX%";
	// char *b = "abc";
	// printf("%s");
	//printf("%-09 ", );
	printf("%s \n", specifiers);
	a = printf("asdf%  j%%d", 0);
	printf("%d", a);
	return (0);
}