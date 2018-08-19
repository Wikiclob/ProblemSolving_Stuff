#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int MAX=100;
int n,m;
bool M[MAX][MAX];
bool visited[MAX][MAX];
int A,B;
int even,odd;

//(x-i=A || i-x=A) && (y-j=B || j-y=B)
//(x-i=B || i-x=B) && (y-j=A || j-y=B)
//=>
//(x=A+i || x=i-A) && (y=B+j || y=j-B)
//(x=B+i || x=i-B) && (y=A+j || y=j-A)
//=>
//(A+i,B+j),(A+i,j-B),(i-A,B+j),(i-A,j-B)
//(B+i,A+j),(B+i,j-A),(i-B,A+j),(i-B,j-A)

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};

bool go(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m && !M[i][j]);
}

/*
bool possible(int i,int j,int a,int b){
    return (((abs(i-a)==A && abs(j-b)==B)||(abs(i-a)==B && abs(j-b)==A)) && !M[a][b]);
}
*/

void bfs(){
    queue<pair<int,int> > Q;
    pair<int,int> tmp;
    int calcul;
    Q.push({0,0});
    visited[0][0]=true;
    while(!Q.empty()){
        calcul=0;
        tmp=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            if(A==0 && i==2)
                break;
            if(B!=0 || i%2!=0){
                if(go(tmp.f+A*dx[i],tmp.s+B*dy[i])){

                    calcul++;
                    if(!visited[tmp.f+A*dx[i]][tmp.s+B*dy[i]]){
                        Q.push({tmp.f+A*dx[i],tmp.s+B*dy[i]});
                        visited[tmp.f+A*dx[i]][tmp.s+B*dy[i]]=true;
                    }
                }
            }
        }
        if(A!=B){
            for(int i=0;i<4;i++){
                if(B==0 && i==2)
                    break;
                if(A!=0 || i%2!=0){
                    if(go(tmp.f+B*dx[i],tmp.s+A*dy[i])){
                        calcul++;
                        if(!visited[tmp.f+B*dx[i]][tmp.s+A*dy[i]]){
                            Q.push({tmp.f+B*dx[i],tmp.s+A*dy[i]});
                            visited[tmp.f+B*dx[i]][tmp.s+A*dy[i]]=true;
                        }
                    }
                }
            }
        }
        if(calcul%2)
            odd++;
        else
            even++;
    }
}

int main()
{
    //ofstream output("output.out");
    int t;
    int water,wx,wy;
    cin >> t;
    for(int i=1;i<=t;i++){
        memset(visited,false,sizeof visited);
        memset(M,false,sizeof M);
        even=0;
        odd=0;
        cin >> n >> m >> A >> B;
        cin >> water;
        while(water--){
            cin >> wx >> wy;
            M[wx][wy]=true;
        }
        bfs();
        cout << "Case " << i << ": " << even << " " << odd << endl;
    }
    return 0;
}
