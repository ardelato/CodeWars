#include <stdlib.h>

int* race(int v1, int v2, int g) {
    int carrier;
    int *time = calloc(3,sizeof(int));

    printf("V1 %d V2 %d G %d\n",v1,v2,g);
    
    if (v1 >= v2){
      time[0] = -1;
      time[1] = -1;
      time[2] = -1;
      return time;
    }
    
    carrier = 1.0 * g /(v2-v1) * 60 * 60;
    time[0] = carrier / 60 / 60;
    printf("Hour %d\n",time[0]);
    time[1] = carrier / 60 % 60;
    printf("Minute %d\n",time[1]);
    time[2] = carrier % 60;
    printf("Seconds %d\n",time[2]);
    return time;
}

// Best Solutions
/*
#include <stdlib.h>

int* race(int v1, int v2, int g) {
    int* res = malloc(3*sizeof(int));
    res[0] = res[1] = res[2] = -1;
    if(v1 < v2) {
        long long tmp = 3600*g/(v2 - v1);
        res[0] = tmp / 3600;
        res[1] = (tmp % 3600) / 60;
        res[2] = tmp % 60;
    }
    return res;
}
*/

/*
#include <stdlib.h>

int* race(int v1, int v2, int g)
{
    int *result = (int *) malloc(3 * sizeof(int));
    if (! result)
        return NULL;
    if (v1 >= v2)
    {
        result[0] = result[1] = result[2] = -1;
        return result;
    }
    int time = 1.0 * g / (v2 - v1) * 60 * 60;
    result[0] = time / 60 / 60;
    result[1] = time / 60 % 60;
    result[2] = time % 60;
    return result;
}
*/