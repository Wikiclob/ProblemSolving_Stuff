#include <bits/stdc++.h>
using namespace std;
const int MAX = 310;
const int INIT = -1;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graphe;
int n;
int color[MAX];
bool stop;

void bfs(int start){
    queue<int> Q;
    int u,v;
    bool bicolor=true;
    color[start]=0;
    Q.push(start);
    while(!Q.empty() && bicolor){
        u=Q.front();
        Q.pop();
        for(int i=0;i<graphe[u].size();i++){
            v=graphe[u][i];
            if(color[v]==INIT){
                color[v]=1-color[u];
                Q.push(v);
            }
            else if(color[v]==color[u]){
                bicolor=false;
                stop=true;
                break;
            }
        }
    }
}

int main()
{
    int n1,n2;
    //ofstream output("output.out");
    while(true){
        cin >> n;
        if(!n)
            break;
        graphe.clear();
        graphe.resize(n);
        memset(color,INIT,sizeof color);
        while(true){
            cin >> n1 >> n2;
            if(!n1 && !n2)
                break;
            graphe[n1-1].push_back(n2-1);
            graphe[n2-1].push_back(n1-1);
        }
        stop=false;
        for(int i=0;i<n && !stop;i++){
            if(color[i]==INIT)
                bfs(i);
        }
        if(stop){
            cout << "NO" << endl;
            //output << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            //output << "YES" << endl;
        }
    }
    return 0;
}
