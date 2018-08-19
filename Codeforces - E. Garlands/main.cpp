#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
using namespace std;
const int oo=1e9;
const int MAX=2001;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

bool on[MAX];
vector<ll> res;
vector<ii> query;
vector<pair<ii,ii> > ask;
long long tree[MAX][MAX];
vector<pair<ii,int> > garland[MAX];
vector<int> garlandQueries[MAX];
int n,m,g;

//read(r1,c1,r2,c2) = read(r2,c2) - read(r2,c1-1) - read(r1-1,c2) + read(r1-1,c1-1);
long long read(int x,int y){ // return sum from 1,1 to x,y.
    long long sum= 0;
    int y1;
    while(x){
        y1 = y;
        while(y1){
            sum += tree[x][y1];
            y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
    return sum;
}

void update(int x , int y , int val){
    int y1;
    while (x <= n){
        y1 = y;
        while (y1 <= m){
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}



int main()
{
    //std::ios::sync_with_stdio(false);
    int len,event,tmp;
    char ev[10];

    int i1,i2,j1,j2;
    unsigned long long sum;
    scanf("%d%d%d",&n,&m,&g);
    for(int i=1;i<=g;i++){
        on[i]=true;
        scanf("%d",&len);
        for(int j=1;j<=len;j++){
            scanf("%d%d%d",&i1,&j1,&tmp);
            garland[i].push_back({{i1,j1},tmp});
        }
    }
    scanf("%d",&event);
    for(int k=0;k<event;k++){
        scanf("%s",ev);
        if(ev[0]=='S'){
            scanf("%d",&tmp);
            on[tmp]^=true;
            //query.push_back({0,tmp});
        }
        else{
            scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
            for(int i=1;i<=g;i++)
                if(on[i]) garlandQueries[i].push_back(ask.size());
            //query.push_back({1,ask.size()});
            ask.push_back({{i1,j1},{i2,j2}});
        }
    }
    res.resize(ask.size());
    pair<ii,ii> tm;
    for(int i=1;i<=g;i++){
        for(int j=0;j<garland[i].size();j++)
            update(garland[i][j].f.f,garland[i][j].f.s,garland[i][j].s);
        for(int j=0;j<garlandQueries[i].size();j++){
            tm=ask[garlandQueries[i][j]];
            res[garlandQueries[i][j]]+=read(tm.s.f,tm.s.s) - read(tm.s.f,tm.f.s-1) - read(tm.f.f-1,tm.s.s) + read(tm.f.f-1,tm.f.s-1);
        }
        for(int j=0;j<garland[i].size();j++)
            update(garland[i][j].f.f,garland[i][j].f.s,-garland[i][j].s);
    }
    for(int i=0;i<res.size();i++){
        printf("%I64d\n",res[i]);
    }
    return 0;
}
