#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
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

int main()
{
    int lig=0,col=0;
    int saveL=0,saveC=0;
    int M[102][102];
    memset(M,0,sizeof(int)*102*102);
    M[1][1]=1;
    while(true){
        cin >> lig >> col;
        if(lig==col && lig==-1)
            break;
        //if(saveL>=lig && saveC>=col)
        //    cout << M[lig+1][col+1] << endl;
        else{
            for(int i=1;i<lig+2;i++){
                for(int j=1;j<col+2;j++){
                    if(i!=1 || j!=1){
                        //if(i>saveL+1 || j>saveC+1)
                            M[i][j]=(M[i][j-1]+M[i-1][j])%MOD_INT;
                    }
                }
            }
            //saveL=max(lig,saveL);
            //saveC=max(col,saveC);
            cout << M[lig+1][col+1] << endl;
            //cout << "it's the second one" << endl;
        }

    }
    return 0;
}
