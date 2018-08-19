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

int T[3];
int nb;
bool error;

bool add(int x){
    if(error) return false;
    bool in=false;
    for(int i=0;i<nb;i++){
        if(T[i]==x){
            in=true;
            break;
        }
    }
    if(!in && nb<3){
        T[nb]=x;
        nb++;
        return true;
    }
    else if(in)
        return true;
    error=true;
    return false;
}

bool verif(){
    if(nb<3) return true;
    if(nb>3) return false;
    sort(T,T+3);
    int x=T[2]-T[0];
    if(x%2!=0) return false;
    x/=2;
    if(T[1]-T[0]!=x) return false;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,tmp;
    bool rep1,rep2;
    error=false;
    nb=0;
    rep1=true;
    rep2=true;
    init(T,-1);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        rep1=add(tmp);
    }
    rep2=verif();
    if(rep1 && rep2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
