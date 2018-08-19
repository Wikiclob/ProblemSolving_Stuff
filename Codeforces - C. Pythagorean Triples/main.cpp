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
    long long n,m,k;
    bool solution = true;
    cin >> n;
    if(n%2==1){
        if(n==1)
            solution=false;
        else{
            m=(n*n-1);
            m/=2;
            k=(n*n+1);
            k/=2;
        }
    }
    else{
        if(n==2)
            solution=false;
        else{
            m=(n/2)*(n/2);
            m--;
            k=(n/2)*(n/2);
            k++;
        }
    }
    if(solution)
        cout << m << " " << k << endl;
    else
        cout << -1 << endl;
    return 0;
}
