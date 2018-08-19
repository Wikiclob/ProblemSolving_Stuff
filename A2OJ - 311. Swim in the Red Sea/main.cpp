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
typedef vector<ll> vll;
typedef pair<string,string> ss;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

int M[10][10];
int n;

int minPos(int visited,int now,int minV){
    if(now>=n) return minV;
    int minVal=oo;
    for(int i=0;i<n;i++){
        if((visited & (1 << i))==0){
            minVal = min(minVal,minPos(visited | (1<<i),now+1,max(minV,M[now][i])));
        }
    }
    return minVal;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                cin >> M[j][k];
        cout << "Case " << i << ": " << minPos(0,0,0) << endl;
    }
    return 0;
}
