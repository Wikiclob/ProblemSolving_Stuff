#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
#define BE(x) x.begin(),x.end()
#define PI atan(1.0)/4
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
typedef vector<string> vs;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

double rad2deg(double r){
    return r*180/PI;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,c;
    double x1,x2,y1,y2,prob;
    cin >> t;
    cout << std::fixed;
    cout << setprecision(5);

    while(t--){
        cin >> c;
        prob = 0.0f;
        while(c--){
            cin >> x1 >> x2 >> y1 >> y2;
            prob+=abs(atan(y1/x1)-atan(y2/x2));
            cout << "now: " << prob/PI << endl;
        }
        cout << prob << endl;
    }
    return 0;
}
