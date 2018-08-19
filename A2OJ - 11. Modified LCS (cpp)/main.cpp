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
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (a * (b / gcd(a, b))); }

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll len1,len2,first1,first2,jump1,jump2;
    ll seq1,seq2;
    ll limit1,limit2;
    ll jump,max_,min_;
    cin >> t;
    while(t--){
        cin >> len1 >> first1 >> jump1 >> len2 >> first2 >> jump2;
        limit1 = jump1 * (len1-1) + first1;
        limit2 = jump2 * (len2-1) + first2;
        seq1 = first1;
        seq2 = first2;
        jump = lcm(jump1,jump2);
        max_ = min(limit1,limit2);
        while(seq1!= seq2 && seq1<=limit1 && seq2<=limit2){
            if(seq1<seq2)
                seq1 += jump1;
            else if(seq1>seq2)
                seq2 += jump2;
            else{
                seq1 += jump1;
                seq2 += jump2;
            }
        }
        while(seq1!= seq2 && seq1<=limit1)
            seq1 += jump1;
        while(seq1!=seq2 && seq2<=limit2)
            seq2 += jump2;

        if(seq1<=limit1 && seq2<=limit2){
            min_ = seq1;
            cout << (max_  - min_)/jump + 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}
