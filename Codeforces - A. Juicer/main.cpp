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
    int n,maxSize,emptySize;
    int tmp;
    int sum=0;
    int waste=0;
    cin >> n >> maxSize >> emptySize;
    for(int i=0;i<n;i++){
        cin >> tmp;
        if(maxSize>=tmp){
            sum+=tmp;
            if(sum>emptySize){
                sum=0;
                waste++;
            }
        }
    }
    cout << waste << endl;
    return 0;
}
