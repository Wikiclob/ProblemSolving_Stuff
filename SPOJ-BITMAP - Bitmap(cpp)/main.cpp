#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;
int x,y;
int M[182][182];
int dist[182][182];
int cc=0;
void recursive_parcours(int i,int j,int countT){
    cout << "iteration nb: " << cc << "\n";
    cc++;
    if(j<y-1 && dist[i][j+1]>countT+1){
        dist[i][j+1]=countT+1;
        recursive_parcours(i,j+1,countT+1);
    }

    if(i<x-1 && dist[i+1][j]>countT+1){
        dist[i+1][j]=countT+1;
        recursive_parcours(i+1,j,countT+1);
    }

    if(j>0 && dist[i][j-1]>countT+1){
        dist[i][j-1]=countT+1;
        recursive_parcours(i,j-1,countT+1);
    }

    if(i>0 && dist[i-1][j]>countT+1){
        dist[i-1][j]=countT+1;
        recursive_parcours(i-1,j,countT+1);
    }

}

int main()
{
    int N;
    scanf("%d",&N);
    int tmp;
    char ch[183];
    for(int i=0;i<N;i++){
        scanf("%d%d",&x,&y);
        memset(dist,33125,sizeof(int)*182*182);
        fflush(stdin);
        for(int j=0;j<x;j++){
            scanf("%s",ch);
            for(int k=0;k<y;k++){
                if(ch[k]=='1'){
                    dist[j][k]=0;
                }
                M[j][k]=ch[k]-48;
            }
        }
        for(int j=0;j<x;j++){
            for(int k=0;k<y;k++){
                if(M[j][k]==0){
                    for(int l=0;l<x;l++){
                        for(int m=0;m<y;m++){
                            if((l!=j || m!=k) && M[l][m]==1){
                                tmp=abs(j-l)+abs(k-m);
                                if(tmp<dist[j][k])
                                    dist[j][k]=tmp;
                            }
                        }
                    }
                }
            }
        }
        for(int j=0;j<x;j++){
            for(int k=0;k<y;k++){
                if(k!=0)
                    printf(" ");
                printf("%d",dist[j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}
