#include <cs50.h>
#include <stdio.h>

int fibonacci(int c)
{
    if (c == 0) {
        return 0;
    }

    if (c == 1) {
        return 1;
    }
    return fibonacci(c-1) + fibonacci(c-2);
}

int main(void)
{
    printf("How many elements of the Fibonacci Sequence would you like printed?:   ");
    int n = get_int();

    for (int i=0; i<=n-1; i++) {
        printf("%d\n", fibonacci(i));
    }
    return 0;
}
