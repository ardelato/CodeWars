#include <string.h>

char *repeat_str(size_t count, const char *src) {
  char *str;
  char *temp;

  if((str = calloc((strlen(src)+1)*count,count)) == NULL){
   perror(NULL);
   exit(1);
  }
  temp = str;

  for(int i=0;i<count;i++){
    memcpy(temp,src,strlen(src));
    temp += strlen(src);
  }
  return str;   
}

// Best Solutions

// Does not handle null termination vv
/*
#include <string.h>

char *repeat_str(size_t count, const char *src) {
  int length = strlen(src);
  char* dest = malloc(count * length * sizeof(char));
  for (int i = 0; i < count; i++) {
    strcpy(dest + i * length, src);
  }
  return dest;
}
*/

/*
#include <string.h>
#include <stdlib.h>

char * repeat_str( size_t n, const char * s ) {
  size_t slen = strlen(s);
  char * dest = malloc(n*slen+1);
  int i; char * p;
  for ( i = 0, p = dest; i < n; ++i, p += slen ) {
      memcpy(p, s, slen);
  }
  *p = '\0';
  return dest;
}
*/