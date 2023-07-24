# _**_printf**
This proyect point is my version of the printf function that we use in c.

## Code Style
Betty coding style.

## Flow chart

![_printf flowchart](https://github.com/Mvigil6343/holbertonschool-printf/assets/124288213/889070a4-b33b-4a43-9e60-98e8c4b35b73)

## Functions
* printc  
   A function that prints a unique character.
* prints  
   A function that prints a string.
* printd  
   A function that prints an int.
* printmod  
   A function that prints a % after the command. 
* converter  
   A function that converts a string of numbers into any base of numbers. We use it for decimal but it can be used to convert the numbers to binary or another base.
* auxlist  
   A function that is used to check which format the user is using and choose the correct print function, for example: %d uses printd.

## How to use:
You call the function by writing __printf() later you can choose what to print with the symbol % and then you write what you want to print. It can also print even without the % symbol.
Syntax: _printf(format, "argument");

example 1:
```
_printf("Welcome to the code");
```
It will print: Welcome to the code  

example 2:
```
char a = "Day"
_printf("Good %s", a);
```
It will print: Good Day

## Disclaimer
On the function prints if after the %s format the string is an empty string (""), it will print '%s' instead of nothing. 

## Author:
Marcos Vigil
