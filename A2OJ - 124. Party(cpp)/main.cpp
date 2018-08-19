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
    int N,D,TR,R,X;
    cin >> N;
    while(N--){
        cin >> D >> TR;
        vector<bool> T(D-1,false);
        R = 0;
        while(TR--){
            cin >> X;
            if(X<=D-2){
                if(!T[X]){
                    R++;
                    T[X]=true;
                }
                else{
                    for(int i=X+1;i<D-1;i++){
                        if(!T[i]){
                            T[i] = true;
                            R++;
                            break;
                        }
                    }
                }
            }
        }
        cout << R << endl;
    }
    return 0;
}
