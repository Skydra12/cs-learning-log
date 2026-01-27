# Pointers in C

## Pointer
A variable that stores a memory address
- & : Address-of operator(gives the address)
- * : Deference operator(value stored at address points to)

```C
int x = 5;
int *p = &x; //p stores the address of x

printf("%d\n", x);   // 5
printf("%d\n", *p);  // 5
