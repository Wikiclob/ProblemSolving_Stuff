#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define PI 3.14159265
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (a * (b / gcd(a, b))); } // divide bef multiply!

pair<ll,ll> simple_form(pair<ll,ll> p){
    ll g=gcd(p.first,p.second);
    pair<ll,ll> res={p.first/g,p.second/g};
    return res;
}

int main()
{
    int N;
    pair<ll,ll> F1,F2,GCD,PCM;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin >>F1.first>>F1.second>>F2.first>>F2.second;
        F1=simple_form(F1);
        F2=simple_form(F2);
        GCD=simple_form({gcd(F1.first,F2.first),lcm(F1.second,F2.second)});
        PCM=simple_form({lcm(F1.first,F2.first),gcd(F1.second,F2.second)});
        cout << GCD.first << "/" << GCD.second << " " << PCM.first << "/" << PCM.second<<endl;
    }
    return 0;
}
