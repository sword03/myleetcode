//
// Created by testuser0 on 9/13/18.
//

#ifndef LEETCODE_TWOSUM1_H
#define LEETCODE_TWOSUM1_H
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int* result = malloc(sizeof(int) * 2);
    for( i = 0; i < numsSize; i++ ){
        for( j = i + 1 ; j < numsSize; j ++ ){
            if( nums[i] + nums[j] == target )
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
#endif //LEETCODE_TWOSUM1_H
