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
    int t,G,C,E;
    int remaining,kilo;
    int candies = 0;
    cin >> t;
    while(t--){
        cin >> G >> C >> E;
        if(G == 1)
            candies =1;
        else if(G == 2)
            candies = 3;
        else if(G == 3)
            candies = 5;
        remaining = E - C;
        if(remaining<=0){
            cout << 0 << endl;
        }
        else{
            kilo = remaining*candies;
            cout << kilo << endl;
        }
    }
    return 0;
}
