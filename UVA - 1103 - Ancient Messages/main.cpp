#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
const int MAX=210;

int n,m;
int M[MAX][MAX];
bool visited[MAX][MAX];
string res;
int color;

int signe[MAX][MAX];

void to_binary(int *M,char hex){
    switch(hex){
        case '0':
            M[0]=0;M[1]=0;M[2]=0;M[3]=0;break;
        case '1':
            M[0]=0;M[1]=0;M[2]=0;M[3]=1;break;
        case '2':
            M[0]=0;M[1]=0;M[2]=1;M[3]=0;break;
        case '3':
            M[0]=0;M[1]=0;M[2]=1;M[3]=1;break;
        case '4':
            M[0]=0;M[1]=1;M[2]=0;M[3]=0;break;
        case '5':
            M[0]=0;M[1]=1;M[2]=0;M[3]=1;break;
        case '6':
            M[0]=0;M[1]=1;M[2]=1;M[3]=0;break;
        case '7':
            M[0]=0;M[1]=1;M[2]=1;M[3]=1;break;
        case '8':
            M[0]=1;M[1]=0;M[2]=0;M[3]=0;break;
        case '9':
            M[0]=1;M[1]=0;M[2]=0;M[3]=1;break;
        case 'a':
            M[0]=1;M[1]=0;M[2]=1;M[3]=0;break;
        case 'b':
            M[0]=1;M[1]=0;M[2]=1;M[3]=1;break;
        case 'c':
            M[0]=1;M[1]=1;M[2]=0;M[3]=0;break;
        case 'd':
            M[0]=1;M[1]=1;M[2]=0;M[3]=1;break;
        case 'e':
            M[0]=1;M[1]=1;M[2]=1;M[3]=0;break;
        case 'f':
            M[0]=1;M[1]=1;M[2]=1;M[3]=1;break;
    }
}

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool go(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m*4);
}

bool go1(int i,int j){
    return (i>=0 && i<=(n+1) && j>=0 && j<=(m*4+1));
}

void bfs(int i,int j){
    color++;
    queue<pair<int,int> > Q;
    pair<int,int> tmp;
    memset(signe,0,sizeof signe);
    Q.push({i,j});
    visited[i][j]=true;
    signe[i+1][j+1]=1;
    M[i][j]=color;
    while(!Q.empty()){
        tmp=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            if(go(tmp.f+dx[i],tmp.s+dy[i]) && !visited[tmp.f+dx[i]][tmp.s+dy[i]] && M[tmp.f+dx[i]][tmp.s+dy[i]]==1){
                Q.push({tmp.f+dx[i],tmp.s+dy[i]});
                M[tmp.f+dx[i]][tmp.s+dy[i]]=color;
                visited[tmp.f+dx[i]][tmp.s+dy[i]]=true;
                signe[tmp.f+dx[i]+1][tmp.s+dy[i]+1]=1;
            }
        }
    }


    /*cout << endl << "signe:" << endl;
    for(int i=0;i<=(n+1);i++){
        for(int j=0;j<=(m*4+1);j++){
            cout << signe[i][j];
        }
        cout << endl;
    }*/

    Q=queue<pair<int,int> >();
    int couleur=1;

    for(int i=0;i<=(n+1);i++){
        for(int j=0;j<=(m*4+1);j++){
            if(signe[i][j]==0){
                couleur++;
                Q.push({i,j});
                signe[i][j]=couleur;
                while(!Q.empty()){
                    tmp=Q.front();
                    Q.pop();
                    for(int k=0;k<4;k++){
                        if(go1(tmp.f+dx[k],tmp.s+dy[k]) && signe[tmp.f+dx[k]][tmp.s+dy[k]]==0){
                            Q.push({tmp.f+dx[k],tmp.s+dy[k]});
                            signe[tmp.f+dx[k]][tmp.s+dy[k]]=couleur;
                        }
                    }
                }
            }
        }
    }

    /*cout << endl << "colored:" << endl;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=(m*4+1);j++){
            cout << signe[i][j];
        }
        cout << endl;
    }*/

    // 1 white = W
    // 2 whites = A
    // 3 whites = K
    // 4 whites = J
    // 5 whites = S
    // 6 whites = D
    switch(couleur-1){
        case 1: res=res+'W';break;
        case 2: res=res+'A';break;
        case 3: res=res+'K';break;
        case 4: res=res+'J';break;
        case 5: res=res+'S';break;
        case 6: res=res+'D';break;
    }
    /*
    cout << "end bfs: " << res[res.length()-1] << endl;
    */
}

int main()
{
    ofstream output("output.out");
    string tmp;
    int cc;
    int Case_t=1;
    while(true){
        cin >> n;
        cin >> m;
        if(n==0 && m==0)
            break;
        //cout << "coord: " << n << " " << m << endl;
        memset(M,0,sizeof M);
        memset(signe,0,sizeof signe);
        memset(visited,false,sizeof visited);
        color=1;

        for(int i=0;i<n;i++){
            cin >> tmp;
            cc=0;
            for(int j=0;j<tmp.length();j++){
                to_binary(M[i]+cc*4,tmp[j]);
                cc++;
            }
        }
        /*cout << endl << "matrix:" << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m*4;j++){
                cout << M[i][j];
            }
            cout << endl;
        }*/
        //int test=1;
        res="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m*4;j++){
                if(M[i][j]==1){
                    //cout << "bfs: " << test++ << endl;
                    bfs(i,j);
                }
            }
        }
        sort(res.begin(),res.end());
        output << "Case " << Case_t << ": " << res << endl;
        cout << "Case " << Case_t++ << ": " << res << endl;
    }
    return 0;
}
