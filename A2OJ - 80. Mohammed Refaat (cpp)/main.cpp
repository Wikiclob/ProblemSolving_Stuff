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
typedef vector<string> vs;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};
vvii graphe;
int n;

int dijekstra(int from,int to){
    priority_queue<ii> q;
    vi dist(n,oo);
    int now = from;
    ii tmp;
    bool visited[n];
    init(visited,false);
    visited[from] = true;
    dist[from] = 0;
    do{
        int _min = oo;
        int minIdx;
        for(int i=0;i<graphe[now].size();i++){
            tmp = graphe[now][i];
            if(!visited[tmp.f]){
                dist[tmp.f] = min(dist[tmp.f],dist[now]+tmp.s);
                q.push(ii(-dist[tmp.f],tmp.f));
            }
        }
        while(visited[q.top().f])
            q.pop();
        now = q.top().s;
        q.pop();
        visited[now] = true;
    }
    while(now !=to);
    return dist[to];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,m,x,y,w,from,to;
    cin >> t;
    for(int _case=1;_case<=t;_case++){
        cin >> n >> m;
        graphe = vvii(n);
        for(int i=0;i<m;i++){
            cin >> x >> y >> w;
            graphe[x-1].push_back(ii(y-1,w));
            graphe[y-1].push_back(ii(x-1,w));
        }
        cin >> from >> to;
        cout << "Case " << _case << ": " << dijekstra(from-1,to-1) << endl;
    }
    return 0;
}
