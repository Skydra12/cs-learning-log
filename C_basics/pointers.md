# Pointers in C

## Pointer
A variable that stores the memory address of another variable
- & : Address-of operator (gives the address of a variable)
- \* : Dereference operator (access the value stored at the address)

## Why use Pointers?
- To allow functions to modify variables outside their scope
- To efficiently work with arrays and dynamic memory

## Example
```C
int x = 5;
int *p = &x; // p stores the address of x

printf("%d\n", x);   // 5
printf("%d\n", *p);  // 5
printf("%p\n", p);   // address of x
```
