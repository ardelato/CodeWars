#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_bang(const char *s) {
    char *str = malloc(strlen(s) + 2);
    char *temp = s;
    char *pt = str;
    while(*temp != '\0'){
        if(*temp != '!'){
            *pt = *temp;
            pt++;
        }
        temp++;
    }
    *pt++ = '!';
    *pt = '\0';
    return str;
}

// Having problems running this program from this computer, and it running fine on the CodeWars environment

//Best Solutions
// Iterates each character and only adds characters that are not an '!', since it will be added to the end
// of every word
/*
char* remove_bang(char* s)
{
    int wPos = 0;
    char *sOut = malloc(strlen(s) * sizeof(char));
    while(*s != '\0'){
       if(*s != '!')
          sOut[wPos++] = *s;
       s++;
    }
    sOut[wPos++] = '!';
    sOut[wPos]   = '\0';
    return sOut;
}
*/
/*
#include <stdlib.h>
#include <string.h>

char* remove_bang(char* original)
{
    char* modified = (char*) malloc(strlen(original) + 2), *m = modified, c;
    while((c = *original++) != 0)
        if(c != '!')
            *m++ = c;
    *m++ = '!';
    *m = 0;
    return modified;
}
*/

