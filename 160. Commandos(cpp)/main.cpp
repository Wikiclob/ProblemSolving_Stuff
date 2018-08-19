#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int M[11][11][11];
    int T,N,F,X,Y,H;
    scanf("%i",&T);
    for(int i=0;i<T;i++){
        memset(M,0,sizeof(M));
        scanf("%i",&N);
        for(int j=0;j<N;j++){
            scanf("%i%i%i%i",&F,&Y,&X,&H);
            M[F-1][X][Y]=H;
        }
        for(int j=9;j>=0;j--)
            for(int k=1;k<11;k++)
                for(int l=1;l<11;l++)
                    M[j][k][l]+=max(max(M[j+1][k][l],M[j][k-1][l]),M[j][k][l-1]);
        printf("%i\n",M[0][10][10]);
    }
    return 0;
}
