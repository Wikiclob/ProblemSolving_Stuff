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
    long long n,t,m,tmp;
    long long prodMod,sol1,sol2,tmpProd,t1,t2;
    cin >> t;
    vector<long long> val;
    while(t--){
        val.clear();
        cin >> m >> n;
        for(int i=0;i<n;i++){
            cin >> tmp;
            val.push_back(tmp);
        }
        sort(val.begin(),val.end());
        int ii=0,jj=1;
        prodMod = -1;
        while(ii<n){
            t1 = val[ii] % m;
            for(int j=ii+1;j<n;j++){
                t2 = val[j] % m;
                tmpProd = (t1 * t2) % m;
                if(tmpProd>prodMod){
                    prodMod = tmpProd;
                    sol1 = val[ii];
                    sol2 = val[j];
                }
            }
            ii++;
        }
        cout << sol1 << " " << sol2 << endl;
    }
    return 0;
}
