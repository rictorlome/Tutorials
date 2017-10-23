#include <cs50.h>
#include <stdio.h>
int main(void)
{
    printf("How much change is owed?");
    float ChangeLeft = get_float();
    if (ChangeLeft < 0) {
        printf("Please provide a non-negative amount of change.\n");
    } else {

    int NumberofQuarters = 0;
    while (ChangeLeft >= .25)
    {NumberofQuarters++;
    ChangeLeft = ChangeLeft - .25;
    }

    int NumberofDimes = 0;
    while (ChangeLeft >= .10)
    {NumberofDimes++;
    ChangeLeft = ChangeLeft - .10;
    }

    int NumberofNickels = 0;
    while (ChangeLeft >= .05)
    {NumberofNickels++;
    ChangeLeft = ChangeLeft - .05;
    }

    int NumberofPennies = 0;
    while (ChangeLeft >= .01)
    {NumberofPennies++;
    ChangeLeft = ChangeLeft - .01;
    };

    int TotalCoins = NumberofQuarters + NumberofDimes + NumberofNickels + NumberofPennies;
    printf("The change left is %f\n", ChangeLeft);
    printf("The number of quarters back is %i\n", NumberofQuarters);
    printf("The number of dimes back is %i\n", NumberofDimes);
    printf("The number of nickels back is %i\n", NumberofNickels);
    printf("The number of pennies back is %i\n", NumberofPennies);
    printf("The minimum number of coins back is %i\n", TotalCoins);
    }
}
