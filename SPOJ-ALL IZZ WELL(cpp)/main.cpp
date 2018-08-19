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
char M[100][100];
const char* mot="ALLIZZWELL";
bool recursive_parcours(int i,int j,int ind,bool visited[][100]){
    if(ind==strlen(mot))
        return true;
    bool retour=false;
    if(j<y-1 && M[i][j+1]==mot[ind] && !visited[i][j+1]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i][j+1]=true;
        retour|=recursive_parcours(i,j+1,ind+1,cpy);
        if(retour)
            return true;
    }
    if(j<y-1 && i<x-1 && M[i+1][j+1]==mot[ind] && !visited[i+1][j+1]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i+1][j+1]=true;
        retour|=recursive_parcours(i+1,j+1,ind+1,cpy);
        if(retour)
            return true;
    }
    if(i<x-1 && M[i+1][j]==mot[ind] && !visited[i+1][j]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i+1][j]=true;
        retour|=recursive_parcours(i+1,j,ind+1,cpy);
        if(retour)
            return true;
    }
    if(j>0 && i<x-1 && M[i+1][j-1]==mot[ind] && !visited[i+1][j-1]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i+1][j-1]=true;
        retour|=recursive_parcours(i+1,j-1,ind+1,cpy);
        if(retour)
            return true;
    }
    if(j>0 && M[i][j-1]==mot[ind] && !visited[i][j-1]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i][j-1]=true;
        retour|=recursive_parcours(i,j-1,ind+1,cpy);
        if(retour)
            return true;
    }
    if(j>0 && i>0 && M[i-1][j-1]==mot[ind] && !visited[i-1][j-1]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i-1][j-1]=true;
        retour|=recursive_parcours(i-1,j-1,ind+1,cpy);
        if(retour)
            return true;
    }
    if(i>0 && M[i-1][j]==mot[ind] && !visited[i-1][j]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i-1][j]=true;
        retour|=recursive_parcours(i-1,j,ind+1,cpy);
        if(retour)
            return true;
    }
    if(i>0 && j<y-1 && M[i-1][j+1]==mot[ind] && !visited[i-1][j+1]){
        bool cpy[100][100];
        memcpy(cpy,visited,sizeof(bool)*100*100);
        cpy[i-1][j+1]=true;
        retour|=recursive_parcours(i-1,j+1,ind+1,cpy);
        if(retour)
            return true;
    }
    return retour;
}

int main()
{
    int N;
    char ch[101];
    bool res;
    bool visited[100][100];
    memset(visited,false,sizeof(bool)*100*100);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&x,&y);
        fflush(stdin);
        for(int j=0;j<x;j++){
            scanf("%s",ch);
            memcpy(M[j],ch,sizeof(char)*y);
        }
        res=false;
        for(int j=0;j<x;j++){
            for(int k=0;k<y;k++){
                visited[j][k]=true;
                if(M[j][k]=='A')
                    res=recursive_parcours(j,k,1,visited);
                visited[j][k]=false;
                if(res)
                    break;
            }
            if(res)
                break;
        }
        if(res)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
