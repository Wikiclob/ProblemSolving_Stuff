#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
using namespace std;
const int oo=1e9;
const int MAX=49;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int M[MAX][MAX];
int n;
int ending;

void construct(){
    int posI=0,posJ=n/2;
    int nextI,nextJ;
    int taken=1;
    M[posI][posJ]=1;
    while(taken<ending){
        nextI=posI-1;
        if(nextI<0) nextI=n-1;
        nextJ=posJ+1;
        if(nextJ>=n) nextJ=0;
    }
}

int main()
{
    cin >> n;
    ending=n*n;

    return 0;
}
