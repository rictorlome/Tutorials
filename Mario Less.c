#include <cs50.h>
#include <stdio.h>
void repeat(int n, string X);
int main(void)
{
    printf("What is the half-pyramid's height?\n");
    int h = get_int();
    if (h < 0 || h > 23) {
        printf("Please pick an integer between 0 and 23\n");
    } else {
        for (int k = 0; k < h; k++) {
            repeat(-k + h - 1, " "); // Prints 'space' height - (1 + k) times
            repeat(k + 2, "#");      // Prints '#' k + 2 times
            printf("\n");
        }
            }
}

void repeat(int n, string X) // Given a number 'n' and a char 'X', repeatedly print the 'item' 'n' times.
{
    for (int i = 0; i < n; i++) {
        printf("%s", X);
    }
}
