#include<stdio.h>

const int MN = 100;

int N;
int dist[MN][MN];

int main(){
	//dist[i][j] = edge exists -> cost for i->j
	//				not exists -> INF
	//dist[i][i] = 0
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	return 0;
}
