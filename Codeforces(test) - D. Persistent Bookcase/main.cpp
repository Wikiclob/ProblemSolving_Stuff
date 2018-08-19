#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

struct DATA {
    int t,i,j,k;
}A[100005];

vector<int>G[100005];

bool c[1005][1005];
bool d[1005];
int ans[100005];
int cnt[1005];
int res;
int n,m;

void dfs(int u){
    int t=A[u].t,i=A[u].i,j=A[u].j;
    if (t==1) {
        if (!(d[i]^c[i][j])) {
            c[i][j]^=1;
            cnt[i]++;
            res++;
            ans[u]=res;
            for (int o=0;o<G[u].size();o++)
                dfs(G[u][o]);
            res--;
            cnt[i]--;
            c[i][j]^=1;
        }
        else {
            ans[u]=res;
            for (int o=0;o<G[u].size();o++)
                dfs(G[u][o]);
        }
    }
    else if (t==2){
        if ((d[i]^c[i][j])) {
            c[i][j]^=1;
            cnt[i]--;
            res--;
            ans[u]=res;
            for (int o=0;o<G[u].size();o++)
                dfs(G[u][o]);
            res++;
            cnt[i]++;
            c[i][j]^=1;
        }
        else {
            ans[u]=res;
            for (int o=0;o<G[u].size();o++)
                dfs(G[u][o]);
        }
    }
    else if (t==3){
        d[i]^=1;
        res+=m-2*cnt[i];
        cnt[i]=m-cnt[i];
        ans[u]=res;
        for (int o=0;o<G[u].size();o++)
            dfs(G[u][o]);
        cnt[i]=m-cnt[i];
        res-=m-2*cnt[i];
        d[i]^=1;
    }
    else if (t==4){
        ans[u]=res;
        for (int o=0;o<G[u].size();o++)
            dfs(G[u][o]);
    }
}

int main(){
    int q;
    cin>>n>>m>>q;
    for (int i=1;i<=q;i++){
        cin>>A[i].t;
        if (A[i].t==1||A[i].t==2) {
            cin>>A[i].i>>A[i].j;
            G[i-1].push_back(i);
        }
        else if (A[i].t==3) {
            cin>>A[i].i;
            G[i-1].push_back(i);
        }
        else {
            cin>>A[i].k;
            G[A[i].k].push_back(i);
        }
    }
    for (int i=0;i<G[0].size();i++){
        dfs(G[0][i]);
    }
    for (int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
