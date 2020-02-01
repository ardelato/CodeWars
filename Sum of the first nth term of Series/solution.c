#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *series_sum(const size_t n){
    // 1/ 2n + 1 
    char *value = malloc(sizeof(char)+7);
    double sum = 0;

    if (n == 0){
        sprintf(value,"%.2lf",0.00);
        printf("Value is %s\n",value);
        return value;
    }
    
    for(int i = 0; i < n; i++){
        sum += (1.0/(3*i+1));
    }
    sprintf(value,"%.2lf",sum);
    return value;
}