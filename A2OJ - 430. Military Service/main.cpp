#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};


int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    int n,k;
    int sol,sDiv;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n>k){
        sDiv = n/(k+1);
        //sMod = n %(k+1);
        sol = n - sDiv - ((n%(k+1))!=0?1:0);
        }
        else{
            sol = n-1;
        }
        if(sol<0)
            sol = 0;
        cout << sol << endl;
    }
    return 0;
}