#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
using namespace std;
const int oo=1e9;
const int MAX=12;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int n,m;

bool go(int i,int j){
    return (i>=0 && i < n && j>= 0 && j < m);
}


int M[MAX][MAX];

int solve(){
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]=='P'){
                for(int k=0;k<4;k++){
                    if(go(i+dx[k],j+dy[k]) && M[i+dx[k]][j+dy[k]] == 'W'){
                        M[i+dx[k]][j+dy[k]]='.';
                        res++;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    string tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        for(int j=0;j<m;j++){
            M[i][j]=tmp[j];
        }
    }

    cout << solve() << endl;

    return 0;
}
