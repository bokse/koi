#include<bits/stdc++.h>
using namespace std;

const int MN = 10000;

int N;
vector<int> E[MN], sons[MN];

int chk[MN];
int D[MN][MN];

void dfs(int n){
	chk[n]=1;
	for(auto &p:E[n])if(chk[p]==0){
		sons[n].push_back(p);
		dfs(p);
	}
	for(auto &p:sons[n]){
	}
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--, b--;
	}
	setting(0);
	dfs(0);
	return 0;
}
