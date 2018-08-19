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

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

vector<int> Team;

int main()
{
    std::ios::sync_with_stdio(false);
    int n,tmp;
    int sum=0;
    cin >> n;
    bool can=true;
    for(int i=0;i<n;i++){
        cin >> tmp;
        Team.push_back(tmp);
        sum+=tmp;
    }
    if(sum%2==1){
        cout << "NO" << endl;
        can=false;
    }
    else{
        for(int i=0;i<n;i++){
            if(Team[i]%2==1){
                if(i<n-1 && Team[i+1]>0){
                    Team[i+1]--;
                }
                else{
                    cout << "NO" << endl;
                    can=false;
                    break;
                }
            }
        }
        if(can)
            cout << "YES" << endl;
    }
    return 0;
}
