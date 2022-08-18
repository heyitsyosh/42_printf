# 42_printf


I tried to implement the origial printf as much as possible.
(even input that causes warnings)

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
'.' 	| precision															|
'*' 	| precision/width from parameter	|
