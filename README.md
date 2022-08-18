# 42_printf

This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.

%  | format specifier |
---|------|
%c | character				|
%s | string					|
%p | void pointer				|
%d | signed int	|
%d | signed int	|
%u | unsigned int		|
%x | hex (lowercase)|
%X | hex (uppercase)|
%% | %			|

flag||
----|---|
number	| minimum field width						|
'-' 	| left justify 																	|
'0' 	| padding with 0s								|
'+' 	| left justify 																	|
' ' 	| left justify 																	|
'#' 	| left justify 																	|
'.' 	| precision															|
'*' 	| precision/width from parameter	|

Relationship chart of formats and flags:


I tried to implement the original as much as possible.

If conversion specifiers are interrupted by an irrelevant character, printf prints string after %.
The 
Example: ```printf("%#()s", "abc")``` outputs ```#()s```
```printf("%#()s%s", "abc")``` outputs ```#()sabc```
My implementation treats all characters not mentioned in the pdf as irrelevant.

% <flags> <width> <.prec> type_char
  
