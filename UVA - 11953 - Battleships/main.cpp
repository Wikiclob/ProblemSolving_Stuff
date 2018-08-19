#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
const int MAX = 110;

typedef pair<int,int> ii;

int n;
char M[MAX][MAX];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool go(int i,int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

int bfs(){
    int ships=0;
    bool ship;
    queue<ii> Q;
    ii tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]=='x' || M[i][j]=='@'){
                if(M[i][j]=='x')
                    ship=true;
                else
                    ship=false;
                Q.push({i,j});
                M[i][j]='-';
                while(!Q.empty()){
                    tmp=Q.front();
                    Q.pop();
                    for(int k=0;k<4;k++){
                        if(go(tmp.f+dx[k],tmp.s+dy[k]) && (M[tmp.f+dx[k]][tmp.s+dy[k]]=='x' || M[tmp.f+dx[k]][tmp.s+dy[k]]=='@')){
                            if(!ship && M[tmp.f+dx[k]][tmp.s+dy[k]]=='x')
                                ship=true;
                            M[tmp.f+dx[k]][tmp.s+dy[k]]='-';
                            Q.push({tmp.f+dx[k],tmp.s+dy[k]});
                        }
                    }
                }
                if(ship)
                    ships++;
            }
        }
    }
    return ships;
}

int main()
{
    //ofstream output("output.out");
    int t;
    int res;
    string tmp;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> tmp;
            for(int k=0;k<n;k++){
                M[j][k]=tmp[k];
            }
        }
        res=bfs();
        //output << "Case " << i << ": " << res << endl;
        cout << "Case " << i << ": " << res << endl;
    }
    return 0;
}
