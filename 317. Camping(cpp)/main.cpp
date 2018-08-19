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
typedef vector<vi> vvi;

bool M[1001][1001];
//bool know[1001];
int taille;

void modif_know(){
    for(int i=1;i<=taille;i++)
        M[i][i]=true;
    bool modif;
    for(int ind=1;ind<=taille;ind++){
        modif=true;
        while(modif){
            modif=false;
            for(int i=1;i<=taille;i++){
                if(M[ind][i] && ind!=i){
                    for(int j=1;j<=taille;j++)
                        if(M[i][j] && !M[ind][j]){
                            M[ind][j]=true;
                            modif=true;
                        }
                }
            }
        }
    }
}

bool verif_know(int st1,int st2){
    if(M[st1][st2])
        return true;
    return false;
}

int main()
{
    int N,i,j,x,y,st1,st2,nbQ,nb;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        printf("Case %d:\n",i);
        scanf("%d%d",&taille,&nb);
        memset(M,false,sizeof(bool)*1001*1001);
        //memset(know,false,sizeof(bool)*1001);
        for(j=0;j<nb;j++){
            scanf("%d%d",&x,&y);
            M[x][y]=true;
        }
        modif_know();
        scanf("%d",&nbQ);
        for(j=0;j<nbQ;j++){
            scanf("%d%d",&st1,&st2);
            if(verif_know(st1,st2))
                printf("Yes\n");
            else
                printf("No\n");
        }

    }
    return 0;
}
