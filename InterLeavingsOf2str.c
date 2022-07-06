// C program to print all interleavings of given two strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printIlsRecur (char *str1, char *str2, char *iStr, int m,
          int n, int i)
{
  if (m==0 && n==0)
    printf("%s\n", iStr) ;
  if (m != 0)
  {
    iStr[i] = str1[0];
    printIlsRecur (str1 + 1, str2, iStr, m-1, n, i+1);
  }
  if (n != 0)
  {
    iStr[i] = str2[0];
    printIlsRecur(str1, str2+1, iStr, m, n-1, i+1);
  }
}

void printIls (char *str1, char *str2, int m, int n)
{
char *iStr= (char*)malloc((m+n+1)*sizeof(char));
iStr[m+n] = '\0';
printIlsRecur (str1, str2, iStr, m, n, 0);
free(iStr);
}

// Driver program to test above functions
int main()
{
  char str1[] = "AB";
  char str2[] = "CD";
  printIls (str1, str2, strlen(str1), strlen(str2));
  return 0;
}

