#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef pair<int,int> ii;

int n,m;
const int MAX=20;
string M[MAX];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool go(int x,int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

bool extrem(ii p){
    return (p.f==0 || p.f == (n-1) || p.s == 0 || p.s == (m-1));
}

bool visited[MAX*MAX];

bool dfs(int x,int y){
    //cout << "dfs trace: \n";
    stack<ii> S;
    S.push({x,y});
    //cout << x << " " << y << endl;
    ii now;
    visited[x*n+y]=true;
    do{
        now=S.top();
        S.pop();
        for(int i=0;i<4;i++){
            if(go(now.f+dx[i],now.s+dy[i]) && !visited[(now.f+dx[i])*n+now.s+dy[i]] && M[now.f+dx[i]][now.s+dy[i]]=='.'){
                //cout << now.f+dx[i] << " " << now.s+dy[i] << endl;
                if(extrem({now.f+dx[i],now.s+dy[i]}))
                    return true;
                S.push({now.f+dx[i],now.s+dy[i]});
                visited[(now.f+dx[i])*n+now.s+dy[i]]=true;
            }
        }
    }
    while(!S.empty());
    return false;
}

int main()
{
    int t;
    cin >> t;
    int ct;
    string tmp;
    int sx,sy;
    while(t--){
        cin >> n >> m;
        ct=0;
        for(int i=0;i<n;i++){
            cin >> tmp;
            M[i]=tmp;
            if(i==0 || i==(n-1)){
                for(int j=0;j<m;j++){
                    if(tmp[j]=='.'){
                        ct++;
                        sx=i;sy=j;
                    }
                }
            }
            else{
                if(m-1!=0){
                    if(tmp[0]=='.'){
                        ct++;
                        sx=i;sy=0;
                    }
                    if(tmp[m-1]=='.'){
                        ct++;
                        sx=i;sy=m-1;
                    }

                }
                else{
                    if(tmp[0]=='.'){
                        ct++;
                        sx=i;sy=0;
                    }
                }
            }
        }
        if(ct!=2)
            cout << "invalid" << endl;
        else{
            memset(visited,false,sizeof visited);
            if(dfs(sx,sy)){
                //cout << "end trace\n";
                cout << "valid" << endl;
            }
            else{
                //cout << "end trace\n";
                cout << "invalid" << endl;
            }
        }
    }
    return 0;
}
