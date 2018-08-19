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
    int price,lastCoin;
    cin >> price >> lastCoin;
    int fB=price%10;
    int rep=10;
    for(int i=1;i<10;i++){
        if((fB*i)%10==lastCoin || (fB*i)%10==0){
            rep=i;
            break;
        }
    }
    cout << rep << endl;
    return 0;
}
