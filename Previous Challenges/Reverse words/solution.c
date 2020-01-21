#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *reverseWords(const char *text)
{
    // <---- hajime!
    char *revText = malloc((strlen(text) + 1) * sizeof(char));
    char *temp = malloc((strlen(text) + 1) * sizeof(char));
    char *found;

    revText[0] = '\0';
    strcpy(temp, text);

    while ((found = strsep(&temp, " ")) != NULL)
    {
        int wLength = strlen(found);
        char *tempWord = malloc(wLength + 1);
        for (int i = 0; i < wLength; i++)
        {
            tempWord[wLength - i - 1] = found[i];
        }
        tempWord[wLength] = '\0';
        strcat(revText, tempWord);
        strcat(revText, " ");
        free(tempWord);
    }
    return revText;
}

// Best Solutions
/*
#include <stdlib.h>

char* reverseWords(const char* text) {
  char *ret = calloc(strlen(text) + 1, sizeof(char)), *q = ret;
  int wordlen = 0;
  for (char *p = text; ; p++) {
    if (*p == ' ' || *p == '\0') {
      for (int i = 0; i < wordlen; i++) *q++ = *(p - 1 - i);
      if ((*q++ = *p) == '\0') break;
      wordlen = 0;
    } else wordlen++;
  }
  return ret;
}
*/

/*
#include <stdlib.h>

char* reverseWords(const char* text) {
int pos = 0, len = strlen(text);
char* cop = malloc((len+1)*sizeof(char));

for (int i=0; i<len; i++){
  if (text[i] == ' '){
    cop[i]= text[i];
    for(int j=0; j<i-pos; j++) cop[pos+j]=(text[i-1-j]);
    pos=i+1;
  }
}

for(int j=0; j<len-pos; j++) cop [pos+j] = (text[len-1-j]);
cop[len]='\0';
return cop;
}
*/