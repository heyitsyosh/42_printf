<h1 align="center">
 42_printf
</h1>

This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.

----
%  | format specifier  |
---|------|
%c | character|
%s | string|
%p | void pointer|
%d | signed int|
%d | signed int|
%u | unsigned int|
%x | hex (lowercase)|
%X | hex (uppercase)|
%% | %|


flag||
----|---|
num	| minimum field width						|
'-' 	| left justify|
'0' 	| padding with 0s|
'+' 	| print '+' if positive or '-' if negative|
' ' 	| print ' ' if positive or '-' if negative|
'#' 	| prefixes 0x/0X to x/X conversions |
'.' 	| precision															|
'*' 	| precision/width from parameter	|

----
Relationship chart of formats and flags:

[![chart.png](https://i.postimg.cc/Y9SJ6PKr/chart.png)](https://postimg.cc/Z917ZV52)

----
**I tried to stay true to the original printf as much as possible.**

If output formatting is interrupted by an irrelevant character, printf prints the string after the already parsed flags.  
>Example:  
>```printf("%#()s%s", "abc")``` outputs ```()sabc```  

My implementation treats all characters not mentioned in the pdf as irrelevant and acts accordingly.  

>% \<flags\> \<width\> <.prec> type_char  

Although putting flags, width, precision in the wrong order produces a warning, the original printf parses correctly and compiles.  
My code accepts output formatting in the wrong order as well.  
