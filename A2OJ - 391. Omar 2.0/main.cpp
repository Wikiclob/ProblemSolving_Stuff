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

int charToInt(char c){
    return c-48;
}

char intToChar(int a){
    return a+48;
}

int main()
{
    std::ios::sync_with_stdio(false);
    string a,b,res,rest=0;

    int cc=0,cci;
    cin >> a >> b;
    res.resize(max(a,b)+1);
    cc = min(a.size(),b.size());
    cci = cc;
    do{
        cci--;
        res[cci] = intToChar((charToInt(a[cci])+charToInt(b[cci]+rest))%10);
        rest = (charToInt(a[cci])+charToInt(b[cci]+rest))/10;
    }while(cci>=0);
    if(cc<a.size()){
        for(int i=cc-1;i>=0;i--){
            res[i]
        }
    }
    if(cc<b.size()){
        for(int i=cc-1;i>=0;i--){

        }
    }
    return 0;
}
