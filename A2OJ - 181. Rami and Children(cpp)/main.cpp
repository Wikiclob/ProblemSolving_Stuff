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
    int n,m,t,tmp,tmp1,_maxVal,_maxPos;
    cin >> t;
    while(t--){
        cin >> n >> m;
        _maxPos=0;
        _maxVal=0;
        for(int j=0;j<n;j++){
            cin >> tmp;
            tmp1=tmp/m;
            if(tmp%m!=0)
                tmp1++;
            if(tmp1>=_maxVal){
                _maxPos = j;
                _maxVal = tmp1;
            }
        }
        cout << _maxPos+1 << endl;
    }
    return 0;
}
