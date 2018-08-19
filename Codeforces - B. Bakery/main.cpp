#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int oo=1e9;
const int MAX=100010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vector<pair<int,ii> > graphe;
bool bakery[MAX];
int main()
{
    int n,m,k;
    int u,v,l;
    cin >> n >> m >> k;
    memset(bakery,false,sizeof bakery);

    for(int i=0;i<m;i++){
        cin >> u >> v >> l;
        graphe.push_back({l,{u-1,v-1}});
    }
    for(int i=0;i<k;i++){
        cin >> u;
        bakery[u-1]=true;
    }
    sort(graphe.begin(),graphe.end());
    int cc=0;
    int length=-1;
    while(cc<graphe.size()){
        if(bakery[graphe[cc].s.f]^bakery[graphe[cc].s.s]){
            length=graphe[cc].f;
            break;
        }
        else
            cc++;
    }
    cout << length << endl;
    return 0;
}
