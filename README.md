<h1 align="center">
	ft_printf
</h1>

*<p align="center">This project is pretty straightforward, you have to recode printf.
<br>
You will learn what is and how to implement variadic functions.<br>
Once you validate it, you will reuse this function in your future projects.</p>*

## Description:
Self-implemented printf. Implemented format specifiers and flags are listed in <b><a href = "#formatting-overview">overview</b>.  
Printf can be compiled with functions from [libft](https://github.com/heyitsyosh/42_libft/tree/main) into a library named `libftprintf.a`.  

## Set-up:
First, enter directory with `cd ft_printf`.  
Then use any Makefile command.  

#### Makefile Commands:
```C
make        //compile library (to libftprintf.a)
make clean  //delete .o
make fclean //delete .o and .a
make re     //delete .o and .a, recompile library
```

## Usage:  
```C
//Prototype:
int	ft_printf(const char *input, ...);
//Examples:
ft_printf("char: %c, string: %s, %%", 'c', "str");
ft_printf("%-10d", 123);
ft_printf("%#x", 123);
```
To use in projects, compile with `-L<path/to/dir> -lftprintf`.  
Alternatively, compile files directly with `path/to/libftprintf.a`.  
Make sure to include `ft_printf.h` appropriately in your source code.

#### Compilation Examples:
```
gcc main.c -L./ft_printf/ -lprintf
gcc main.c ./ft_printf/libftprintf.a
```

## Formatting overview:
| % | format specifier |
---|---|
%c | character |
%s | string |
%p | void pointer |
%d | signed int |
%i | signed int |
%u | unsigned int |
%x | hex (lowercase) |
%X | hex (uppercase) |
%% | % |

|Flag||
---|---|
num | minimum field width |
'-' | left justify |
'0' | padding with 0s |
'+' | print '+' if positive or '-' if negative |
' ' | print ' ' if positive or '-' if negative |
'#' | prefixes 0x/0X to x/X conversions |
'.' | precision	|
'*' | precision/width from parameter |
