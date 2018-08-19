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
    int N,nb,tmp;
    scanf("%d",&N);
    int T[10];
    for(int i=0;i<N;i++){
        scanf("%d",&nb);
        for(int j=0;j<10;j++){
            scanf("%d",&T[j]);
        }
        sort(T,T+10);
        printf("%d %d\n",nb,T[7]);
    }
    return 0;
}
