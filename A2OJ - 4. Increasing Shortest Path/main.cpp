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

vb visited;
vvii graphe;
int maxE;
int B;

int dijkstra(int src){
    vi dist(graphe.size(),oo);
    vb visited(graphe.size(),false);
    vi countE(graphe.size(),0);

    visited[src] = true;
    dist[src] = 0;
    int min_= oo,minI = 0;
    int now = src;
    int edge = 0;

    for(int i=0;i<graphe[now].size();i++){
        if(!visited[graphe[now][i].f] && graphe[now][i].s >= edge){
            if(dist[graphe[now][i].f] >= dist[src] + graphe[now][i].s){

            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,e,q;
    int x,y,z;
    cin >> t;
    while(t--){
        cin >> n >> e >> q;
        graphe = vvii(n);
        visited = vb(n,false);
        for(int i=0;i<e;i++){
            cin >> x >> y >> z;
            graphe[x].push_back(ii(y,z));
            graphe[y].push_back(ii(x,z));
        }
        for(int i=0;i<q;i++){
            cin >> x >> B >> maxE;
        }
    }
    return 0;
}
