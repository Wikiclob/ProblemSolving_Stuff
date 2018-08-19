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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    int N,nb,year,yy,sum,i,j,k;
    vi stone,res;
    vector<bool> A,B;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        stone.clear();
        res.clear();
        A.clear();
        B.clear();
        sum=0;
        scanf("%d%d",&year,&nb);
        for(j=0;j<nb;j++){
            scanf("%d",&yy);
            stone.push_back(yy);
            sum+=yy;
        }
        A.resize(sum+1);
        B.resize(sum+1);
        A[0]=true;
        B[0]=true;
        sort(stone.begin(),stone.end());
        for(j=0;j<stone.size();j++){
            for(k=0;k<sum+1;k++){
                if(A[k]){
                    if(!A[k+stone[j]]){
                        res.push_back(k+stone[j]);
                        B[k+stone[j]]=true;
                    }
                }
            }
            A=B;
        }
        sort(res.begin(),res.end());
        for(j=0;j<res.size();j++)
            cout << res[j]+year << "\n";
    }
    return 0;
}
