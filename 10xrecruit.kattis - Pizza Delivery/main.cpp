#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
#define BE(x) x.begin(),x.end()
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<string,string> ss;

int dx[8]={-1,-1,0,1,1,1,0};
int dy[8]={0,1,1,1,0,-1,-1};

int n,m;

bool go(int a,int b){
    if(a>=0 && a<n && b>=0 && b<m)
        return true;
    return false;
}

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

int ab(int a){
    if(a>=0) return a;
    return -a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tmp;
    cin >> t;
    while(t--){
        cin >> m >> n;
        int M[n][m];
        ll val[n][m]={0};
        memset(val,0,sizeof(ll) *n);
        bool visited[n][m] = {false};
        memset(visited,false,sizeof(bool)*n);
        int maximum = 0;
        int minI,minJ;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                cin >> M[i][j];
                if(maximum < M[i][j]){
                    minI = i;
                    minJ = j;
                    maximum = M[i][j];
                }
            }
        ll dist;
        bool change = true;
        visited[minI][minJ] = true;
        while(change){
            change = false;
            int mini = minI,minj=minJ;
            dist = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    dist+= M[i][j]*(ab(i-minI)+ab(j-minJ));
                }
            }
            for(int i=0;i<8;i++){
                if(go(minI+dx[i],minJ+dy[i]) && !visited[minI+dx[i]][minJ+dy[i]]){
                    tmp = 0;
                    0visited[minI+dx[i]][minJ+dy[i]] = true;
                    for(int ii=0;ii<n;ii++)
                        for(int jj=0;jj<m;jj++)
                            tmp+= M[ii][jj]*(ab(ii-minI-dx[i])+ab(jj-minJ-dy[i]));
                    if(dist > tmp){
                        dist = tmp;
                        mini = minI+dx[i];
                        minj = minJ+dy[i];
                        change = true;
                    }
                }
            }
            minI = mini;
            minJ = minj;
        }
        cout << dist << " blocks" << endl;
    }
    return 0;
}
