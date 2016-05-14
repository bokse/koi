#include<stdio.h>

const int MN = 1000+5;
const int INF = 1e9;

int L, N;
int x[MN],y[MN];
int D[MN][MN];
int path[MN][MN];

int abs(int a){
    if(a<0)return -a;
    return a;
}
int dist(int i,int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

void trace(int i,int j){
    if(i==0 && j==1)return;

    if(i>j){
        if(i==j+1){
            trace(path[i][j],j);
        }
        else{
            trace(i-1,j);
        }
    }
    else{
        if(j==i+1){
            trace(i,path[i][j]);
        }
        else{
            trace(i,j-1);
        }
    }
    if(i>j){
        printf("1\n");
    }
    else{
        printf("2\n");
    }
}

int main(){
    scanf("%d%d",&L,&N);
    x[0]=y[0]=1;
    x[1]=y[1]=L;
    for(int i=2;i<=N+1;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    D[0][1]=0;
    D[0][0]=D[1][1]=D[1][0]=INF;
    for(int m=2;m<=N+1;m++){
        for(int i=0;i<m;i++){
            if(i+1==m){
                D[i][m]=INF;
                for(int j=0;j<i;j++){
                    if(D[i][m]>D[i][j]+dist(j,m)){
                        D[i][m]=D[i][j]+dist(j,m);
                        path[i][m]=j;
                    }
                }
            }
            else{
                D[i][m]=D[i][m-1]+dist(m-1,m);
            }
        }
        for(int i=0;i<m;i++){
            if(i+1==m){
                D[m][i]=INF;
                for(int j=0;j<i;j++){
                    if(D[m][i]>D[j][i]+dist(j,m)){
                        D[m][i]=D[j][i]+dist(j,m);
                        path[m][i]=j;
                    }
                }
            }
            else{
                D[m][i]=D[m-1][i]+dist(m-1,m);
            }
        }
    }
    int ans=INF;
    int p1,p2;
    for(int i=0;i<=N;i++){
        if(ans>D[i][N+1]){
            ans=D[i][N+1];
            p1=i,p2=N+1;
        }
        if(ans>D[N+1][i]){
            ans=D[N+1][i];
            p1=N+1,p2=i;
        }
    }
    printf("%d\n",ans);
    trace(p1,p2);
    return 0;
}
