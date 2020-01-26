#include <stdio.h>
#include <stdlib.h>

int nbDig(int n, int d)
{
    // your code
    int digits = 0;
    for (int i = 0; i <= n; i++)
    {
        int power = i * i;
        while (power != 0)
        {
            if (power % 10 == d)
            {
                digits += 1;
            }
            power /= 10;
        }
    }
    if (d == 0)
        digits++;
    return digits;
}

//Best Solutions

// My last line of code was added a ternary operator/starting point
/*
int nbDig(int n, int d) {
  int count = (d == 0) ? 1 : 0;
  
  for (int k = 1; k <= n; k++) {
    int kk = k * k;
    while (kk != 0) {
      if (kk % 10 == d)
        count++;
      kk /= 10;
    }
  }
  
  return count;
}
*/

// Very similar idea
/*
int nbDig(int n, int d) {
  int i, c = 0, val;
  for(i=0; i <= n; i++)
   {
      val=i*i;
       while (val > 0) 
       {
        if((val % 10) == d) c++;
        val /= 10;
       }
    } 
    if(val == d) c++;
    return c;
}
*/