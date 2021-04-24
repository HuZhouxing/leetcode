#include<stdio.h>
#include<stdlib.h>
#define bool int

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);

int main(void){
    //int matrix[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int matrix1[4] = {1,3,5,7};int matrix2[4] = {10,11,16,20};int matrix3[4] = {23,30,34,60};
    int *matrix[3] = {matrix1,matrix2,matrix3};
    int target = 3;
    int matrixSize  = 12;
    int matrixColSize[2] = {3,4};
    searchMatrix(matrix,matrixSize,matrixColSize,13);

}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){



    //get m,n
    int m = matrixSize;//m*n matrix
    int n = matrixColSize[0];
    
    if (m==0 || n==0){
        return 0;
    }

    //init low and high and mid
    int low[2] = {0,0};
    int mid[2] = {0,0};
    int high[2] = {m-1,n-1};

    low[0] = 0;low[1] = 0;
    high[0] = m-1;high[1] = n-1;
    mid[0] = 0;mid[1] = 0;


    int x = matrix[0][0];//test


    //test weather low or high == target
    if (matrix[low[0]][low[1]] == target || matrix[high[0]][high[1]] == target){
        return 1;
    }

    //transform 2dim to 1dim
    int lowArrayIndex = low[0]*n+low[1];
    int highArrayIndex = high[0]*n+high[1];
    int midArrayIndex = (lowArrayIndex+highArrayIndex)/2;

    mid[0] = midArrayIndex/n;
    mid[1] = midArrayIndex%n;

    //binary search
    while (highArrayIndex - lowArrayIndex > 1){

        //mid == target
        if (matrix[mid[0]][mid[1]] == target){
            return 1;
        }

        //mid > target
        if (matrix[mid[0]][mid[1]]>target){
            high[0] = mid[0];
            high[1] = mid[1];
            highArrayIndex = midArrayIndex;

            midArrayIndex = (lowArrayIndex+highArrayIndex)/2;
            mid[0] = midArrayIndex/n;
            mid[1] = midArrayIndex%n;
        }

        //mid < target
        if (matrix[mid[0]][mid[1]]<target){
            low[0] = mid[0];
            low[1] = mid[1];
            lowArrayIndex = midArrayIndex;

            midArrayIndex = (lowArrayIndex+highArrayIndex)/2;
            mid[0] = midArrayIndex/n;
            mid[1] = midArrayIndex%n;
        }

    }
    return 0;

}

