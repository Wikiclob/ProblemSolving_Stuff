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

int T[10],taille,limit;

int main()
{
    int N,sum,i,j,k;
    vector<bool> A;
    vector<bool> B;
    vi all;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        sum=0;
        A.clear();
        B.clear();
        all.clear();
        scanf("%d%d",&limit,&taille);
        for(j=0;j<taille;j++)
            scanf("%d",&T[j]);
        sort(T,T+taille);
        for(j=0;j<taille;j++)
            sum+=T[j];
        A.resize(sum+1);
        B.resize(sum+1);
        A[0]=true;
        B[0]=true;
        for(j=0;j<taille;j++){
            for(k=0;k<sum+1;k++){
                if(A[k]){
                    if(!A[k+T[j]]){
                        all.push_back(k+T[j]);
                        B[k+T[j]]=true;
                    }
                }
            }
            A=B;
        }
        sort(all.begin(),all.end());
        if(binary_search(all.begin(),all.end(),limit))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
