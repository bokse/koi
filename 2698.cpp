#include<stdio.h>

const int MN = 100+1;

int D[MN][MN][2];

int main(){
    D[1][0][0]=D[1][0][1]=1;
    for(int i=2;i<=100;i++){
        for(int k=0;k<=i-1;k++){
            for(int b2=0;b2<=1;b2++){
                for(int b1=0;b1<=1;b1++){
                    if(k-(b1*b2)>=0){
                        D[i][k][b2]+=D[i-1][k-(b1*b2)][b1];
                    }
                }
            }
        }
    }
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        int N,K;
        scanf("%d%d",&N,&K);
        printf("%d\n",D[N][K][0]+D[N][K][1]);
    }
    return 0;
}
