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
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    int N,k,taille;
    char M[10][82],c;
    char ch[81];

    scanf("%d",&N);
    fflush(stdin);
    for(int i=0;i<N;i++){
        for(int j=0;j<10;j++){
            k=0;
            while((c=getchar())!='\n'){
                M[j][k]=c;
                k++;
            }
            taille=k-2;
            //cout << taille << endl;
        }
        for(int j=1;j<=taille;j++){
            c=0;
            for(k=1;k<9;k++){
                if(M[k][j]=='\\')
                    c|=(1<<(k-1));
                else
                    c|=(0<<(k-1));
            }
            ch[j-1]=c;
            //printf("%c",c);
        }
        ch[taille]='\0';
        printf("%s\n",ch);
        //if(i!=N-1)
            //getchar();
    }
    return 0;
}
