#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int oo=1e9;

double dist(ii a,ii b){
    return sqrt(pow(a.f-b.f,2)+pow(a.s-b.s,2));
}

int main()
{
    int a,b,n;
    double mini=oo;
    double tmp;
    int x,y,v;
    cin >> a >> b >> n;
    while(n--){
        cin >> x >> y >> v;
        tmp=dist({a,b},{x,y})/v;
        if(tmp<mini)
            mini=tmp;
    }
    cout << fixed << setprecision(8) << mini << endl;
    return 0;
}
