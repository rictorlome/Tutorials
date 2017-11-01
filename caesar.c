#include <cs50.h>
#include <stdio.h>
#include <string.h>

//takes string arguments in the command line, sets argc to # of arguments
int main(int argc, string argv[])
{
  // if the argument count == 2
  if (argc == 2)
  {
     // gets a string from the user, assigns it to s
     printf("Please input the string you would like to encrypt: ");
     string s = get_string();

     //locates the number in the string argument input into command line
     char *ptr;
     int key;
     key = strtol(argv[1], &ptr, 10);

     //loops through the characters of the plaintext string, s
     for (int i = 0, n = strlen(s); i < n; i++)
     {
         // if the character is uppercase
         if (s[i] >= 65 && s[i] <= 90)
         {
            int reducedValue = s[i] - 65;
            int encryptedReducedValue = (reducedValue + key) % 26;
            int encryptedValue = encryptedReducedValue + 65;
            printf("%c", encryptedValue);
         }
         // if the character is lowercase
         else if (s[i] >= 97 && s[i] <= 122)
         {
            int reducedValue = s[i] - 97;
            int encryptedReducedValue = (reducedValue + key) % 26;
            int encryptedValue = encryptedReducedValue + 97;
            printf("%c", encryptedValue);
         }
         //for each character in s, prints the character with ascii increased by ...
         //printf("%c plus %i gives %c\n", s[i], ret, s[i]+ret);
     }
     // breaks the line and returns 0 to exit main
     printf("\n");
     return 0;
  }
  // if more or less than 2 arguments are input to the commandline, exit main with an error
  else
  {
      printf("Please provide one non-negative integer as a command line argument\n");
      return 1;
  }
}
