#include<vector>
using namespace std;

int chk[100];
vector<int> E[100];

void dfs(int n){
	chk[n]=1;
	for(int i=0;i<E[n].size();i++){
		if(chk[E[n][i]]==0){
			dfs(E[n][i]);
		}
	}
}
