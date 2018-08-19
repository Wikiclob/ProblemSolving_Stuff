#include <bits/stdc++.h>
#include <bitset>
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
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<100000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.set(); // set all bits to 1
    bs[0] = bs[1] = 0; // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i); // also add this vector containing list of primes
    }
} // call this method in main method


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n,children,beginning,now,after;
    ll result;

    cin >> n;
    sieve(20010);

    for(int i=1;i<=n;i++){
        cin >> children;

        beginning = 1;
        result = 0;

        while(primes[beginning] <= (children*2-1)){
            now = primes[beginning] - children;
            if(now <= 0) now = 1;
            after = primes[beginning] - now;

            result += (after +1 - now)/2;

            beginning++;
        }
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
