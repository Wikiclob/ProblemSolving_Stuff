#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
const int MAX=25;

typedef pair<int,int> ii;


char M[MAX][MAX];
int n,m;
int noX,noY;
char land;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool go(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

bool go1(int i,int j){
    return (i>=0 && i<n && j>=-1 && j<=m);
}

int bfs(){
    queue<ii> Q;
    ii tmp;
    int max_t=0;
    int tmp_l;
    int not_this_land;
    /*
    cout << "land: " << endl;
    for(int l=0;l<n;l++){
        for(int o=0;o<m;o++){
            cout << M[l][o];
        }
        cout << endl;
    }
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==land){
                not_this_land=false;
                Q.push({i,j});
                if(i==noX && j==noY)
                    not_this_land=true;
                M[i][j]='\0';
                tmp_l=1;
                while(!Q.empty()){
                    tmp=Q.front();
                    Q.pop();
                    for(int k=0;k<4;k++){
                        if(go(tmp.f+dx[k],tmp.s+dy[k]) && M[tmp.f+dx[k]][tmp.s+dy[k]]==land){
                            M[tmp.f+dx[k]][tmp.s+dy[k]]='\0';
                            Q.push({tmp.f+dx[k],tmp.s+dy[k]});
                            tmp_l++;
                            if(tmp.f+dx[k]==noX && tmp.s+dy[k]==noY)
                                not_this_land=true;
                        }
                        else if(go1(tmp.f+dx[k],tmp.s+dy[k])){
                            if(tmp.s+dy[k]==m && M[tmp.f+dx[k]][0]==land){
                                M[tmp.f+dx[k]][0]='\0';
                                Q.push({tmp.f+dx[k],0});
                                tmp_l++;
                                if(tmp.f+dx[k]==noX && noY==0)
                                    not_this_land=true;
                            }
                            else if(tmp.s+dy[k]==-1 && M[tmp.f+dx[k]][m-1]==land){
                                M[tmp.f+dx[k]][m-1]='\0';
                                Q.push({tmp.f+dx[k],m-1});
                                tmp_l++;
                                if(tmp.f+dx[k]==noX && noY==(m-1))
                                    not_this_land=true;
                            }
                        }
                    }
                }
                if(!not_this_land){
                    if(tmp_l>max_t){
                        max_t=tmp_l;
                    }
                }
                /*cout << "land: " << endl;
                for(int l=0;l<n;l++){
                    for(int o=0;o<m;o++){
                        cout << M[l][o];
                    }
                    cout << endl;
                }*/
            }

        }
    }
    return max_t;
}

int main()
{
    //ofstream output("output.out");
    string tmp;
    int res;
    while(cin >> n){
        cin >> m;
        for(int i=0;i<n;i++){
            cin >> tmp;
            for(int j=0;j<m;j++){
                M[i][j]=tmp[j];
            }
        }
        cin >> noX >> noY;
        land = M[noX][noY];
        res=bfs();
        //output << res << endl;
        cout << res << endl;
    }
    return 0;
}
