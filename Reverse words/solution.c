#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* reverseWords(const char* text) {
    // <---- hajime!
    char *revText = malloc((strlen(text)+1)* sizeof(char));
    char *temp = malloc((strlen(text)+1) * sizeof(char));
    char *found;

    revText[0] = '\0';    
    strcpy(temp,text);

    while((found = strsep(&temp," ")) != NULL ){
        int wLength = strlen(found);
        char *tempWord = malloc(wLength+1);
        for(int i = 0; i < wLength; i++){
            tempWord[wLength-i-1] = found[i];
        }
        tempWord[wLength] = '\0';
        strcat(revText,tempWord);
        strcat(revText," ");
        free(tempWord);
    }
    return revText;
}