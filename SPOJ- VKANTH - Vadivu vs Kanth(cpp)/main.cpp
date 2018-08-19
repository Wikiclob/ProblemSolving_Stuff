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
    int N,j;
    ll A=0;
    string input;
    scanf("%d",&N);
    char c,prev,tmp='9',tmp_p='9';
    vector<int> V;
    int jump=0;
    for(int i=0;i<N;i++){
        fflush(stdin);
        V.clear();
        A=0;
        jump=0;
        cin >> input;
        for(int j=input.length()-1;j>0;j--){
            V.push_back(input[j]-input[j-1]);
        }
        if(input[0]=='1')
            V.push_back(1);
        else
            V.push_back(0);
        for(int j=0;j<V.size();j++){
            if(V[j]==1)
                A+=pow(2,j);
        }
        cout << A << "\n";
    }
    return 0;
}
