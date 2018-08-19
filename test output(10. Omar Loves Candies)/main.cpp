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
    ofstream output;
    ifstream input("input.in");
    output.open("output.out");
    int N,lig,col;
    ll maxC,maxL;
    ll sup[1001],inf[1001];
    short int M[1001][1001];
    input >> N;
    for(int i=0;i<N;i++){
        maxC=MIN_INT;
        maxL=MIN_INT;
        input >> lig >> col;
        memset(sup,0,sizeof(ll)*(col+1));
        memset(inf,0,sizeof(ll)*(col+1));
        memset(M,0,sizeof(short int)*(lig+1)*(col+1));
        for(int j=0;j<lig;j++)
            for(int k=0;k<col;k++)
                input >> M[j][k];
        for(int j=lig-1;j>=0;j--){
            for(int k=col-1;k>=0;k--){
                if(j%2==0){
                    sup[k]=inf[k]+sup[k+1]-inf[k+1]+M[j][k];
                    if(maxC<=sup[k]){
                        maxC=sup[k];
                    }
                }
                else{
                    inf[k]=sup[k]+inf[k+1]-sup[k+1]+M[j][k];
                    if(maxC<=inf[k]){
                        maxC=inf[k];
                    }
                }
            }
        }
        memset(sup,0,sizeof(ll)*(lig+1));
        memset(inf,0,sizeof(ll)*(lig+1));
        for(int k=col-1;k>=0;k--){
            for(int j=lig-1;j>=0;j--){
                if(k%2==0){
                    sup[j]=inf[j]+sup[j+1]-inf[j+1]+M[j][k];
                    if(maxL<=sup[j]){
                        maxL=sup[j];
                    }
                }
                else{
                    inf[j]=sup[j]+inf[j+1]-sup[j+1]+M[j][k];
                    if(maxL<=inf[j]){
                        maxL=inf[j];
                    }
                }
            }
        }
        output << max(maxC,maxL) << endl;
    }
    input.close();
    output.close();
    return 0;
}
