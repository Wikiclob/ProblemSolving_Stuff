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
typedef vector<ll> vll;
typedef pair<string,string> ss;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,tmp,x,y;
    cin >> n >> m;
    vi values(n);
    vvi relations(n);
    bool visited[n];
    init(visited,false);
    for(int i=0;i<n;i++){
        cin >> tmp;
        values[i] = tmp;
    }
    for(int i=0;i<m;i++){
        cin >> x >> y;
        relations[x].push_back(y);
        relations[y].push_back(x);
    }
    queue<int> q;
    ll sum;
    bool possible = true;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            sum = 0;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int now = q.front();
                sum += values[now];
                q.pop();
                for(int j=0;j<relations[now].size();j++){
                    if(!visited[relations[now][j]]){
                        q.push(relations[now][j]);
                        visited[relations[now][j]] = true;
                    }
                }
            }
            if(sum!=0){possible = false; break;}
        }
    }
    if(possible) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
