#include<stdio.h>
#include<algorithm>
using namespace std;

const int MN = 10000 + 5;

int N, M;
int n1,n2;
int A[MN],B[MN];
int maxv;

int calc(int *A,int n){
	int val = 0;
	sort(A,A+n);
	for(int i=n-1;i>=0;i-=M){
		val += 2*A[i];
	}
	return val;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		if(x<0){
			A[n1++]=-x;
			if(maxv<-x) maxv=-x;
		}
		else{
			B[n2++]=x;
			if(maxv<x) maxv=x;
		}
	}
	printf("%d\n",calc(A,n1)+calc(B,n2)-maxv);
	return 0;
}
