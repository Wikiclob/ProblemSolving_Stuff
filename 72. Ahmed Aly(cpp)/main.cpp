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
    int N;
    char op,tmp;
    int x,y,res;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d %c %d %c %d",&x,&op,&y,&tmp,&res);
        switch(op){
            case '+': printf("Case %d: %s\n",i,(x+y==res)?"YES":"NO");break;
            case '-': printf("Case %d: %s\n",i,(x-y==res)?"YES":"NO");break;
        }
    }
    return 0;
}
