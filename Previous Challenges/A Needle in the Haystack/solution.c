#include <stddef.h>
#include <stdio.h>

char *find_needle(const char **haystack, size_t count){
  int index = 0;
  char *needleStr;

  while(index < count-1){
    if(strcmp(haystack[index],"needle") == 0){
       asprintf(&needleStr,"found the needle at position %d",index);
       return needleStr;
    }
    ++index;
  }
  asprintf(&needleStr,"found the needle at position %d",index);
  return needleStr;
}

// Best Solutions
/*
#include <stdio.h>

char *find_needle(const char **haystack, size_t count)
{
  for(int i=0; i<count;++i)
  {
    if(!strcmp(haystack[i], "needle")) // strcmp will return 0 if true, so we need '!' to it to work
    {
      char* buff;
      asprintf(&buff, "found the needle at position %d", i);
      return buff;
    }
  }
}
*/
/*
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *find_needle(const char **haystack, size_t count)
{
  while (strcmp(haystack[--count], "needle"));
  char *buf = malloc(128);
  sprintf(buf, "found the needle at position %d", count);
  return buf;
}
*/