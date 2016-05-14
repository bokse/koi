#include<stdio.h>
 
const int MN = 1000+1;
 
int N;
int A[MN];
int D[MN];
 
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&A[i]);
    D[0]=1;
    for(int i=1;i<N;i++){
        D[i]=1;
        for(int j=0;j<i;j++){
            if(A[j]<A[i] && D[i]<D[j]+1){
                D[i]=D[j]+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<N;i++){
        if(ans<D[i]){
            ans=D[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
