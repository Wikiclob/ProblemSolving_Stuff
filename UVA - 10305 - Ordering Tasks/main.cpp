#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
const int MAX=110;
typedef pair<int,int> ii;
typedef vector<vector<int> > vvi;

int n;
vvi Graphe;
bool visited[MAX];
vector<int> rep;

void dfs(int deb){
    visited[deb]=true;
    for(int i=0;i<Graphe[deb].size();i++){
        if(!visited[Graphe[deb][i]]){
            dfs(Graphe[deb][i]);
        }
    }
    rep.push_back(deb);
}

int main()
{
    int m;
    int r1,r2;
    while(true){
        cin >> n >> m;
        if(n==0 && m==0)
            break;
        Graphe.clear();
        Graphe.resize(n+1);
        for(int i=0;i<m;i++){
            cin >> r1 >> r2;
            Graphe[r1].push_back(r2);
        }
        rep.clear();
        memset(visited,false,sizeof visited);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        for(int i=rep.size()-1;i>=0;i--){
            cout << rep[i];
            if(i!=0)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
