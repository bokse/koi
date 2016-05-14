#include<stdio.h>
 
const int MN = 300+1;
 
int N;
int A[MN];
int D1[MN];
int D2[MN];
 
int max(int a,int b){
    if(a>b)return a;
    return b;
}
 
int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
    }
    D1[1]=A[1];
    for(int i=2;i<=N;i++){
        D1[i]=max(D1[i-2],D2[i-2])+A[i];
        D2[i]=D1[i-1]+A[i];
    }
    printf("%d\n",max(D1[N],D2[N]));
    return 0;
}
