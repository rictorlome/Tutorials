// encrypts string s with key based on command line argument input from user.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//define concat for later use.
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


//takes string arguments in the command line, sets argc to # of arguments
int main(int argc, string argv[])
{
  // if the argument count == 2
  if (argc == 2)
  {
     // gets a string from the user, assigns it to s
     printf("Please input the plaintext string you would like to encrypt: ");
     string s = get_string();
     if (s != NULL)
     {
         //assigns the string argument input into command line to be the key
         string key = argv[1];

         //create variable repeatedKey whose length >= s's length
         string repeatedKey = key;
         while (strlen(repeatedKey) < strlen(s))
         {
             repeatedKey = concat(repeatedKey, key);
         }

         //loops through the characters of the plaintext string, s
         for (int i = 0, n = strlen(s); i < n; i++)
         {
             // if the character is uppercase
             if (s[i] >= 65 && s[i] <= 90)
             {
                // reduces ASCII range of A-Z in s to 0-26, so that mod 26 keeps values within range
                int reducedValue = s[i] - 65;
                // first makes repeatedKey case insensitive, then reduces ASCII range of repeatedKey, for same reason as above
                int reducedUppercaseRepeatedKey = toupper(repeatedKey[i]) - 65;
                // increases ASCII value by the reduced value of the repeatedKeyUpper
                int encryptedReducedValue = (reducedValue + reducedUppercaseRepeatedKey) % 26;
                // resets ASCII range to proper values
                int encryptedValue = encryptedReducedValue + 65;
                printf("%c", encryptedValue);
             }
             // if the character is lowercase
             else if (s[i] >= 97 && s[i] <= 122)
             {
                // reduces ASCII range of a-z to 0-26, so that mod 26 keeps values within range
                int reducedValue = s[i] - 97;
                // first makes repeatedKey case insensitive, then reduces ASCII range of repeatedKey, for same reason as above
                int reducedUppercaseRepeatedKey = toupper(repeatedKey[i]) - 65;
                // increases ASCII value by the by the reduced value of the repeatedKeyUpper
                int encryptedReducedValue = (reducedValue + reducedUppercaseRepeatedKey) % 26;
                // resets ASCII range to proper values
                int encryptedValue = encryptedReducedValue + 97;
                printf("%c", encryptedValue);
             }


         }
     // breaks the line and returns 0 to exit main
     printf("\n");
     return 0;

     }

  }
  // if more or less than 2 arguments are input to the commandline, exit main with an error
  else
  {
      printf("Please provide one string as a command line argument\n");
      return 1;
  }


}
