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

int pos;
vector<int> checkpoints;


int main()
{
    int n,tmp;
    int dist;
    int now;
    std::ios::sync_with_stdio(false);
    cin >> n >> pos;
    for(int i=0;i<n;i++){
        cin >> tmp;
        checkpoints.push_back(tmp);
    }
    checkpoints.push_back(pos);
    sort(checkpoints.begin(),checkpoints.end());
    int count_n=0;
    int i,j;
    vector<int>::iterator itnow=lower_bound(checkpoints.begin(),checkpoints.end(),pos);
    now=itnow-checkpoints.begin();
    if(now!=0 && now!=(checkpoints.size()-1)){
        i=now-1;
        j=now+1;
    }
    else if(now == 0){
        i=-1;
        j=1;
    }
    else{
        i=checkpoints.size()-2;
        j=-1;
    }
    dist=0;
    while(count_n<n-1){
        //cout << "i: " << i << " j: " << j << " now: " << now << endl;
        if(i>=0 && j>=0){
            if(abs(checkpoints[i]-checkpoints[now])<abs(checkpoints[j]-checkpoints[now])){
                dist+=abs(checkpoints[i]-checkpoints[now]);
                now=i;
                i--;
                count_n++;
            }
            else{
                dist+=abs(checkpoints[j]-checkpoints[now]);
                now=j;
                j++;
                count_n++;
            }
        }
        else if(i>=0){
            dist+=abs(checkpoints[i]-checkpoints[now]);
            now=i;
            i--;
            count_n++;
        }
        else if(j<=n){
            dist+=abs(checkpoints[j]-checkpoints[now]);
            now=j;
            j++;
            count_n++;
        }
        //cout << "dist: " << dist << " i: " << i << " j: " << j << endl;
    }
    cout << dist << endl;
    return 0;
}
