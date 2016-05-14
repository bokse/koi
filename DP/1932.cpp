#include<stdio.h>
 
const int MN = 500+1;
 
int N;
int A[MN][MN];
int D[MN][MN];
 
int max(int a,int b){
    if(a>b)return a;
    return b;
}
 
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)for(int j=0;j<=i;j++){
        scanf("%d",&A[i][j]);
    }
    D[0][0]=A[0][0];
    for(int i=1;i<N;i++)for(int j=0;j<=i;j++){
        if(j==0){
            D[i][j]=D[i-1][j]+A[i][j];
        }
        else{
            D[i][j]=max(D[i-1][j],D[i-1][j-1])+A[i][j];
        }
    }
    int ans=0;
    for(int j=0;j<N;j++){
        if(ans<D[N-1][j]){
            ans=D[N-1][j];
        }
    }
    printf("%d\n",ans);
    return 0;
}
