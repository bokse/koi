#include<vector>
using namespace std;

vector<int> E[MN];

a,b
E[a].push_back(b);
E[b].push_back(a);

void tree(int n){
	for(int p=son[n]; p!=-1; p=bro[p]){
		tree(p);
	}
}

int chk[MN];
int parent[MN],son[MN],bro[MN];
void dfs(int n){
	chk[n]=1;
	for(auto &t:E[n]){
		if(chk[t]==0){
			bro[t]=son[n];
			son[n]=t;
			dfs(t);
		}
	}
}
dfs(0);
