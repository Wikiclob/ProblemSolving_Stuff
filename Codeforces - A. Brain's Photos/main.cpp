#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main()
{
    int n,m;
    char c;
    bool colored=false;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c;
            if(c=='C' || c=='M' || c=='Y')
                colored=true;
        }
    }
    if(colored)
        cout << "#Color" << endl;
    else
        cout << "#Black&White" << endl;
    return 0;
}
