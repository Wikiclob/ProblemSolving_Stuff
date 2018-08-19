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
typedef vector<ll> vll;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

ll count_inversion_merge(ll array[], int first, int last)
{
    int mid = (first+last)/2;
    int ai = first;
    int bi = mid+1;
    ll final[last-first+1], finali=0;
    ll inversion = 0, i;

    while (ai <= mid && bi <= last) {
        if (array[ai] <= array[bi]) {
                final[finali++] = array[ai++];
        } else {
                final[finali++] = array[bi++];
                inversion += mid - ai + 1;
        }
    }

    while (ai <= mid)
        final[finali++] = array[ai++];

    while (bi <= last)
        final[finali++] = array[bi++];

    for (i=0 ; i<last-first+1 ; i++)
        array[i+first] = final[i];

    return inversion;
}

ll count_inversion(ll array[], int a, int b)
{
    ll x, y, z, mid;
    if (a >= b) return 0;

    mid = (a+b)/2;

    x = count_inversion(array, a, mid);
    y = count_inversion(array, mid+1, b);
    z = count_inversion_merge(array, a, b);

    return x+y+z;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll T,n,tmp;
    ll rep;
    cin >> T;
    while(T--){
        cin >> n;
        ll elements[n];
        for(int i=0;i<n;i++){
            cin >> tmp;
            elements[i]=tmp;
        }
        rep = count_inversion(elements, 0, n-1);
        cout << rep << endl;
    }
    return 0;
}
