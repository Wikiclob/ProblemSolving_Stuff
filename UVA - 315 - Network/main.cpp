#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int oo=1e9;
const int MAX=110;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vvi graphe;
int dfs_parent[MAX];
int dfs_low[MAX];
int dfs_num[MAX];
int dfsRoot;
int dfsNumberCounter;
int rootChildren;
bool articulation_vertex[MAX];

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)graphe[u].size(); j++) {
        int v = graphe[u][j];
        if (dfs_num[v] == UNVISITED) { // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot)
                rootChildren++; // special case if u is a root

            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = true; // store this information first

            if (dfs_low[v] > dfs_num[u]){ // for bridge
                /**bridge**/
                //printf(" Edge (%d, %d) is a bridge\n", u, v);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }
}

int main()
{
    int n,u,v,res;
    string input;
    while(true){
        cin >> n;
        if(!n)
            break;
        dfsNumberCounter = 0;
        memset(dfs_num,UNVISITED,sizeof dfs_num);
        memset(dfs_low,0,sizeof dfs_low);
        memset(dfs_parent,0,sizeof dfs_parent);
        memset(articulation_vertex,false,sizeof articulation_vertex);
        graphe.clear();
        graphe.resize(MAX);
        cin.ignore();
        while(true){
            getline(cin,input);
            //cout << "test: "  << input << endl;
            stringstream ss(input);
            ss >> u;
            //cout << "u: " << u << endl;
            if(!u)
                break;
            while(ss >> v){
                //cout << "u: " << u << " v: " << v << endl;
                graphe[u-1].push_back(v-1);
                graphe[v-1].push_back(u-1);
            }
        }

        for (int i = 0; i < n; i++){
            if (dfs_num[i] == UNVISITED) {
                dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
            }
        }
        res=0;
        for(int i=0;i<n;i++){
            if(articulation_vertex[i])
                res++;
        }
        cout << res << endl;
    }

    return 0;
}
