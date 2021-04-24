#include<stdio.h>
#define uint32_t unsigned int

uint32_t reverseBits(uint32_t n);

int main(void){
    uint32_t n = 4294967293;
    int x = reverseBits(n);
}

uint32_t reverseBits(uint32_t n) {
    
    uint32_t ret = 0;
    for (int i = 32-1;i>=0;i--){
        ret |= ((n&1)<<i);
        n = n>>1;
    }   

    return ret;
}