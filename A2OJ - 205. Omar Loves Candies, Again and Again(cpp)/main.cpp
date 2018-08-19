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

vii candies;

int max_candies(int money, int visited){
    int retour = 0;
    for(int i=0;i<candies.size();i++){
        if(money>=candies[i].f && !(visited &(1 << i)))
            retour = max(retour,1+max_candies(money-candies[i].f+candies[i].s,visited | (1 << i)));
    }
    return retour;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T,N,Coins,price,inbox;
    cin >> T;
    while(T--){
        cin >> N >> Coins;
        candies = vii();
        for(int i=0;i<N;i++){
            cin >> price >> inbox;
            candies.push_back(ii(price,inbox));
        }
        cout << max_candies(Coins,0) << endl;
    }
    return 0;
}
