#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool vis[8][8];
int dx[8]={-2,-2,-1,1,2,2,1,-1};
int dy[8]={-1,1,2,2,1,-1,-2,-2};
vector<int> level;

string e1,e2;

bool possible(int i,int j){
    return (i>=0 && i<8 && j>=0 && j<8);
}

int bfs(pair<int,int> src){
    queue<pair<int,int> > Q;
    level[src.first*8+src.second]=0;
    Q.push(src);
    vis[src.first][src.second]=true;
    while(!Q.empty()){
        pair<int,int> u=Q.front();
        Q.pop();
        for(int i=0;i<8;i++){
            pair<int,int> v(u.first+dx[i],u.second+dy[i]);
            if(possible(v.first,v.second) && !vis[v.first][v.second]){
                vis[v.first][v.second]=true;
                level[v.first*8+v.second]=1+level[u.first*8+u.second];
                if(v.first== e2[1]-49 && v.second == e2[0]-97){
                    return level[v.first*8+v.second];
                }
                Q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    level.clear();
    level.resize(8*8);
    int res;
    while(cin >> e1){
        cin >> e2;
        memset(vis,false,sizeof(bool)*8*8);
        res=bfs(make_pair(e1[1]-49,e1[0]-97));
        cout << "To get from " << e1 << " to " << e2 << " takes "<< res << " knight moves.\n";
    }
    return 0;
}
