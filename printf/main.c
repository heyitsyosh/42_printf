#include "printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	// int a = ft_printf("asdf%012d", -12);
	//int a = ft_printf(" %c ", '0');
	//ft_printf(" %-2d ", -1);
	int a =	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");
	int b = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\na = %d, b = %d", a, b);
	//int a = ft_printf("\nmaria%s%d", "kankan123", 1);
	//ft_printf("\n%d", a);
}
