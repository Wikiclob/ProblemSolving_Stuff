#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
using namespace std;
const int oo=1e9;
const int MAX=51;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

int n;
char M[MAX][MAX];
int dx[8]={-1,-1,0,1,1,1,0};
int dy[8]={0,1,1,1,0,-1,-1};
int idx[8]={1,1,0,-1,-1,-1,0,1};
int idy[8]={0,-1,-1,-1,0,1,1,1};
int MAX_M=8;

double dist(ii a,ii b){
    return sqrt(pow(a.f-b.f,2)+pow(a.s-b.s,2));
}

bool in(int x,int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void show(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << M[i][j];
        cout << endl;
    }
}

bool change;

void box(int x,int y){
    M[x][y]='o';
    cout << "dist: " << dist({2,2},{x,y}) << endl;
    show();
    for(int i=0;i<MAX_M;i++){
        if(!change){
            if(in(x+dx[i],y+dy[i]) && M[x+dx[i]][y+dy[i]]=='.'){
                if(i>=5)
                    change=true;
                box(x+dx[i],y+dy[i]);
                break;
            }
        }
        else{
            if(in(x+idx[i],y+idy[i]) && M[x+idx[i]][y+idy[i]]=='.'){
                box(x+idx[i],y+idy[i]);
                break;
            }
            if(in(x+idx[i],y+idy[i]) && M[x+idx[i]][y+idy[i]]=='o')
                break;
        }

    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    string inp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> inp;
        for(int j=0;j<n;j++)
            M[i][j]=inp[j];
    }
    cout << "before" << endl;
    show();
    bool found=false;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(M[i][j]=='.'){
                found=true;
                change=false;
                box(i,j);
                break;
            }
        }
        if(found)
            break;
    }

    //show();
    return 0;
}
