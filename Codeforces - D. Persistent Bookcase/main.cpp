#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
using namespace std;
const int oo=1e9;
const int MAX=100010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

struct SAVE{
    int type,i,j;
}save[MAX];

bool current[1010][1010];
int shelf[1010];
bool inverse[1010];
int score;

vector<int> G[MAX];
int res[MAX];
int n,m;

void dfs(int u){
    //cout << "u: " << u << " ==> type: " << save[u].type <<  endl;
    if(save[u].type==1){
        if(!(inverse[save[u].i]^current[save[u].i][save[u].j])){
            current[save[u].i][save[u].j]^=true;
            shelf[save[u].i]++;
            score++;

            res[u]=score;

            for(int i=0;i<G[u].size();i++)
                dfs(G[u][i]);

            score--;
            shelf[save[u].i]--;
            current[save[u].i][save[u].j]^=true;
        }
        else{
            res[u]=score;
            for(int i=0;i<G[u].size();i++)
                dfs(G[u][i]);
        }
    }
    else if(save[u].type==2){
        if((inverse[save[u].i]^current[save[u].i][save[u].j])){
            //cout << "working 2" << endl;
            current[save[u].i][save[u].j]^=true;
            shelf[save[u].i]--;
            score--;

            res[u]=score;

            for(int i=0;i<G[u].size();i++)
                dfs(G[u][i]);

            score++;
            shelf[save[u].i]++;
            current[save[u].i][save[u].j]^=true;
        }
        else{
            res[u]=score;
            for(int i=0;i<G[u].size();i++)
                dfs(G[u][i]);
        }
    }
    else if(save[u].type==3){
        //cout << "working 3" << endl;
        inverse[save[u].i]^=true;
        score+=m-2*shelf[save[u].i];
        shelf[save[u].i]=m-shelf[save[u].i];

        res[u]=score;

        for(int i=0;i<G[u].size();i++)
            dfs(G[u][i]);

        shelf[save[u].i]=m-shelf[save[u].i];
        score-=m-2*shelf[save[u].i];
        inverse[save[u].i]^=true;
    }
    else if(save[u].type==4){
        res[u]=score;
        for(int i=0;i<G[u].size();i++){
            dfs(G[u][i]);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int q;
    cin >> n >> m >> q;
    for(int i=1;i<=q;i++){
        cin >> save[i].type;
        if(save[i].type==1 || save[i].type==2){
            cin >> save[i].i >> save[i].j;
            G[i-1].push_back(i);
        }
        else if(save[i].type==3){
            cin >> save[i].i;
            G[i-1].push_back(i);
        }
        else{
            cin >> save[i].i;
            G[save[i].i].push_back(i);
        }
    }
    score=0;
    for (int i=0;i<G[0].size();i++){
        dfs(G[0][i]);
    }
    for(int i=1;i<=q;i++){
        cout << res[i] << endl;
    }
    return 0;
}
