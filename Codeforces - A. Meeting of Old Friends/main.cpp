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

int main()
{
    std::ios::sync_with_stdio(false);
    ll deb1,fin1,deb2,fin2,k;
    ll minX,maxX;
    cin >> deb1 >> fin1 >> deb2 >> fin2 >> k;
    minX=max(deb1,deb2);
    maxX=min(fin1,fin2);
    if(maxX-minX<0) cout << 0 << endl;
    else if(k<=maxX && k>=minX) cout << maxX-minX << endl;
    else cout << maxX-minX+1 << endl;
    return 0;
}
