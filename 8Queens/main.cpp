#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii> > vvii;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
typedef long long ll;

const int oo = (int)1e9;

int n,m;

int ways(int i, int mask1,int mask2,int mask3){
    if(i>=n)
        return 1;
    int r = 0;
    for(int j=0;j<m;j++){
        if(!(mask1&(1<<j)) && !(mask2&(1<<j)) && !(mask3&(1<<j))){
            r+= ways(i+1,(mask1|(1<<j))>>1,(mask2|(1<<j))<<1,mask3|(1<<j));
        }
    }
    return r;
}

int main()
{
    n = m = 8;
    int k=8;
    cout << ways(0,0,0,0) << endl;
    return 0;
}
