#include <stdio.h>
#include <stddef.h>

// void printascii()
// {
//     int i;
//     i=0;
//     while(i<=301)
// 	{
//         printf("%d %c \n",i,i);
//         i++;
// 	}
// }

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}

// void	print_str(char *s, int fd, size_t s_len)
// {
// 	while (s_len > INT_MAX)
// 	{
// 		write(fd, s, INT_MAX);
// 		s += INT_MAX;
// 		s_len -= INT_MAX;
// 	}
// 	write(fd, s, s_len);
// }

void	pointer_experiment(char *ptr)
{
	//print_str
	ptr = ft_strchr(ptr, 'a');
}

int main()
{
	 int a;
	//const char	specifiers[10] = "cspdiuxX%";
	// char *b = "abc";
	// printf("%s"); //no matching variable
	//printf("%-09 ", ); 
	//a = printf("%   d", 10); //double ' ' flag works as if only one.
	//a = printf("%  - -d", 10); //mixed double flags only counts one of each.
	//printf("%s \n", specifiers); //checked allocation format
	// a = printf("asdf% %%d", 0);  //irrelevant character interrups flag = asdf%0
	// a = printf("asdf% c%d", 'a', 3);  //irrelevant character interrups flag = asdf%0
	// a = printf("asdf% c%d", 'a', 3);
	// a = printf("asdf%03c%d", 'a');  //irrelevant character interrups flag = asdf%0
	// a = printf("asdf%03c%d", 'a');  //%d not specifies, prints negative garbage value
	// a = printf("asdf%%", ); //not putting variable cannot compile
	//a = printf("asdf%c", 300);
	//printascii();
	//a = printf("asdf%103c", 'a'); //pure number before specifies width and fills with space
	//a = printf("asdf%-103c", 'a'); //char reacts to -
	//a = printf("asdf%03-103c", 'a'); //ignores 0 padding
	//printf("%d", a);

	// char *ptr = "holla-----";
	// pointer_experiment(ptr);
	// printf("%s", ptr);
	// return (0); //im an idiot you can change content in another function using pointers but not the pointer itself (doesnt move at all) unless i have a double pointer, then I could move along the pointer?? i think.

	//a = printf("asdf%*c", 'a'); //more '%' conversions than data arguments
	//a = printf("asdf%.c", 'a'); //no error (perhaps . reads num after and detects 0?)
	//a = printf("asdf%.1234c", 'a'); //precision used with 'c' conversion specifier, resulting in undefined behavior
	//a = printf("asdf%-12345c", 'a'); //ignores 0 padding

	//a = printf("asdf%.000c", 'a');
	a = printf("%");
	printf("%d", a);
}

//undefined with %c - (#-no reaction, ' '-no reaction, precision but not necessarily '.' - no reaction (if only ., not undefined. compiles with no reaction), '+' - no reaction, '0' - has reaction)
//%c works with purely number specifiers, and '-'

//no error (perhaps . reads num after and detects 0?)
//use sizeof va arg to determine if there is at least one variable after input

/*
characters dont react to flags, except 0 padding

how does width react with all datatype?
mixing up the order of flags?
printing more than int_max characters?
converting over 4095 bytes?
what happens when % is not followed up by a specifier (more % conversions than data arguments)
what happens when flags are interrupted by irrelevant characters?
when there isnt a variable but a percent?
when the datatypes dont match?
when null or empty values are printed?

what are the possible errors?

_ _ _ _
*/