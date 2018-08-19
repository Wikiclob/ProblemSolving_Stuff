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


int main()
{
    std::ios::sync_with_stdio(false);
    int t,n,q;
    int p1,p2;
    map<int,bool> exist;
    vi mini;
    vi maxi;
    cin >> t;
    while(t--){
        mini.clear();
        maxi.clear();
        exist.clear();
        cin >> n >> q;
        for(int i=0;i<n;i++){
            cin >> p1 >> p2;
            if(p1==p2)
            exist[p1]=true;
            mini.push_back(min(p1,p2));
            maxi.push_back(max(p1,p2));
        }
        sort(mini.begin(),mini.end());
        sort(maxi.begin(),maxi.end());
        for(int i=0;i<q;i++){
            cin >> p1;
            if(exist.find(p1)!=exist.end())
                cout << "YES" << endl;
            else{
                int b = upper_bound(mini.begin(),mini.end(),p1)-mini.begin();
                int c = lower_bound(maxi.begin(),maxi.end(),p1)-maxi.begin();
                if(b!=mini.size() && b!=0 && c!=maxi.size() && c!=0)
                    cout << "YES" << endl;
                else
                    cout << "NOT SURE" << endl;
            }
        }
    }
    return 0;
}
