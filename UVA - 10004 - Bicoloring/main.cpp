#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MAX=210;
const int IND=-1;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
vvi graphe;
int color[MAX];

bool bfs(){
    queue<int> Q;
    int v,u;
    Q.push(0);
    color[0]=0;
    bool bicolor=true;
    while(!Q.empty() && bicolor){
        v=Q.front();
        Q.pop();
        for(int i=0;i<graphe[v].size();i++){
            u=graphe[v][i];
            if(color[u]==IND){
                color[u]=1-color[v];
                Q.push(u);
            }
            else if(color[u]==color[v]){
                bicolor=false;
                break;
            }
        }
    }
    return bicolor;
}

int main()
{
    //ofstream output("output.out");
    int e;
    int n1,n2;
    while(true){
        cin >> n;
        if(!n)
            break;
        graphe.clear();
        graphe.resize(n);
        memset(color,IND,sizeof color);
        cin >> e;
        for(int i=0;i<e;i++){
            cin >> n1 >> n2;
            graphe[n1].push_back(n2);
        }
        if(bfs()){
            cout << "BICOLORABLE." << endl;
            //output << "BICOLORABLE." << endl;
        }
        else{
            cout << "NOT BICOLORABLE." << endl;
            //output << "NOT BICOLORABLE." << endl;
        }
    }
    return 0;
}
