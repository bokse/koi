#include<stdio.h>
#include<algorithm>
using namespace std;

const int MN = 100000;

int N,M;
int A[MN];

int bsearch(int n){
	int l=0,r=N-1,m;
	while(l<=r){
		m=(l+r)/2;
		if(A[m]==n){
			return 1;
		}
		else if(A[m]<n){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int a;
		scanf("%d",&a);
		printf("%d\n",bsearch(a));
	}
	return 0;
}
