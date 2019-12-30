#include <ctype.h>
#include <string.h>
#include <stdio.h>

char *solve(const char *str)
{
    int lowerCase, upperCase;
    char *rtrStr = malloc(strlen(str)+1);
    char *temp = str;
    
    strcpy(rtrStr,str);
    lowerCase = upperCase = 0;

    while(*temp != '\0'){
      islower(*temp)?lowerCase++:upperCase++;
      temp++;
    }
   
    if(lowerCase>=upperCase){
        for(int i = 0; i < strlen(rtrStr); i++){
            rtrStr[i] = tolower(rtrStr[i]);
        }
    }   
    else{
     for(int i = 0; i < strlen(rtrStr); i++){
            rtrStr[i] = toupper(rtrStr[i]);
        }
    }
    
    return rtrStr;
}

// Best Solutions

//Creates two strings, and only returns the one needed for the conditional and frees the other, this only iterating once at the cost of memory
/*
char *solve(const char *str)
{
   unsigned int upper_cnt = 0;
   unsigned int sz = strlen(str);
   char *upper = calloc(sz + 1, sizeof(char)), *lower = calloc(sz + 1, sizeof(char));
   for (int i = 0; i < sz; i++)
   {
      if (isupper(str[i])) upper_cnt ++;
      upper[i] = toupper(str[i]);
      lower[i] = tolower(str[i]);
   }
   if (upper_cnt > sz/2)
   {
      free(lower);
      return upper;
   }
   free(upper);
   return lower;
}
*/
/*
#include <stdbool.h>

char *solve(const char *str)
{
  int hi = 0;
  for (char *p = str; *p; p++) if (isupper(*p)) hi++;
  char *r = strdup(str);
  bool upper = strlen(r) < 2 * hi;
  for (char *p = r; *p; p++) *p = upper ? toupper(*p) : tolower(*p);
  return r;
}
*/