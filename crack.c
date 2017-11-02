// program brute force cracks password composed of 4 alphabetic (lower or upper case) characters, encrypted using the DES-based algorithm.
// input is hashed password in command line, output is password.

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string hash = argv[1];
        //for the DES based algo, the salt is the first two characters of the hash.
        char salt[3] = { hash[0], hash[1], '\0'};

        for (int i = 65; i>= 65 && i<=122; i++) //loop through first letter of pass
        {
            for (int j = 65; j>=65 && j<=122; j++) // loop through second letter of pass
            {
                for (int k = 65; k>=65 && k<=122; k++) // loop through third letter of pass
                {
                    for (int l = 65; l>=65 && l<=122; l++) // loop through fourth letter of pass
                    {
                        char pass[5] = { (char) i, (char) j , (char) k, (char) l, '\0'}; // set pass to ASCII value
                        string check = crypt(pass, salt);
                        int ret = strcmp(check, hash); // use strcmp to compare strings (returns 0 when they are equal)
                        if (ret == 0)
                        {
                            printf("%s\n", pass);
                            return 0;
                        }
                    }
                }
            }
        }


    }
    else
    {
        printf("Please include a hashed alphabetic 4 char password as a command line argument.\n");
        return 1;
    }
}
