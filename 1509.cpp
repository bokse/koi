#include<stdio.h>
#include<string.h>

const int MN = 2500+1;
const int INF = 1e9;

char str[MN];
bool palin[MN][MN];

int N;
int D[MN];

int main(){
    scanf("%s",str);
    N=strlen(str);
    for(int i=0;i<N;i++)palin[i][i]=true;
    for(int i=0;i<N-1;i++){
        if(str[i]==str[i+1]){
            palin[i][i+1]=true;
        }
    }
    for(int l=2;l<N;l++){
        for(int i=0;i+l<N;i++){
            palin[i][i+l] = (str[i]==str[i+l])&&palin[i+1][i+l-1];
        }
    }
    for(int i=0;i<N;i++){
        if(palin[0][i]){
            D[i]=1;
            continue;
        }
        D[i]=INF;
        for(int j=1;j<=i;j++)if(palin[j][i]){
            if(D[i]>D[j-1]+1){
                D[i]=D[j-1]+1;
            }
        }
    }
    printf("%d\n",D[N-1]);
    return 0;
}
