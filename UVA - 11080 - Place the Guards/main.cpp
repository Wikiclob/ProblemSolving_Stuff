#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MAX=210;
const int INIT=-1;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;

vvi graphe;
int color[MAX];
int n;
int res;
bool stop;

void bfs(int start){
    queue<int> Q;
    int v,u;
    int zero=1,one=0;
    bool bicolor=true;
    color[start]=0;
    Q.push(start);
    while(!Q.empty() && bicolor){
        v=Q.front();
        Q.pop();
        for(int i=0;i<graphe[v].size();i++){
            u=graphe[v][i];
            if(color[u]==INIT){
                color[u]=1-color[v];
                if(color[u]==0)
                    zero++;
                else
                    one++;
                Q.push(u);
            }
            else if(color[u]==color[v]){
                bicolor=false;
                break;
            }
        }
    }
    if(!bicolor)
        stop=true;
    else{
        if(zero && one)
            res+=min(zero,one);
        else
            res+=1;
    }
}

int main()
{
    //ofstream output("output.out");
    int t,e,n1,n2;
    cin >> t;
    while(t--){
        graphe.clear();
        res=0;
        stop=false;
        cin >> n >> e;
        graphe.resize(n);
        memset(color,INIT,sizeof color);
        for(int i=0;i<e;i++){
            cin >> n1 >> n2;
            graphe[n1].push_back(n2);
            graphe[n2].push_back(n1);
        }
        for(int i=0;i<n;i++){
            if(color[i]==INIT)
                bfs(i);
            if(stop)
                break;
        }
        if(stop){
            //output << -1 << endl;
            cout << -1 << endl;
        }
        else{
            //output << res << endl;
            cout << res << endl;
        }
    }
    return 0;
}
