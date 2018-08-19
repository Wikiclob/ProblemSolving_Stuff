#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
#define MOD_INT (1000000007)

using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;

int Ant[51][51],n,m;

void super_ant_move(int x,int y,int time){
    int i,j;
    if(time>0){
        int moves=1;
        for(i=x+1;i<=n;i++){
            if(moves<=time){
                Ant[i][y]++;
                super_ant_move(i,y,time-moves);
                moves++;
            }
            else
                break;
        }
        moves=1;
        for(i=x-1;i>=1;i--){
            if(moves<=time){
                Ant[i][y]++;
                super_ant_move(i,y,time-moves);
                moves++;
            }
            else
                break;
        }
        moves=1;
        for(i=y+1;i<=m;i++){
            if(moves<=time){
                Ant[x][i]++;
                super_ant_move(x,i,time-moves);
                moves++;
            }
            else
                break;
        }
        moves=1;
        for(i=y-1;i>=1;i--){
            if(moves<=time){
                Ant[x][i]++;
                super_ant_move(x,i,time-moves);
                moves++;
            }
            else
                break;
        }
        moves=1;
        for(i=x+1,j=y+1;i<=n && j<=m;i++,j++){
            if(moves<=time){
                Ant[i][j]++;
                super_ant_move(i,j,time-moves);
                moves++;
            }
            else
                break;
        }
        moves=1;
        for(i=x-1,j=y+1;i>=1 && j<=m;i--,j++){
            if(moves<=time){
                Ant[i][j]++;
                super_ant_move(i,j,time-moves);
                moves++;
            }
            else
                break;
        }
        moves=1;
        for(i=x+1,j=y-1;i<=n && j>=1;i++,j--){
            if(moves<=time){
                Ant[i][j]++;
                super_ant_move(i,j,time-moves);
                moves++;
            }
            else
                break;
        }
        moves=1;
        for(i=x-1,j=y-1;i>=1 && j>=1;i--,j--){
            if(moves<=time){
                Ant[i][j]++;
                super_ant_move(i,j,time-moves);
                moves++;
            }
            else
                break;
        }
    }
}

int main()
{
    //ofstream output("output.out");
    //ifstream input("input.in");
    int N,time,superX,superY,score,temp;
    int Sugar[51][51];
    //input >> N;
    scanf("%d",&N);
    while(N--){
        memset(Ant,0,sizeof(int)*51*51);
        score=0;
        scanf("%d%d%d%d%d",&n,&m,&time,&superX,&superY);
        //input >> n >> m >> time >> superX >> superY;
        Ant[superX][superY]=1;
        super_ant_move(superX,superY,time);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                scanf("%d",&Sugar[i][j]);
                //input >> Sugar[i][j];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                temp=(Ant[i][j]*Sugar[i][j])%MOD_INT;
                score=(score+temp)%MOD_INT;
            }
        }
        printf("%d\n",score);
        //output << score << "\n";
    }
    //input.close();
    //output.close();
    return 0;
}
