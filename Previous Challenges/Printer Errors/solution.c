
char* printerError(char *s) {
    // your code
    int errors = 0,length = strlen(s);
    char *err_msg = malloc(10*sizeof(char));  
    
    for(int i=0; i<length;i++){
      if(s[i] >= 'n')
        errors++;
    }
    sprintf(err_msg,"%d/%d",errors,length);
    return err_msg;
}
// Best Solutions

// asprintf() is similar to sprintf, but will allocate enough memory including the null terminator to the passed string
/*
char* printerError(char *s) {
  
  int c = 0;
  int len = strlen(s);
  char *r;
  
  while(*s){
    if (*s < 'a' || *s > 'm') c++;
    s++;
  }
  
  asprintf(&r, "%d/%d", c, len);
  
  return r;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

char* printerError(char *s) {
    char *res = (char*)malloc(sizeof(char) * 80);
    int countError = 0;
    int lg = 0;
    while (*s) {
        if(*s < 'a' || *s > 'm')
            countError++;
        s++;
        lg++;
    }
    sprintf(res, "%d/%d", countError, lg);
    return res;
}
*/