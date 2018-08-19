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

using namespace std;

bool M[200][200];
int bX,bY,moves;
void knight_moves(int X,int Y){
    if(X-1>=0 && Y+2<bY){
        if(!M[X-1][Y+2]){
            M[X-1][Y+2]=true;
            moves++;
            knight_moves(X-1,Y+2);
        }
    }
    if(X-2>=0 && Y+1 <bY){
        if(!M[X-2][Y+1]){
            M[X-2][Y+1]=true;
            moves++;
            knight_moves(X-2,Y+1);
        }
    }
    if(X+1<bX && Y+2<bY){
        if(!M[X+1][Y+2]){
            M[X+1][Y+2]=true;
            moves++;
            knight_moves(X+1,Y+2);
        }
    }
    if(X+2<bX && Y+1<bY){
        if(!M[X+2][Y+1]){
            M[X+2][Y+1]=true;
            moves++;
            knight_moves(X+2,Y+1);
        }
    }
    if(X-1>=0 && Y-2>=0){
        if(!M[X-1][Y-2]){
            M[X-1][Y-2]=true;
            moves++;
            knight_moves(X-1,Y-2);
        }
    }
    if(X-2>=0 && Y-1>=0){
        if(!M[X-2][Y-1]){
            M[X-2][Y-1]=true;
            moves++;
            knight_moves(X-2,Y-1);
        }
    }
    if(X+1<bX && Y-2>=0){
        if(!M[X+1][Y-2]){
            M[X+1][Y-2]=true;
            moves++;
            knight_moves(X+1,Y-2);
        }
    }
    if(X+2<bX && Y-1>=0){
        if(!M[X+2][Y-1]){
            M[X+2][Y-1]=true;
            moves++;
            knight_moves(X+2,Y-1);
        }
    }
}

int main()
{
    int N;
    int KnX,KnY;
    cin >> N;
    while(N--){
        memset(M,false,sizeof(bool)*200*200);
        cin >> bX >> bY >> KnX >> KnY;
        M[KnX-1][KnY-1]=true;
        moves=1;
        knight_moves(KnX-1,KnY-1);
        cout << moves << endl;
    }
    return 0;
}
