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

int diff(int t1,int t2,bool way){
    if(way){
        if(t2<t1)
            return (720-t1+t2);
        else
            return t2-t1;
    }
    else{
        if(t2>t1)
            return t1+720-t2;
        else
            return t1-t2;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tmp,diff1,diff2;
    int rep;
    vector<string> times(3);
    vector<int> times_s(3);
    int pos[3][3] = {{0,1,2},{1,0,2},{2,0,1}};
    cin >> t;
    while(t--){
        cin >> times[0] >> times[1] >> times[2];
        rep = 0;
        for(int i=0;i<3;i++){
            tmp = times[i].find(':');
            times_s[i] = atoi(times[i].substr(0,tmp).c_str())*60 + atoi(times[i].substr(tmp+1).c_str());
        }
        //cout << "t1: " << times_s[0] << " t2: " << times_s[1] << " t3: " << times_s[2] << endl;
        bool probably = false;
        bool stop = false;
        for(int i=0;i<3;i++){
            for(int j=0;j<2;j++){
                diff1 = diff(times_s[pos[i][0]],times_s[pos[i][1]],!j);
                diff2 = diff(times_s[pos[i][0]],times_s[pos[i][2]],j);
                //cout << times[pos[i][0]] << " => " << times[pos[i][1]] << " , " << times[pos[i][2]] << endl;
                //cout << "##diff## " << diff1 << " " << diff2 << endl;
                if(diff1<=480 && diff2 <=480 && diff1==diff2){
                    if(!probably){
                        probably = true;
                        rep = pos[i][0];
                    }
                    else if(rep != pos[i][0]){
                        probably = false;
                        stop = true;
                        break;
                    }
                }
            }
            if(stop)
                break;
        }
        if(stop || !probably)
            cout << "Look at the sun" << endl;
        else
            cout << "The correct time is " << times[rep] << endl;
    }
    return 0;
}
