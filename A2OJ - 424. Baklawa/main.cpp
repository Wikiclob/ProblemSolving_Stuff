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
    int t;
    int x,y,z,n,xi,yi,zi;
    bool isImpair = false;
    int joker=0;
    int drop=0;
    cin >> t;
    while(t--){
        int T[6];
        T[0]=T[1]=T[2]=T[3]=T[4]=T[5]=2;
        isImpair = false;
        joker = 0;
        drop = 0;
        cin >> x >> y >> z >> n;
        while(n--){
            cin >> xi >> yi >> zi;
            T[0] = min(T[0],xi-1);
            T[2] = min(T[2],yi-1);
            T[4] = min(T[4],zi-1);
            T[1] = min(T[1],x-xi);
            T[3] = min(T[3],y-yi);
            T[5] = min(T[5],z-zi);
        }
        for(int i=0;i<6;i++){
            //cout << i << ": " << T[i] << endl;
            if(T[i]==1)
                isImpair=!isImpair;
            else if(T[i]!=0){
                joker++;
                if(T[i]!=2)
                    drop+=T[i]-2;
            }
        }
        if(joker!=0){
            if(joker%2==1 && drop%2==0)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
        }
        else{
            if(isImpair)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
        }
    }
    return 0;
}
