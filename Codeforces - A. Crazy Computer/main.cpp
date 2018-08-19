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
    int n,c;
    int nb=0,t1=0,t2;
    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> t2;
        if(t2-t1<=c)
            nb++;
        else
            nb=1;
        t1=t2;
    }
    cout << nb << endl;
    return 0;
}
