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

int last_digit[10][10]={
{0,1,5,4,0,5,1,0,4,5},
{5,1,5,4,0,5,1,0,4,5},
{4,5,4,3,9,4,0,9,3,4},
{0,1,5,9,5,0,6,5,9,0},
{1,2,6,5,6,1,7,6,0,1},
{5,6,0,9,5,5,1,0,4,5},
{0,1,5,4,0,5,6,5,9,0},
{4,5,9,8,4,9,5,9,3,4},
{5,6,0,9,5,0,6,5,4,5},
{1,2,6,5,1,6,2,1,5,1}};

ll pow2(ll n){
    return n*n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a,b;
    ll repeat;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> a >> b;
        repeat = (b/10)-(a/10);
        if(a%10>b%10) repeat--;
        //ll power = 0;
        //cout << last_digit[a%10][b%10] << " + " << last_digit[0][9] << "*" << repeat << "%10" << endl;
        cout << "Case " << i << ": " << (last_digit[a%10][b%10]+(last_digit[0][9]*repeat))%10 << endl;
        /*for(int j=a;j<=b;j++){
            power = (power+pow2(j)%10)%10;
        }

        cout << "###: " << power%10 << endl;*/
        //power = 0;
    }
    return 0;
}
