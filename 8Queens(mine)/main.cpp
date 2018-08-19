#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii> > vvii;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
typedef long long ll;

const int oo = (int)1e9;
const int nbW = 9999999;

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

bool go(int i,int j){
    return (i>=0 && i<8 && j>=0 && j<8);
}

int ways(int pos){
    if(pos>nbW)
        return 0;
    int i=1;
    int M[8][8]={0};
    int p;
    while((p=pos/((int)pow(10,i))%((int)pow(10,i)))!=0){
        M[i-1][p-1]=1;
        for(int j=0;j<8;j++){
            while(go(i-1+dx[j],p-1+dy[j])){
                M[i-1+dx[j]][p-1+dy[j]]=1;
            }
        }
        for(int j=p-1;j<8;j++){
            if(M[i-1][j]==0){
                return 1+ways(pos+pow(10,i-1)*(j+1));
            }
        }
    }
    return 0;


}

int main()
{
    cout << ways(0) << endl;
    return 0;
}
