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

int n,W;
int val[1000],w[101];
int dp[1001][100001];

int solve(int i,int rem){
    if(rem<0)
        return -oo;
    if(i>=n)
        return 0;
    if(dp[i][rem] != -1)
        return dp[i][rem];
    int& r=dp[i][rem];
    r=solve(i+1,rem);
    if(rem>=w[i])
        r=max(r,val[i] + solve(i+1,rem-w[i]));
    return r;
}

int cost;

void trace(int i,int rem){
    if(i>=n)
        return;
    int r=solve(i,rem);
    int ch1 = solve(i+1,rem);
    int ch2 = 0;
    if(rem>=w[i])
        ch2 = val[i] + solve(i+1,rem-w[i]);
    if(r == ch1)
        trace(i+1,rem);
    else{
        trace(i+1,rem-w[i]);
        cout << i << " " << w[i] << " " << val[i] << endl;
        cost+=w[i];
    }
}

int sol(){
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i-1])
                dp[i][j]=max(dp[i][j] , dp[i-1][j-w[i-1]]+ val[i-1]);
        }
    }
    return dp[n][W];
}

int main()
{
    freopen("in.txt","r",stdin);
    memset(dp,-1,sizeof dp);
    cin >> n >> W;
    for(int i=0;i<n;i++){
        cin >> val[i] >> w[i];
    }
    cout << solve(0,W) << endl;
    cost=0;
    cout << "trace:\n";
    trace(0,W);
    cout << "total cost: " << cost << endl;
    cout << "end trace\n";
    cout << "gain: " << sol() << endl;
    return 0;
}
