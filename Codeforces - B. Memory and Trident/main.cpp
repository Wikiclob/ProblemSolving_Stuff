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

int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    int x=0,y=0;
    cin >> s;
    if(s.size()%2!=0)
        cout << -1 << endl;
    else{
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case 'U': x--;break;
                case 'D': x++;break;
                case 'L': y--;break;
                case 'R': y++;break;
            }
        }
        cout << (int)(abs(x)+abs(y))/2 << endl;
    }
    return 0;
}
