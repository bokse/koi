#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long ll;

const int MN = 100000;
const int INF = 1000000000;

int N,T;
int A[MN], arr[MN], ans[MN];

bool test(int diff){
	int lim=INF;
	for(int i=0;i<N;i++){
		lim = min(lim, A[i]);
		arr[i] = lim;
		lim += diff;
	}
	lim=INF;
	for(int i=N-1;i>=0;i--){
		lim = min(lim, A[i]);
		arr[i] = min(arr[i], lim);
		lim += diff;
	}
	ll dsum = 0;
	for(int i=0;i<N;i++){
		dsum += A[i]-arr[i];
	}
	return dsum <= T;
}

int main(){
	scanf("%d%d",&N,&T);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	int l=0,r=INF,m;
	while(l<=r){
		m=(l+r)/2;
		if(test(m)){
			for(int i=0;i<N;i++)ans[i]=arr[i];
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	for(int i=0;i<N;i++)printf("%d ",ans[i]);
	return 0;
}
