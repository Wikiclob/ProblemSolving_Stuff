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
    int x,y;

    cin >> x >> y;
    int T[3]={y,y,y};
    int rep=0;
    while(T[0]<x){
        rep++;
        T[0]=T[1]+T[2]-1;
        sort(T,T+3);
    }
    cout << rep << endl;
    return 0;
}
