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

using namespace std;

int main()
{
    int N,lig,col;
    ll maxC,temp;
    int *M[1001];
    cin >> N;
    for(int i=0;i<N;i++){
        maxC=MIN_INT;
        cin >> lig >> col;
        ll *M[lig+1];
        for(int j=0;j<lig;j++){
            M[j]= new ll[col+1];
            for(int k=0;k<col;k++)
                cin >> M[j][k];
            M[j][col]=0;
        }
        M[lig]= new ll[col+1];
        memset(M[lig],0,sizeof(ll)*(col+1));
        /*for(int j=0;j<=lig;j++){
            for(int k=0;k<=col;k++)
                cout << M[j][k] << "  ";
            cout << endl;
        }*/
        for(int j=0;j<lig;j++){
            for(int k=col-2;k>=0;k--)
                M[j][k]+=M[j][k+1];
        }
        for(int k=0;k<col;k++){
            maxC=max(maxC,M[lig-1][k]);
            temp=0;
            for(int j=lig-2;j>=0;j--){
                if(M[j][k]<0)
                    break;
                temp+=M[j][k]+M[j+1][k];
            }
            maxC=max(maxC,temp);
        }
        cout << maxC << endl;
    }
    return 0;
}
