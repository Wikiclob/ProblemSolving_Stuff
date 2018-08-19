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
typedef pair<string,string> ss;

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};

int pow2(int a){
    return a*a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream output("output.out");
    output << "{";
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(j==0) output << "{";
            int sum = 0;
            if(i<=j){
                for(int k=i;k<=j;k++){
                    sum = (sum + pow2(k)%10)%10;
                }
            }
            else{
                for(int k=i;k<=9;k++)
                    sum = (sum+ pow2(k)%10)%10;
                for(int k=0;k<=j;k++)
                    sum = (sum+ pow2(k)%10)%10;
            }
            output << sum;
            cout << i << " => " << j << " : " << sum << endl;
            if(j!=9)
                output << ",";
        }
        output << "}";
        if(i!=9)
            output << ",\n";
        else
            output << "}";
    }
    return 0;
}
