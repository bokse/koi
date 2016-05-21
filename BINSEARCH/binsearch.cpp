#include<stdio.h>

int A[]={1,3,3,4,4,5,5,10};
int N = 8;
int bsearch(int n){
	int l=0,r=N-1,m;
	while(l<=r){
		m=(l+r)/2;
		if(A[m]==n){
			return m;
		}
		else if(A[m]<n){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return -1;
}

int main(){
	printf("%d ",bsearch(4));
	printf("%d\n",bsearch(11));
	return 0;
}
