# 42_printf


I tried to implement the origial printf as much as possible.
(even input that causes warnings)

%  | format specifier |
---|------|
%c | character				|
%s | string					|
%p | pointer				|
%d | decimal signed integer	|
%i | integer				|
%u | unsigned integer		|
%x | hex integer (lowercase)|
%X | hex integer (uppercase)|
%% | just the %				|

flag||
----|---|
num	| (number between % and the identifier) minimum field width						|
'-' 	| left justify 																	|
'0' 	| field padded with 0's instead of blanks										|
'.' 	| precision															|
'*' 	| indicates that the maximum or minimum field width will be passed as parameter	|
