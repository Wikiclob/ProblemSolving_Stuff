#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define init(M,x) memset(M,x,sizeof M)
using namespace std;
const int oo=1e9;
const int MAX=100010;
const int UNVISITED=-1;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

int A[MAX];
int B[MAX];

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    int sum;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> A[i];
    B[n-1]=A[n-1];
    sum=B[n-1];
    for(int i=n-2;i>=0;i--){
        B[i]=A[i]+sum;
        sum=B[i]-sum;
    }
    for(int i=0;i<n-1;i++)
        cout << B[i] << " ";
    cout << B[n-1] << endl;
    return 0;
}
