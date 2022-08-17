#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printascii()
{
    int i;
    i=0;
    while(i<=301)
	{
        printf("%d %c \n",i,i);
        i++;
	}
}

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s != (char)c)
// 		if (*s++ == '\0')
// 			return (NULL);
// 	return ((char *)s);
// }

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

// void	pointer_experiment(char *ptr)
// {
// 	//print_str
// 	ptr = ft_strchr(ptr, 'a');
// }

int main(){
	// int a;
	//const char	specifiers[10] = "cspdiuxX%";
	// char *b = "abc";
	// printf("%s"); //no matching variable
	//printf("%-09 ", ); 
	//a = printf("%   d", 10); //double ' ' flag works as if only one.
	//a = printf("%  - -d", 10); //mixed double flags only counts one of each.
	//printf("%s \n", specifiers); //checked allocation format
	// a = printf("asdf% %%d", 0);
	//a = printf("asdf%12s", NULL);  //irrelevant character interrups flag = asdf%0
	//a = printf("%-.3s", "abc");
	// a = printf("%*%", 12);
	// printf("\n%d", a);
	// a = printf("asdf% c%d", 'a', 3);
	// a = printf("asdf%03c%d", 'a');  //irrelevant character interrups flag = asdf%0
	// a = printf("asdf%03c%d", 'a');  //%d not specifies, prints negative garbage value
	// a = printf("asdf%%", ); //not putting variable cannot compile
	//a = printf("asdf%c", 300);
	printascii();
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
	//a = printf("%"); // prints nothing returns 0
	//printf("%d", a);
	//a = printf("%*12 #d", 12); //warning: unknown conversion type character ‘1’ in format //%1212 #d
	//a = printf("%*d", 12, 12);
	//a = printf("%*d", 'a', 12);
	//a = printf("%123 #d", 12); //warning: too many arguments for format //%123 #d
	//a = printf("%*.2d", 12, 1);
	// a = printf("%*.2d", 12.3, 1); //prints negative garbage value, warning: field width specifier ‘*’ expects argument of type ‘int’, but argument 2 has type ‘double’
	//a = printf("%12.2d",  1);
	//a = printf("%12.1100d",  1);
	//a = printf("%12.1100d",  1);
	//a = printf("%*d",  -12, 1); // invalid, width specifier ignored
	//a = printf("%s", str); // prints nothing returns 0

	// int b = 2;
	// char *str = "abcdefg";
	// write(1, str + b++, 1);
	// write(1, str + b, 1);
	// printf("\n%d", a);

	// warning: ‘%2147483648d’ directive output of 2147483648 bytes exceeds ‘INT_MAX’
	//note: ‘printf’ output 2147483653 bytes
	// a = printf("%2147483647d", 1); //INTMAX, doesnt print, return -1
	// printf("\n[%d]\n", a);
	// a = printf("%2147483648d", 1); //INTMAX + 1, doesnt print, return -1
	// printf("\n[%d]\n", a);
	//a = printf("a%2147483645d", 1); //INTMAX - 1, prints, returns printed num
	//printf("\n[%d]\n", a);
	// a = printf("a%2147483644dabasdf", 1); //INTMAX - 1, prints
	// printf("\n[%d]\n", a);
	// a = printf("%da%2147483643dabasdf", 1, 1); //INTMAX - 1, prints, but returns -1
	// printf("\n[%d]\n", a);
	//a = printf("");

// printf("st|%d\n",    printf("st|%2147483644d\n", 1)); //フィールド幅がINT_MAX未満
// printf("st|%d\n",    printf("st|%2147483648d\n", 1)); //フィールド幅がINT_MAX超

// size_t n = INT_MAX;
// n += 10;
// char *str;
// str = malloc(sizeof(char) * (n + 1));
// memset(str, 'a', n);
// str[n] = '\0';
// printf("(ret)|%d|\n",   printf("st(fmt)|%s|", str)); //%sがINT_MAX超

// // やたら0を出力する。いつ終わるのかわからない感じ。
// printf("st|%d\n",    printf("st|%.2147483648d\n", 1)); //精度がINT_MAX超


}

//undefined with %c - (#-no reaction, ' '-no reaction, precision but not necessarily '.' - no reaction (if only ., not undefined. compiles with no reaction), '+' - no reaction, '0' - has reaction)
//%c works with purely number specifiers, and '-'

//no error (perhaps . reads num after and detects 0?)
//use sizeof va arg to determine if there is at least one variable after input

/*
characters dont react to flags, except 0 padding

how does width react with all datatype?
mixing up the order of flags?
printing more than int_max characters (string literal length, width/precision specification)?
what happens when % is not followed up by a specifier (more % conversions than data arguments)
what happens when flags are interrupted by irrelevant characters?
when there isnt a variable but a percent?
when the datatypes dont match?
when null or empty values are printed?

what are the possible errors?

_ _ _ _
*/