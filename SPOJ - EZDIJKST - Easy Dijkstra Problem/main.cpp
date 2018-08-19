#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const int oo = 1e9;

int n,e;
vvii graph;

int source,dest;
int dijkstra(){
    priority_queue<ii,vector<ii>,greater<ii> > Q;
    vi dist(n,oo);
    ii next,v;
    int d,u;
    dist[source]=0;
    Q.push({0,source});
    while(!Q.empty()){
        next=Q.top();
        Q.pop();
        d=next.f;
        u=next.s;
        if(d>dist[u])
            continue;
        for(int i=0;i<(int)graph[u].size();i++){
            v=graph[u][i];
            if(dist[u]+v.f < dist[v.s]){
                dist[v.s] = dist[u] + v.f;
                Q.push({dist[v.s],v.s});
            }
        }
        //cout << "infini?\n";
    }
    return dist[dest];
}

int main()
{
    int t;
    int tmp;
    ii next;
    cin >> t;
    while(t--){
       cin >> n >> e;
        graph.clear();
        graph.resize(n);
        for(int i=0;i<e;i++){
            cin >> tmp;
            cin >> next.s  >> next.f;
            graph[tmp-1].push_back({next.f,next.s-1});
        }
        cin >> source >> dest;
        source--;dest--;
        int res=dijkstra();
        if(res!=oo)
            cout << res << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
