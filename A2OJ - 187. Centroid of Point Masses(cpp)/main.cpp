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

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,tmp_x,tmp_y,tmp_m;
    //int max_x,min_x,max_y,min_y;
    ll sum_m;
    double interm_x,interm_y;
    int cases=1;
    //vector<pair<ii,i> > coord;
    do{
        cin >> n;
        if(n<0)
            break;
        sum_m = 0;
        interm_x = 0;
        interm_y = 0;
        //coord = vector<pair<ii,i> >;
        for(int i=0;i<n;i++){
            cin >> tmp_x >> tmp_y >> tmp_m;
            interm_x += (tmp_m*tmp_x);
            interm_y += (tmp_m*tmp_y);
            sum_m+=tmp_m;
            //coord.push_back(pair<ii,i>(ii(tmp_x,tmp_y),tmp_m));
        }
        cout <<std::fixed <<setprecision(2) << "Case " << cases++ << ": " << interm_x/sum_m << " " << interm_y/sum_m << endl;
    }
    while(true);
    return 0;
}
