#include<stdio.h>

const int MN = 1000000+1;

int D[MN];
int N;

int main(){
    scanf("%d",&N);
    for(int i=2;i<=N;i++){
        D[i]=D[i-1]+1;
        if(i%3==0 && D[i]>D[i/3]+1){
            D[i]=D[i/3]+1;
        }
        if(i%2==0 && D[i]>D[i/2]+1){
            D[i]=D[i/2]+1;
        }
    }
    printf("%d\n",D[N]);
    return 0;
}
