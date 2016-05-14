#include<stdio.h>
 
const int MN = 20+1;
 
int N,L;
int A[MN][MN];
int D[MN][MN][MN][MN][MN];
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
 
int main(){
    scanf("%d%d",&N,&L);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        scanf("%d",&A[i][j]);
    }
    if(L%2){
        for(int i=0;i<N;i++)for(int j=0;j<N;j++){
            D[i][j][i][j][1]=1;
        }
    }
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<8;k++){
                    int ni=i+dx[k],nj=j+dy[k];
                    if(ni<0 || nj<0 || ni>=N || nj>=N)continue;
                    if(A[i][j]!=A[ni][nj])continue;
                    D[i][j][ni][nj][2]=1;
                }
            }
        }
    }
    for(int len=L%2+2;len<=L;len+=2){
        for(int i=0;i<N;i++)for(int j=0;j<N;j++){
            for(int k=0;k<N;k++)for(int l=0;l<N;l++){
                if(A[i][j]!=A[k][l])continue;
                for(int k1=0;k1<8;k1++)for(int k2=0;k2<8;k2++){
                    int ni=i+dx[k1],nj=j+dy[k1];
                    int nk=k+dx[k2],nl=l+dy[k2];
                    if(ni<0 || nj<0 || ni>=N || nj>=N)continue;
                    if(nk<0 || nl<0 || nk>=N || nl>=N)continue;
                    D[i][j][k][l][len]+=D[ni][nj][nk][nl][len-2];
                }
            }
        }
    }
 
    int ans=0;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)for(int l=0;l<N;l++){
        ans+=D[i][j][k][l][L];
    }
    printf("%d\n",ans);
    return 0;
}
