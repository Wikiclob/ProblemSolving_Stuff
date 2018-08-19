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

int visited[20000001];
//int visits;

/*
int min(int a,int b,int c){
    return (a<b)?((a<c)?a:c):((b<c)?b:c);
}
int min_steps(int num){
    //visits++;
    if(num <= 1) return 0;
    if(visited[num]) return visited[num];
    return visited[num] = 1 + min(min_steps(num-1),(num%2==0)?min_steps(num/2):oo,(num%3==0)?min_steps(num/3):oo);
}
*/

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,num;
    int maxNum = 2;
    cin >> t;
    for(int i=1;i<=t;i++){
        //visits=0;
        //init(visited,0);
        cin >> num;
        //cout << "Case " << i << ": " << min_steps(num) << endl;
        //cout << "###with recursion: " << visits << endl;
        visited[1] = 0; visited[0] = 0;
        for(int i=maxNum;i<=num;i++){
            visited[i] = 1+visited[i-1];
            if(i%2==0) visited[i] = min(visited[i],1+visited[i/2]);
            if(i%3==0) visited[i] = min(visited[i],1+visited[i/3]);
        }
        maxNum = max(num,maxNum);
        cout << "Case " << i << ": " << visited[num] << endl;
        //cout << "###with dp: " << num-2+1 << endl;
        //cout << "visits(" << i << "): " << visits << endl;
    }
    return 0;
}
