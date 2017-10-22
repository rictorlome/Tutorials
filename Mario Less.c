#include <cs50.h>
#include <stdio.h>

void hash_row(int n);

int main(void)
{
    printf("What is the half-pyramid's height?");
    int h = get_int();
    if (h < 1 || h > 23) {
        printf("Please pick an integer between 1 and 23\n");
    } else {
        for (int k = 0; k < h; k++) {
        hash_row(k);
        printf("\n");
        }
    }

}
void hash_row(int n)
{
    for (int i = 0; i <= n + 1; i++) {
        printf("#");
    }
}
