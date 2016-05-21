#include<stdio.h>
#include<algorithm>
using namespace std;

int A[]={10,3,4,5,9,2,7,6,1,8};
int N=10;

int main(){
	sort(A,A+N);
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	return 0;
}


