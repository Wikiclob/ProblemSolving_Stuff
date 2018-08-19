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
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;



//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

vs M;
int n;

/*bool go(int i,int j){
    return i<n && j<n && i>=0 && j>=0;
}

int flood(int i,int j){
    int retour=0;
    queue<ii> Q;
    ii tmp;
    Q.push(ii(i,j));
    while(!Q.empty()){
        tmp = Q.front();
        Q.pop();
        if(M[tmp.f][tmp.s]=='#'){
            M[tmp.f][tmp.s]='.';
            retour++;
            for(int i_=0;i_<4;i_++){
                if(go(dx[i_]+tmp.f,dy[i_]+tmp.s) && M[dx[i_]+tmp.f][dy[i_]+tmp.s]=='#')
                    Q.push(ii(dx[i_]+tmp.f,dy[i_]+tmp.s));
            }
        }
    }
    return retour/2;
}

int solution(){
    int retour =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]=='#')
                retour+= flood(i,j);
        }
    }
    return retour;
}*/

int solution(){
    int retour =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]=='#'){
                if(i<n-1 && j<n-1){
                    if(M[i+1][j+1]=='#' && M[i][j+1] == '#' && M[i+1][j] == '#'){
                        retour +=2;
                        M[i][j] = M[i][j+1] = M[i+1][j] = M[i+1][j+1] = '.';
                    }
                    else if(M[i][j+1]=='#'){
                        retour++;
                        M[i][j] = M[i][j+1] = '.';
                    }
                    else if(M[i+1][j]=='#'){
                        retour++;
                        M[i][j] = M[i+1][j] = '.';
                    }
                }
                else if(i<n-1){
                    if(M[i+1][j]=='#'){
                        retour++;
                        M[i][j] = M[i+1][j] = '.';
                    }
                }
                else if(j<n-1){
                    if(M[i][j+1]=='#'){
                        retour++;
                        M[i][j] = M[i][j+1] = '.';
                    }
                }
            }
        }
    }
    return retour;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        M.resize(n);
        for(int j=0;j<n;j++)
            cin >> M[j];
        cout << "Case " << i << ": " << solution() << endl;
    }
    return 0;
}
