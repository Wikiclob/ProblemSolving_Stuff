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
    int N,A,B,C;
    float res;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d%d",&A,&B,&C);
        res=A+B+C;
        res*=3;
        res--;
        res/=4;
        cout << "Case " << i << ":\n" << res << "\n";
    }
    return 0;
}
