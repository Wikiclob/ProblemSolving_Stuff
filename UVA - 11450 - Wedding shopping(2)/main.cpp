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

int money,garments;
int dp[210][25];
vvi G;

int solve(int m,int g){
    if(m<0) return -1;
    if(g==garments) return money-m;
    if(dp[m][g]!=-1) return dp[m][g];
    int res=-1;
    for(int i=0;i<G[g].size();i++){
        res=max(res,solve(m-G[g][i],g+1));
    }
    return dp[m][g]=res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,k,tmp,res;
    cin >> t;
    while(t--){
        init(dp,-1);
        G.clear();
        cin >> money >> garments;
        G.resize(garments);
        for(int i=0;i<garments;i++){
            cin >> k;
            for(int j=0;j<k;j++){
                cin >> tmp;
                G[i].push_back(tmp);
            }
        }
        res=solve(money,0);
        if(res<0)
            cout << "no solution" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
