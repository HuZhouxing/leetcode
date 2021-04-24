#include<stdio.h>
int findMin(int* nums, int numsSize);

int main(){
    // int nums[7] = {3,4,5,6,7,1,2};
    int nums[5] = {2,3,4,5,1};
    int x = findMin(nums,5);
}

int findMin(int* nums, int numsSize){

    //1 input case
    if (numsSize == 1){
        return *nums;
    }



    int left,right,midLeft,midRight,ret;

    left = 0;
    right = numsSize-1;
    midLeft = (left+right)/2;
    midRight = midLeft+1;




    while(right-left>2){

        if (nums[left] > nums[midLeft]){  //left issue
            right = midLeft;
        }

        if (nums[right] < nums[midRight]){  //right issue
            left = midRight;
        }

        if (nums[left]<nums[midLeft] && nums[midRight]<nums[right]){
            ret = nums[midRight];
            break;
        }

        midLeft = (left+right)/2;
        midRight = midLeft+1;
    }
    
    return ret;
}