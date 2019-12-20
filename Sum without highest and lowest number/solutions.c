#include <stdlib.h>

int sum(int* numbers, int numbersCount)
{
  int min, max, sum = 0;
  if (numbersCount <= 1 || numbers == NULL) return 0;
  min = max = numbers[0];

  for(int i = 0; i < numbersCount;i++){
      if(min > numbers[i]){
          min = numbers[i];
      }
      else if (max < numbers[i]){
          max = numbers[i];
      }
      sum += numbers[i];
  }
  return sum - min - max;
}

// Best Solutions
/*
int sum(int* numbers, int numbersCount){
  int max=numbers[0], min=numbers[0], sum=numbers[0];
  if (numbersCount < 2) return 0;
  for(int i = 1; i < numbersCount; i++){
  sum += numbers[i];
  if(max < numbers[i]) max = numbers[i];
  if(min > numbers[i]) min = numbers[i];
  }
  
  return sum - min - max;
}
*/

/*
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int sum(int* numbers, int numbersCount)
{
  qsort(numbers, numbersCount, sizeof(int), cmpfunc);
  int sum = 0;
  for(int i = 1; i < numbersCount - 1; ++i)
      sum += numbers[i];
  return sum;
}
*/