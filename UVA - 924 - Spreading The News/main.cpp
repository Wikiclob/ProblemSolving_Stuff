#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector <int> > g;
int e;
vector<int> vis;
int first_day,max_day;
vector<int> level;
vector<int> nb_level;
void bfs(int src){
    //cout << "trace: ";
    queue<int> Q;
    //int tmp=0;
    Q.push(src);
    level[src]=0;
    for(int i=0;i<e;i++)
        vis[i]=0;
    vis[src]=1;
    //bool first=true;
    while(!Q.empty()){
        int u=Q.front();
        //cout << u << " ";
        //ord.push_back(u);
        Q.pop();
        //tmp=0;
        //cout << "size: " << g[u].size() << endl;
        for(int i=0;i<(int)g[u].size();i++){

            int v=g[u][i];
            if(!vis[v]){
                //if(u==0)
                //    cout << "size: " << g[u].size() << endl;
                vis[v]=1;
                level[v]=1+level[u];
                if(level[v]+1>nb_level.size())
                    nb_level.resize(level[v]+1);
                nb_level[level[v]]++;
                Q.push(v);
                //tmp++;
            }
        }
        /*if(first){
            first_day=tmp;
            first=false;
        }*/
        //if(tmp>max_day)
        //    max_day=tmp;
    }
    //cout << "end trace" << endl;
}

int main()
{
    int friends,tmp;
    cin >> e;
    g.resize(e);
    vis.resize(e);
    level.resize(e);
    for(int j=0;j<e;j++){
        cin >> friends;
        for(int i=0;i<friends;i++){
            cin >> tmp;
            g[j].push_back(tmp);
        }
    }
    int t;
    cin >> t;
    while(t--){
        cin >> tmp;
        max_day=-1;
        first_day=0;
        nb_level.clear();
        level.resize(e);
        level.clear();
        bfs(tmp);
        //cout << "trace: ";
        bool first=true;
        for(int i=1;i<nb_level.size();i++){
            if(nb_level[i]>max_day){
                max_day=nb_level[i];
                    first_day=i;
            }
            //cout << nb_level[i] << " ";
        }
        //cout << "end trace\n";
        //first_day=0;
        if(first_day>0)
            cout << max_day << " " << first_day << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
