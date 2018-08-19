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
    //cout << "Hello world!" << endl;
    int N,m,n;
    int x,y;
    int res=0;
    bool verif;
    scanf("%d",&N);
    char M[1000][1000];
    char V[1000][1000];
    for(int i=0;i<N;i++){
        res=0;
        verif=true;
        //cin >> n >> m;cin.ignore();
        scanf("%d%d",&n,&m);
        fflush(stdin);
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                M[j][k]=getchar();
            }
            getchar();
        }
        /*cout << "mat1:\n";
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cout << M[j][k] << " ";
            }
            cout << endl;
        }*/
        scanf("%d%d",&x,&y);
        fflush(stdin);
        for(int j=0;j<x;j++){
            for(int k=0;k<y;k++){
                V[j][k]=getchar();
            }
            getchar();
        }
        /*cout << "mat2:\n";
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cout << V[j][k] << " ";
            }
            cout << endl;
        }*/
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(M[j][k]==V[0][0]){
                    verif=true;
                    for(int l=0;l<x;l++){
                        for(int o=0;o<y;o++){
                            if(M[j+l][k+o]!=V[l][o]){
                                verif=false;
                                //cout << "diff " << M[j+l][k+o] << " " << V[l][o] << endl;
                                break;
                            }
                        }
                    }
                    if(verif)
                        res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
