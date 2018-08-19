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
    int n,tmp;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> tmp;
        cout << "Case " << i << ":" << endl;
        if(tmp<=5)
            cout << "Languages" << endl;
        else if (tmp <=7)
            cout << "Read and Write" << endl;
        else if(tmp <=12)
            cout << "Robotics" << endl;
        else if(tmp <=19)
            cout << "Programming and Robotics" << endl;
        else
            cout << "Read about everything" << endl;
    }
    return 0;
}
