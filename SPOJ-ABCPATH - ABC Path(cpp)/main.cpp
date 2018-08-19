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
int maxT;
int x,y;
char M[50][50];
bool visited[50][50];
void recursive_parcours(int i,int j,int countT){
    if(countT>maxT)
        maxT=countT;
    if(j<y-1 && M[i][j+1]-1==M[i][j]){
        recursive_parcours(i,j+1,countT+1);
    }
    if(j<y-1 && i<x-1 && M[i+1][j+1]-1==M[i][j]){
        recursive_parcours(i+1,j+1,countT+1);
    }
    if(i<x-1 && M[i+1][j]-1==M[i][j]){
        recursive_parcours(i+1,j,countT+1);
    }
    if(j>0 && i<x-1 && M[i+1][j-1]-1==M[i][j]){
        recursive_parcours(i+1,j-1,countT+1);
    }
    if(j>0 && M[i][j-1]-1==M[i][j]){
        recursive_parcours(i,j-1,countT+1);
    }
    if(j>0 && i>0 && M[i-1][j-1]-1==M[i][j]){
        recursive_parcours(i-1,j-1,countT+1);
    }
    if(i>0 && M[i-1][j]-1==M[i][j]){
        recursive_parcours(i-1,j,countT+1);
    }
    if(i>0 && j<y-1 && M[i-1][j+1]-1==M[i][j]){
        recursive_parcours(i-1,j+1,countT+1);
    }
}
int main()
{
    int cc=1;
    do{
        scanf("%d%d",&x,&y);
        if(x==0 && y==0)
            break;
        maxT=0;
        memset(visited,false,sizeof(bool)*x*y);
        char ch[y+1];
        fflush(stdin);
        for(int i=0;i<x;i++){
            scanf("%s",ch);
            memcpy(M[i],ch,sizeof(char)*y);
        }
        recursive_parcours(0,0,0);
        cout << "Case " << cc << ": " << maxT+1 << "\n";
        cc++;
    }
    while(true);
    return 0;
}
