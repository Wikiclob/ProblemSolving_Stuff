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

//int dx[8]={-1,-1,0,1,1,1,0};
//int dy[8]={0,1,1,1,0,-1,-1};

//int dx[4]={-1,0,1,0};
//int dy[4]={0,1,0,-1};


int main()
{
    std::ios::sync_with_stdio(false);
    int socks,days,colors;
    cin >> socks >> days >> colors;
    bool blocks[socks];
    vi Sock_color(socks);
    vvi pairs(socks);
    for(int i=0;i<socks;i++)
        cin >> Sock_color[i];
    int tmp1,tmp2;
    for(int i=0;i<days;i++){
        cin >> tmp1 >> tmp2;
        pairs[tmp1].push_back(tmp2);
        pairs[tmp2].push_back(tmp1);
    }
    for(int i=0;i<socks;i++){
        int countC[colors];
        int maxIdx=0;
        int maxC=0;
        bool block=false;
        int block_idx;
        for(int j=0;j<pairs[i].size();j++){
            if(!blocks[Sock_color[pairs[i][j]]]){
                countC[Sock_color[pairs[i][j]]]++;
                if(countC[Sock_color[pairs[i][j]]]>maxC){
                    maxIdx = Sock_color[pairs[i][j]];
                    maxC = countC[Sock_color[pairs[i][j]]];
                }
            }
            else{
                block=true;
                block_idx=pairs[i][j];
                break;
            }
        }
        if(block){
            Sock_color[i] = Sock_color[block_idx];
            blocks[i] = true;
        }
        else{

        }
    }
    return 0;
}
