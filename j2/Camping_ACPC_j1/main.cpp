#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int vis[100],n;
vector<int> ord,level;
vector<vector<int> > g;

void dfs(int src){
    vis[src]=1;
    ord.push_back(src);
    for(int i=0;i<(int)g[src].size();i++){
        if(!vis[g[src][i]]){
            dfs(g[src[i]]);
        }
    }
}

void bfs(int src){
    queue<int> Q;
    Q.push(src);
    level[src]=0;
    for(int i=0;i<n;i++)
        vis[i]=0;
    vis[src]=1;
    while(!Q.empty()){
        int u=Q.front();
        ord.push_back(u);
        Q.pop();
        for(int i=0;i<(int)g[u].size();i++){
            int v=g[u][i];
            if(!vis[v]){
                vis[v]=1;
                level[v]=1+level[u];
                Q.push(v);
            }
        }
    }

}

int main()
{
    freopen("in.txt","r",stdin);
    n=5;
    int e;
    cin >> n >> e;
    for(int i=0;i<e;i++){

    }
    return 0;
}
