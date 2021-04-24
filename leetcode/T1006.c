#include<stdio.h>
int clumsy(int N);

int main(){
    int x = 10;
    int y = clumsy(7);
    printf("%d",y);
}

int clumsy(int N){

    //case N<4
    switch (N)
    {
    case 1:return 1;break;
    case 2:return 2;break;
    case 3:return 6;break;
    case 4:return 7;break;
    }

    //case N>=4
    int headSeg = N*(N-1)/(N-2)+(N-3),ret = 0;
    int opNum[4] = {N-4,N-5,N-6,N-7};
    while(opNum[0] >= 4){
        ret -= opNum[0]*opNum[1]/opNum[2]-opNum[3]; // -(-opNum[3] => +opNum[3])
        for (int i = 0;i<4;i++){
            opNum[i] -= 4;
        }
    }

    //tail part
    switch (opNum[0])
    {
    case 0:return headSeg + ret;break;
    case 1:return headSeg + ret -1;break;
    case 2:return headSeg + ret -2;break;
    case 3:return headSeg + ret -6;break;
    }

}
 


