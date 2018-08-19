#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > vvii;

const int oo=(int)1e9;

ii e1,e2;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
bool visited[64];

ii coord(string e){
    return {e[1]-'1',e[0]-'a'};
}

bool go(int i,int j){
    return (i>=0 && i<8 && j>=0 && j<8);
}

int bfs(ii src){
    if(src.f == e2.f && src.s == e2.s)
        return 0;
    visited[src.f*8+src.s]=true;
    //cout << "test queue:\n";
    queue<ii> Q;
    ii now;
    int sz;
    int level=1;
    for(int i=0;i<8;i++){
        if(go(src.f+dx[i],src.s+dy[i])){
            if(src.f+dx[i]==e2.f && src.s+dy[i]==e2.s){
                return 1;
            }
            Q.push({src.f+dx[i],src.s+dy[i]});
            //cout << src.f+dx[i] << " " << src.s+dy[i] << endl;
        }
    }
    //cout << "second:\n";
    while(!Q.empty()){
        sz=Q.size();
        level++;
        for(int j=0;j<sz;j++){
            now=Q.front();
            Q.pop();
            for(int i=0;i<8;i++){
                if(go(now.f+dx[i],now.s+dy[i]) && !visited[(now.f+dx[i])*8+now.s+dy[i]]){
                    if(now.f+dx[i]==e2.f && now.s+dy[i]==e2.s){
                        return level;
                    }
                    visited[(now.f+dx[i])*8+now.s+dy[i]]=true;
                    Q.push({now.f+dx[i],now.s+dy[i]});
                    //cout << now.f+dx[i] << " " << now.s+dy[i] << endl;
                }
            }
        }

    }
    //cout << "end test stack\n";
    return -1;
}

int main()
{
    int t;
    cin >> t;
    string tmp;
    while(t--){
        memset(visited,false,sizeof visited);
        cin >> tmp;
        e1=coord(tmp);
        cin >> tmp;
        e2=coord(tmp);
        cout << bfs(e1) << endl;
    }
    return 0;
}
