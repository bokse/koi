#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MN = 100000;
const int INF = 1000000000;

int N,M;

struct DATA{
	int index, dist;
	DATA(){}
	DATA(int index,int dist):index(index),dist(dist){}
	bool operator <(DATA A)const{
		return dist>A.dist;
	}
};
vector<DATA> E[MN];
int dist[MN];

void dijkstra(int s,int *d){
	for(int i=0;i<N;i++)d[i]=INF;
	d[s]=0;
	priority_queue<DATA> que;
	for(int i=0;i<N;i++)que.push(DATA(i,d[i]));

	while(!que.empty()){
		DATA h = que.top();
		que.pop();
		if(h.dist!=d[h.index]){
			continue;
		}
		for(DATA &e:E[h.index]){
			if(d[e.index] > h.dist + e.dist){
				d[e.index] = h.dist + e.dist;
				que.push(DATA(e.index, d[e.index]));
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	int st;
	scanf("%d",&st);--st;
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);--a,--b;
		E[a].push_back(DATA(b,c));
	}
	dijkstra(st,dist);
	for(int i=0;i<N;i++){
		if(dist[i]==INF){
			puts("INF");
		}
		else{
			printf("%d\n",dist[i]);
		}
	}
	return 0;
}
