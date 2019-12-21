#include <stdlib.h> 
#include <stdio.h>

int* parse(char* program)
{
  // TODO: your code here!
  int *iArray = malloc(5*sizeof(int));
  int count, currVal,size = 5;
  count = currVal = 0;

  for(;*program != '\0';program++){
      switch (*program)
      {
      case 'i':
        currVal++;        
        break;
      case 'd':
        currVal--;
        break;
      case 's':
        currVal *= currVal;
        break;
      case 'o':
        if(count >= size){
            iArray = realloc(iArray, 2*size*sizeof(int));
            size *= 2;
        }
        iArray[count] = currVal;
        count++;
      }
  }
  return realloc(iArray,sizeof(int)*(count));
}

//Best Solutions
/*
int* count_outputs(char *program)
{
  int outputs = 0;
  
  char c;
  while (c = *program++)
  {
    if (c == 'o') 
    {
      ++outputs;
    }
  }
  
  return outputs;
}

int* parse(char* program)
{
  int val = 0;
  int result_len = count_outputs(program);
  int *result = malloc(result_len * sizeof(int));
  int outputPos = 0;
  
  char c;
  while (c = *program++) 
  {
    if (c == 'i') { ++val; }
    else if (c == 'd') { --val; }
    else if (c == 's') { val *= val; }
    else if (c == 'o') { result[outputPos++] = val; }
  }
  
  return result;
}
*/

/*
int* parse(char* program) {
    int val = 0, j = 0;
    int * res = malloc(sizeof(int) * strlen(program));
    for (int i = 0; i < strlen(program); ++i) {
        switch (program[i]) {
            case 'i': ++val; break;
            case 'd': --val; break;
            case 's': val *= val; break;
            case 'o': res[j] = val; ++j; break;
        }
    }
    return res;
}
*/
