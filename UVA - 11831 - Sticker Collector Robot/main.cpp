#include <bits/stdc++.h>

using namespace std;
const int MAX=100;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int F=0,n,m;
char M[MAX][MAX];

bool go(int i,int j){
    return (i + dx[F]>=0 && i+dx[F]<n && j+dy[F]>=0 && j+dy[F]<m && M[i + dx[F]][j+dy[F]]!='#');
}

void D(){
    F=(F+1<4)?F+1:0;
}

void E(){
    F=(F-1>=0)?F-1:3;
}

int main()
{
    int mov,posters;
    int posX,posY;
    string tmp,moves;
    while(true){
        posters=0;
        cin >> n >> m >> mov;
        if(n==0)
            break;
        for(int i=0;i<n;i++){
            cin >> tmp;
            for(int j=0;j<m;j++){
                M[i][j]=tmp[j];
                if(M[i][j]=='N'|| M[i][j]=='S' || M[i][j]=='L' || M[i][j]=='O'){
                    posX=i;
                    posY=j;
                }
            }
        }
        if(M[posX][posY]=='N')
            F=0;
        else if(M[posX][posY]=='S')
            F=2;
        else if(M[posX][posY]=='L')
            F=1;
        else
            F=3;
        cin >> moves;
        for(int i=0;i<mov;i++){
            switch(moves[i]){
                case 'D':D();/*cout << "Droite(D): nextF: "<< posX+dx[F] << " " << posY+dy[F] << endl;*/ break;
                case 'E':E();/*cout << "Gauche(E): nextF: "<< posX+dx[F] << " " << posY+dy[F] << endl;*/ break;
                case 'F':
                    if(go(posX,posY)){
                        posX+=dx[F];
                        posY+=dy[F];
                        //cout << "pos: " << posX << " " << posY << " '" << M[posX][posY] <<"'" << endl;
                        if(M[posX][posY]=='*'){
                            M[posX][posY]='.';
                            posters++;
                        }
                    }
                    /*else{
                        cout << "block: " << posX << " " << posY << endl;
                    }*/
                    break;
            }
        }
        cout << posters << endl;
    }
    return 0;
}
