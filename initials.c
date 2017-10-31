#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Please input your full name: ");
    string s = get_string();
    if (s != NULL)
    {
      char f = toupper(s[0]); 
      printf("%c", f); // prints first letter, in uppercase
      for (int i = 0, n = strlen(s); i < n; i++)
      {
          if (s[i] == ' ')
          {
              char x = toupper(s[i+1]);
              printf("%c", x); //prints every letter after a space, in uppercase
          }
      }
      printf("\n");
    }
}
