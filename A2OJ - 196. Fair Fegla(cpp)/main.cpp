#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
#define BE(x) x.begin(),x.end()
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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,moy,sum,toDel,toMov;
    vi pSet;
    cin >> t;
    while(t--){
        cin >> n;
        pSet.resize(n);
        sum = moy = toMov = 0;
        for(int i=0;i<n;i++){
            cin >> pSet[i];
            sum += pSet[i];
        }
        moy = sum / n;
        toDel = sum - (moy * n);
        for(int i=0;i<n;i++){
            if(pSet[i] > moy)
                toMov += (pSet[i] - moy);
        }
        cout << toDel << " " << toMov-toDel << endl;
    }
    return 0;
}
