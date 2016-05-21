#include<stdio.h>
typedef long long ll;
 
int K,N;
int A[100000];
 
int main(){
    scanf("%d%d",&K,&N);
    for(int i=0;i<K;i++){
        scanf("%d",&A[i]);
    }
    int ans=0;
    ll l=1,m,r=0x7fffffff;
    while(l<=r){
        m=(l+r)/2;
        ll num=0;
        for(int i=0;i<K;i++){
            num+=A[i]/m;
        }
        if(num>=N){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    printf("%d\n",ans);
    return 0;
}
