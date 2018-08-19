#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
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

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

int n,m;
int M[15][110];
int from[15][110];
int value[15][110];
int beginning[15][110];
bool visited[15][110];

int dx[3]={-1,0,1};

int goX(int x){
    if(x>n) return 0;
    if(x<0) return n-1;
    return x;
}

int res,where;
string retour;

string backtrack(){
    int ix=m-1;
    string r=NumberToString(where+1);
    while(ix>0){
        r=NumberToString(from[where][ix]+1)+" "+r;
        where=from[where][ix];
        ix--;
    }
    return r;
}

void solve(){
    int ix;
    res=oo;
    where=-1;
    for(int j=0;j<m-1;j++){
        for(int i=0;i<n;i++){
            for(int k=0;k<3;k++){
                ix=goX(i+dx[k]);
                if(!visited[ix][j+1]){
                    value[ix][j+1]=value[i][j]+M[ix][j+1];
                    from[ix][j+1]=i;
                    visited[ix][j+1]=true;
                }
                else if(value[ix][j+1]>value[i][j]+M[ix][j+1]){
                    value[ix][j+1]=min(value[ix][j+1],value[i][j]+M[ix][j+1]);
                    from[ix][j+1]=i;
                }
            }
        }
    }
    string tmp;
    for(int i=0;i<n;i++){
        if(res>value[i][m-1]){
            res=value[i][m-1];
            where=i;
            retour=backtrack();
        }
        else if(res==value[i][m-1]){
            where=i;
            tmp=backtrack();
            if(tmp<retour)
                retour = tmp;
        }
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> n){
        cin >> m;
        init(visited,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> M[i][j];
                if(j==0){
                    value[i][0]=M[i][0];
                    beginning[i][0]=i;
                }
            }
        }
        solve();
        /*cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout << value[i][j] << " ";
            cout << endl;
        }
        cout << endl;*/

        cout <<"test: " <<  retour << endl << res << endl;
    }
    return 0;
}
