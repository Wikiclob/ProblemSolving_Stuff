#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
using namespace std;
const int oo=1e9;
const int MAX=1010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int ax[8]={1,1,0,-1,-1,-1,0,1};
int ay[8]={0,1,1,1,0,-1,-1,-1};

int chartoint(char c){
    if(c>=97)
        return (c-'a'+1);
    return (c-'0');
}

bool can(int i,int j){
    return (i>=1 && i<=8 && j>=1 && j<=8);
}

int main()
{
    int moves=0;
    string inp;
    cin >> inp;
    for(int i=0;i<8;i++)
        moves+=(can(chartoint(inp[1])+ax[i],chartoint(inp[0])+ay[i]))?1:0;
    cout << moves << endl;
    return 0;
}
