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

long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }

int main()
{
    std::ios::sync_with_stdio(false);
    long long n,tmp;
    cin >> n;
    while(n--){
        cin >> tmp;
        cout << lcm(tmp,7) << endl;
    }
    return 0;
}
