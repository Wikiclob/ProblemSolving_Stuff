#include <bits/stdc++.h>//all
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
    int N,stop,last,first;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&stop);
        int T[stop-1];
        int M[stop][stop];
        memset(M,0,sizeof(int)*stop*stop);
        for(int j=0;j<stop-1;j++){
            scanf("%d",&T[j]);
        }
        for(int j=1;j<stop;j++){
            for(int k=j;k<stop;k++){
                cout << M[j][k-1] << "+" << T[k-1] << " ou " << M[j-1][k] << "\n";
                M[j][k]=max((M[j][k-1]+T[k-1]),M[j-1][k]);
            }
            cout << "-----------\n";
        }
        for(int j=0;j<stop;j++){
            for(int k=0;k<stop;k++){
                cout << M[j][k] << " ";
            }
            cout << "\n";
        }
        last=-1;
        first=-1;
        int j=stop-1;
        int k=stop-1;
        while(k>0 && j>0){
            if(M[k][j]==M[k-1][j]){
                k--;
                cout << "top ";
            }
            else{
                if(last==-1){
                    last=j;
                }
                j--;
                cout << "left ";
            }
        }
        cout <<"\n";
        first=j;
        if(first==-1 || last==-1)
            cout << "Route " << i+1 << " has no nice parts\n";
        else
            cout << "The nicest part of route "<< i+1 <<" is between stops "<< first+1 <<" and "<< last+1 << "\n";
    }
    return 0;
}
