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
    int N,nb;
    //char c;
    int countD;
    scanf("%d",&N);
    //fflush(stdin);
    for(int i=0;i<N;i++){
        countD=0;
        scanf("%d",&nb);
        do{
            countD++;
            nb/=10;
        }
        while(nb!=0);
        printf("%d\n",countD);
    }
    return 0;
}
