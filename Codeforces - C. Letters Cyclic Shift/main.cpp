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
typedef long long ll;

int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    bool never=true;
    int c=0;
    while(s[c]=='a' && c<c<s.size()){
        c++;
    }
    while(c<s.size() && s[c]!='a'){
        s[c]-=1;
        c++;
        never=false;
    }
    if(never)
        s[s.size()-1]='z';
    cout << s << endl;
    return 0;
}
