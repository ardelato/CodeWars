#include <stddef.h>

int find_missing(const int *nums, size_t n)
{
    int actualSum, expectedSum;
    // Gauss Formula
    expectedSum = ((n+1)/2.0)*(nums[0]+nums[n-1]);
    
    actualSum = 0;
    for(int i = 0; i < n; i++){
        actualSum += nums[i];
    }
    return expectedSum-actualSum;
}

//Best Solutions

/*
#include <stddef.h>

int find_missing(const int *nums, size_t n)
{
    int sum = (n+1)*(nums[0]+nums[n-1]) / 2;
    for (int i = 0; i < n; ++i)
        sum -= nums[i];
        
    return sum;
}
*/

/*
#include <stddef.h>

int find_missing(const int *nums, size_t n)
{
    int diff = (nums[n-1] - nums[0])/(int) n;
    if(diff == 0){
        return nums[0];
    }else{
        for(size_t i = 0; i < n-1; i++){
            if(nums[i] + diff != nums[i+1]){
                return nums[i]+diff;
            }
        }
    }
    return 0;
}
*/