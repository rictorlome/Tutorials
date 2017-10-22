#include <cs50.h>
#include <stdio.h>

void hash_row(int n);

int main(void)
{
    printf("What is the half-pyramid's height?");
    int h = get_int();
    if (h < 1 || h > 23) {
        printf("Please pick an integer between 1 and 23\n");
    } else {hash_row(h);}

}
void hash_row(int n)
{
    for (int i = 0; i < n; i++) {
        printf("#");
    }
}
